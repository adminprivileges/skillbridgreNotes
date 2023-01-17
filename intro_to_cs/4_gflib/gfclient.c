#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h> 
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>

#include "gfclient.h"
#define BUFSIZE 4096
/*
This struct is to represent the connection from the client to the server as well
as the appropriate variables and functions needed to send/recieve data
char* server - the server name for dns translation
char port_str[5]; - the port needed, geraddrinfo doesnt like ints
int sockfd - The actual file descriptor for the c/s connection
char* path - the linux path of the file, starting at server root
char request[BUFSIZE] - the string representation of the client reequest
void (*headerfunc)(void *, size_t, void *) - header function (provided,dont change)
void *headerarg - sets arguemts for header funct
void (*writefunc)(void *, size_t, void *)- file write function (provided, dont change)
void *writearg - sets arguemts for write funct
size_t bytes_rec - important for the file write comp to file_len
size_t file_len - important for the file write bytes_rec
gfstatus_t status - signifies status
*/
struct gfcrequest_t{
    char* server;
    char port_str[5];
    int sockfd;

    //request
    char *path;
    char request[BUFSIZE];
    //Callback Function
    void (*headerfunc)(void *, size_t, void *);
    void *headerarg;
    void (*writefunc)(void *, size_t, void *);
    void *writearg;
    //data recieved
    size_t bytes_rec;
    size_t file_len;
    gfstatus_t status;

};

/*Just a simple errpr funct so i can get out of bad spots verbosely,
 might delete later
 */
void unix_error(char *err_msg){
    printf("An Error has occured: %s\n", err_msg);
    exit(1);
}


/*
cleans up the memory that i allocate in the heap thoughout the script so far:
gfr
getaddrinfo
*/
void gfc_cleanup(gfcrequest_t *gfr){
    if(gfr == NULL){
        unix_error("GFR is NULL (gfc_cleanup)");
    } else{
        free(gfr);
    }
}

/*
As part of setting up the connection i need to create a socket handler object
instead of crowding the stack im gonna take a slice of heap for the object
*/
gfcrequest_t *gfc_create(){
    gfcrequest_t *gf;
    if (( gf = malloc(sizeof(gfcrequest_t))) == NULL){ //never call malloc without a way out
        unix_error("Error Reserving space for a gfcrequest_t object.");
        exit(1);
    }else{
        printf("Memory Reserved for a gfcrequest_t object!\n");
    }
    //memset(gf, 0, sizeof(gfcrequest_t)); // kept leading to a segfault, need to figure why
    return gf;
}

/*
Just pulls butes recieved from the object, asserts that its not null first to
prevent a null pointer dereference 

*/
size_t gfc_get_bytesreceived(gfcrequest_t *gfr){
    if(gfr == NULL){
        unix_error("GFR Is NULL (gfc_get_bytesreceived)");
    }
    return gfr->bytes_rec;
}

/*
Just pulls file length from the object, asserts that its not null first to
prevent a null pointer dereference 

*/
size_t gfc_get_filelen(gfcrequest_t *gfr){
    if(gfr == NULL){
        unix_error("GFR Is NULL (gfc_get_filelen)");
    }
    return gfr->file_len;
}


/*
Just pulls the status from the object, asserts that its not null first to
prevent a null pointer dereference 

*/

gfstatus_t gfc_get_status(gfcrequest_t *gfr){
    if(gfr == NULL){
        unix_error("GFR Is NULL (gfc_get_status)");
    }
    return gfr->status;
}

/*
This function initializes all global variables or stucts that i need for this script
*/
void gfc_global_init(){

}

/*
frees up all the memory that i used for the init globals
*/
void gfc_global_cleanup(gfcrequest_t *gfr){
}

