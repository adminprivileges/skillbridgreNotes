#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include "gfserver.h"
#define BUFSIZE 4096
/* 
 * Modify this file to implement the interface specified in
 * gfserver.h.
 */
/*
gfserver.h declare two structs that they fail to define (because thats my job)
these are the definitions.
gfserver_t = server info
gfcontext_t = client info
*/
struct gfserver_t{
    char port_str[5]; //need a port, but getaddrinfo doesnt like ints
    int max_pending; //need for set_maxpending
    int sockfd; //socket for the server
    ssize_t (*handler)(gfcontext_t *, char *, void *); //sets the handler for file I/O
    void *handle_arg; //handler argument
};

struct gfcontext_t{
    int sockfd; //socket for the client
    gfserver_t *gfs;
};

void gfs_abort(gfcontext_t *ctx){
    if(ctx == NULL){
        printf("CTX is NULL(gfs_abort)");
    }
    printf("Throwing an error to client");
    gfs_sendheader(ctx, GF_ERROR, 0);
    printf("Closing Connection");
    close(ctx->sockfd);

}
void unix_error(char *err_msg){
    printf("An Error has occured: %s\n", err_msg);
    exit(1);
}

/*
Here im going to create the server, which will take up a slice of memory for the data
TODO: Make sure you free memory for things like failures.
*/
gfserver_t* gfserver_create(){
    gfserver_t *gf;
    if (( gf = malloc(sizeof(gfserver_t))) == NULL){
        unix_error("Error Reserving space for a gfserver_t object.");
        exit(1);
    }else{
        printf("Memory Reserved for a gfserver_t object!\n");
    }
    //memset(&gf, 0, sizeof(gfserver_t));
    return gf;
}


ssize_t gfs_send(gfcontext_t *ctx, void *data, size_t len){
    if(ctx == NULL){
        unix_error("CTX is NULL (gfs_send))");
    }else if(data == NULL){
        unix_error("Data is NULL (gfs_send))");
    }
    ssize_t bytes_sent = 0, chunk_sent;
    char *new_data = data;
    while(bytes_sent < len){
        if((chunk_sent = send(ctx->sockfd, &new_data[bytes_sent], len - bytes_sent, 0)) < 0){
            printf("Error sending content (gfs_send)");
            break;
        }
        bytes_sent += chunk_sent;
        printf("Request Size is %zd, total sent is %zd, chunks sent this request is %zd\n", len, bytes_sent, chunk_sent);
    }
    return bytes_sent;
}

ssize_t gfs_sendheader(gfcontext_t *ctx, gfstatus_t status, size_t file_len){
    if(ctx == NULL){
        unix_error("CTX is NULL (gfs_sendheader)");
    }
    char header[BUFSIZE];
    if (status == GF_OK) {
        sprintf(header, "GETFILE OK %zd\r\n\r\n", file_len);
    } else if (status == GF_FILE_NOT_FOUND) {
        sprintf(header, "GETFILE FILE_NOT_FOUND\r\n\r\n");
    } else {
        sprintf(header, "GETFILE ERROR\r\n\r\n");
    }
    printf("Sending header %s", header);
    ssize_t request_size = strlen(header);
    ssize_t request_sent = 0;

    while(request_sent < request_size){
        ssize_t chunk_sent = send(ctx->sockfd, &header[request_sent], strlen(header), 0);
        if(chunk_sent < 0){
            printf("Error Sening Message");
            return -1;
        }
        request_sent += chunk_sent;
        printf("Request Size is %zd, total sent is %zd, chunks sent this request is %zd\n", request_size, request_sent, chunk_sent);
        break;
    }
    printf("Header Sent!\n");
    return request_sent;

}