/*
Does all the heavy lifting for the script, this actually performs the connection to he server
requesting the file as well as the recieving of data
*/
int gfc_perform(gfcrequest_t *gfr){
    //struct sockaddr_in server;
    //This structure needs to be zeroes out or youre gonna have a bad time
    struct addrinfo hints, *addr_res, *addr_res_p; 
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM; /* Open a connection */
    hints.ai_flags = AI_NUMERICSERV; /* ...using numeric port arg. */
    hints.ai_flags |= AI_ADDRCONFIG; /* Recommended for connections */
    /* 
    does a DNS resolution on the provided hostname and then returns a linked list of 
    responses, we then itterate through the linked list to try each possible answer
    */ 
    if ((getaddrinfo(gfr->server, gfr->port_str, &hints, &addr_res)) < 0){
        printf("Error Resolving Name");
        exit(1);
    }else{
        /*
        This loop itterates through the list and grabs the IP address from each element to attempt
        a connection
        */
        for (addr_res_p = addr_res; addr_res_p; addr_res_p = addr_res_p->ai_next){
            if ((gfr->sockfd = socket(addr_res_p->ai_family, addr_res_p->ai_socktype, addr_res_p->ai_protocol)) < 0){
                continue; //if the socket is created get out of this loop and try a connection
            }
            printf("Socket Creates Successfully!\n");
            //here we try to actually connect with the returned socket
            if (connect(gfr->sockfd, addr_res_p->ai_addr, addr_res_p->ai_addrlen) != 1){
                printf("Connect Sucessful!\n");
                break;
            }
            printf("Connection Failed\n"); //youll only get here if unable to make connection
            close(gfr->sockfd);//make sure to close the socket to ensure you dont leave loose connections
            continue;
        }
        freeaddrinfo(addr_res);
        if(!addr_res_p){
            unix_error("No valid address");
        }
        //This is where the actual request starts
        char *scheme = "GETFILE";
        char *method = "GET";
        sprintf(gfr->request, "%s %s %s \r\n\r\n", scheme, method, gfr->path);
        //sprintf(gfr->request, "GETFILE GET /workload.txt \r\n\r\n");
        ssize_t request_size = strlen(gfr->request);
        ssize_t request_sent = 0;
        //this will itterate through the request header until its fully sent and print the progress
        while(request_sent < request_size){
            ssize_t chunk_sent = send(gfr->sockfd, gfr->request, strlen(gfr->request)+1, 0);
            if(chunk_sent < 0){
                printf("Error Sening Message");
                break;
            }
            request_sent += chunk_sent;
            printf("Request Size is %zd, total sent is %zd, chunks sent this request is %zd\n", request_size, request_sent, chunk_sent);
            break;
        }
        /*
        I couldnt find a better way to do this so i shutdown the socket, which just allows a response from
        the server then quits
        */
        shutdown(gfr->sockfd, SHUT_WR);
        //Time to do something with the header
        char header[BUFSIZE];
        ssize_t response_size;
        //first i have to listen for a header and make sure i even got something from the server
        if((response_size = recv(gfr->sockfd, header, sizeof(header), 0)) <= 0){
            if(response_size == 0){
                printf("Invalid response");
                gfr->status = GF_INVALID;
                return -1;
            }
            printf("Recieving server reponse failed");
            gfr->status = GF_ERROR;
            return -1;
        }
        //after youre sure you got something, print it out
        printf("Header is %s\n", header);
        char  res_scheme[32], status[32];
        ssize_t file_len = 0;
        int file_pos = 0;
        //This breaks the response into the variables i need if its a valid format
        if (sscanf(header, "%s %s %zd\r\n\r\n%n", res_scheme, status, &file_len, &file_pos) != EOF){
            printf("Sheme is %s, Status is %s, file_len is %zd, file_pos is %d\n", res_scheme, status, file_len, file_pos);
            if(res_scheme != NULL && status != NULL){
                printf("Scheme: %s Status %s\n", res_scheme, status);
                if(strcmp(status, "OK") == 0){
                    gfr->status = GF_OK;
                }else if(strcmp(status, "FILE_NOT_FOUND") == 0){
                    gfr->status = GF_FILE_NOT_FOUND;
                    return 0;
                }else if(strcmp(status, "ERROR") == 0){
                    gfr->status = GF_ERROR;
                    return 0; 
                }
            }else{
                gfr->status = GF_INVALID;
                return -1;                
            }
        }else{
            printf("Error parsing header\n");
            gfr->status = GF_INVALID;
            return -1;
        }
        gfr->file_len = file_len;
        if(gfr->status == GF_OK && file_pos < response_size){
            printf("Writing");
            size_t bytes_written = response_size - file_pos;
            gfr->writefunc(header + file_pos, bytes_written, gfr->writearg);
            gfr->bytes_rec += bytes_written;
        }
        printf("Header is done, parsing file content...\n");
        //header is good, now lets write the content
        char content[BUFSIZE];
        while(gfr->status == GF_OK && gfr->bytes_rec < gfr->file_len){
            size_t cont_size;
            printf("In print content loop\n");
            if((cont_size = recv(gfr->sockfd, content, sizeof(BUFSIZE), 0)) <= 0){
                printf("File not transfered sucessfully\n");
                return -1;
            }else{
                gfr->writefunc(&content, cont_size, gfr->writearg);
                gfr->bytes_rec += cont_size;
            }
            printf("%zd bytes recieved, %zd bytes left, %zd bytes sent this chunk", gfr->bytes_rec, gfr->file_len, cont_size);
        }
        printf("File Transfered sucessfully!\n");
        
    }
    close(gfr->sockfd);
    return 0;
    
}