void gfserver_serve(gfserver_t *gfs){
    struct addrinfo hints, *addr_res, *addr_res_p;
    memset(&hints, 0 ,sizeof(struct addrinfo)); //Always clear hints
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG; /* ...on any IP addr */
    hints.ai_flags |= AI_NUMERICSERV; /* ...using port no. */
    if(getaddrinfo(NULL, gfs->port_str, &hints, &addr_res) < 0){
        unix_error("Error Resolving Name");
    } else{
        for(addr_res_p = addr_res; addr_res_p; addr_res_p = addr_res_p->ai_next){
            if((gfs->sockfd = socket(addr_res_p->ai_family, addr_res_p->ai_socktype, addr_res_p->ai_protocol)) < 0){
                printf("Creating socket failed, trying another\n");
                continue;
            }
            printf("Socket Created!\n");
            if(setsockopt(gfs->sockfd, SOL_SOCKET, SO_REUSEADDR, (const void*) 1, sizeof(int)) < 0){
                printf("Setting Sock Opt Failed, trying another\n");
            }else{
                printf("Socket Options Set!\n");
            }
            if(bind(gfs->sockfd, addr_res_p->ai_addr, addr_res_p->ai_addrlen) <0){
                close(gfs->sockfd);
                printf("Binding Socket Failed, trying another\n");
            } else{
                printf("Socket Binded Sucessfully!\n");
                break;
            }
        }
        freeaddrinfo(addr_res);
        if(!addr_res_p){
            unix_error("No valid address");
        }
        if(listen(gfs->sockfd, gfs->max_pending) < 0){
            unix_error("Error Listening on Socket");
        }else{
            printf("Listening on Socket!\n");
        }
        //Accept Loop
        while(1){
            socklen_t client_len = sizeof(struct sockaddr_storage);
            gfcontext_t *ctx;
            if((ctx = malloc(sizeof(gfcontext_t))) == NULL){
                unix_error("Allocating Space for GF Context Object");
            }
            //memset(&ctx, 0, sizeof(gfcontext_t));
            struct sockaddr_storage clientaddr;
            if((ctx->sockfd = accept(gfs->sockfd, (struct sockaddr  *)&clientaddr, &client_len)) < 0){
                printf("Error Accepting connection\n");
            }else{
                printf("Accepted Connection\n!");
            }
            char recvl[BUFSIZE];
            char header[BUFSIZE];
            ssize_t request_size, bytes_recv=0;
            printf("Reading Header From Socket\n");
            while(bytes_recv < sizeof(header)){
                request_size = recv(ctx->sockfd, recvl, sizeof(BUFSIZE), 0);
                if(request_size < 0){
                    printf("Error Recieving Message\n");
                    exit(1);
                } else if(request_size == 0){
                    printf("No More Bytes Recieved\n");
                    break;
                }
                if ((request_size + bytes_recv) <= sizeof(header)) {
                    memcpy(header+bytes_recv, recvl, sizeof(request_size));
                    bytes_recv += request_size;
                    printf("Request Size is %zd, total sent is %zd\n", request_size, bytes_recv);
                } else{
                    memcpy(header+bytes_recv, recvl, sizeof(header) - bytes_recv);
                    bytes_recv = sizeof(header);
                    printf("Header Limit Reached");
                }
            }
            //need to make handling more robust for errors. 
            printf("Header is %s\n", header);
            char  scheme[32], method[10], filepath[256];
            if (sscanf(header, "%s %s %s \r\n\r\n", scheme, method, filepath) != EOF){
                printf("Sheme is %s, Method is %s, filepah is %s", scheme, method, filepath);
                if(scheme != NULL && method != NULL && filepath!= NULL){
                    printf("request is valid, calling handler\n");
                    gfs->handler(ctx, filepath, gfs->handle_arg);
                } else{
                    printf("Invalid Header");
                    gfs_sendheader(ctx, GF_ERROR, 0);

                }
            }else{
                printf("Error parsing header\n");
                gfs_sendheader(ctx, GF_ERROR, 0);
            }
            if (close(ctx->sockfd) < 0){
                unix_error("Closing socket!");
            }
            free(ctx);
             }
        }
    
    
    }

void gfserver_set_handlerarg(gfserver_t *gfs, void* arg){
    if (gfs == NULL){
        unix_error("GF Object is NULL (gfserver_set_handlerarg)!");
    }
    else{
        gfs->handle_arg = arg;
        printf("Handler Arg Set Sucessfully!\n");
    }
}

void gfserver_set_handler(gfserver_t *gfs, ssize_t (*handler)(gfcontext_t *, char *, void*)){
    if (gfs == NULL){
        unix_error("GF Object is NULL (gfserver_set_handler)!");
    } else if (handler == NULL){
        unix_error("Handler is NULL (gfserver_set_handler)!");
    } else{
        gfs->handler = handler; //set the handler here
        printf("Handler Set Sucessfully!\n");
    }
}

void gfserver_set_maxpending(gfserver_t *gfs, int max_npending){
    //Before i set the var i need to make sure the gf object wont raise a null error 
    if (gfs == NULL){
        unix_error("GF Object is NULL (gfserver_set_maxpending)!");
    }else{
    gfs->max_pending = max_npending;
    printf("Max Pending Set Sucessfully\n!");
    }
}

void gfserver_set_port(gfserver_t *gfs, unsigned short port){
    //Make sute the gf struct isnt null before i add a parameter to prevent null error.
    if (gfs == NULL){
        unix_error("GF Object is NULL! (gfserver_set_port)");
    } else{
    sprintf(gfs->port_str, "%d", port); //getaddrinfo doesnt like ints so i made it a str
    printf("Port Set Sucessfully\n!");
    }
}