void gfc_set_headerarg(gfcrequest_t *gfr, void *headerarg){
    if (gfr == NULL){
        unix_error("GF Object is NULL (gfc_set_headerarg)!");
    }
    else{
        gfr->headerarg = headerarg;
        printf("headerarg Set Sucessfully!\n");
    } 
}

void gfc_set_headerfunc(gfcrequest_t *gfr, void (*headerfunc)(void*, size_t, void *)){
    if (gfr == NULL){
        unix_error("GF Object is NULL (gfc_set_headerfunc)!");
    }else if(headerfunc == NULL){
        unix_error("Writefunc is NULL (gfc_set_headerfunc)!");
    }
    else{
        gfr->headerfunc = headerfunc;
        
        printf("headerfunc Set Sucessfully!\n");
    } 
}

void gfc_set_path(gfcrequest_t *gfr, char* path){
    if (gfr == NULL){
        unix_error("GF Object is NULL (gfc_set_path)!");
    }
    else{
        gfr->path = path;
        printf("Path Set Sucessfully!\n");
    } 
}

void gfc_set_port(gfcrequest_t *gfr, unsigned short port){
    if (gfr == NULL){
        unix_error("GF Object is NULL (gfc_set_port)!");
    }
    else{
        sprintf(gfr->port_str, "%d", port); //getaddrinfo doesnt like ints so i made it a str
        printf("Port Set Sucessfully!\n");
    }  

}

void gfc_set_server(gfcrequest_t *gfr, char* server){
    if (gfr == NULL){
        unix_error("GF Object is NULL (gfc_set_server)!");
    }
    else{
        gfr->server = server;
        
        printf("Server Set Sucessfully!\n");
    }    
}

void gfc_set_writearg(gfcrequest_t *gfr, void *writearg){
    if (gfr == NULL){
        unix_error("GF Object is NULL (gfcrequest_t)!");
    }
    else{
        gfr->writearg = writearg;
        
        printf("writearg Set Sucessfully!\n");
    }   
}

void gfc_set_writefunc(gfcrequest_t *gfr, void (*writefunc)(void*, size_t, void *)){
    if (gfr == NULL){
        unix_error("GF Object is NULL (gfc_set_writefunc)!");
    }else if(writefunc == NULL){
        unix_error("Writefunc is NULL (gfc_set_writefunc)!");
    }
    else{
        gfr->writefunc = writefunc;
        
        printf("writefunc Set Sucessfully!\n");
    }   
  
}

char* gfc_strstatus(gfstatus_t status){
    if (status == GF_OK) {
        return (char *) "OK";
    } else if (status == GF_FILE_NOT_FOUND) {
        return (char *) "FILE_NOT_FOUND";
    } else if (status == GF_INVALID){
        return (char *) "INVALID";
    }
    else {
        return (char *) "ERROR";
    }
}

