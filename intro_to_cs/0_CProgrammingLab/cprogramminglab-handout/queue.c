/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */
//TODO: Create a case for if the program wants to insert or delete a NULL ele, i think this is my NULL pointer dereference issue 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"


/*Queue empty funct
If the head and tail are null then the queue
 initialized and is empty
*/
bool queue_empty(queue_t *q){
  if(q->head == NULL && q->head == q->tail){
    return true;
  } else{
    return false;
  }
}

/*the new function doesnt like when memory is allocated
initialization, so this init function should fix that burden
since inserting at the head or the tail of an empty queue is
effectively the same thing im sending them both to this function
*/
queue_t *init_queue(queue_t *q, char *s){
  list_ele_t *temp_head;
  temp_head = malloc(sizeof(list_ele_t)); //carve out some space for the ele
  if(temp_head == NULL){ //fail space isnt there
    return false;
  }
  char *temp_str = malloc(strlen(s)+1); //carving out space for the string /w null byte
  if(temp_str == NULL){
    free(temp_head);
    return false;
  }
  strcpy(temp_str, s); //be careful bere the buffer is only as large as memory allows
  //since the queue is empty head and tail are the same node
  q->head = temp_head; 
  q->tail = temp_head;
  //size has to be set to 1 here (or q->size++;)
  q->size = 1;
  q->head->value = temp_str;
  //always point the tail to null
  q->tail->next = NULL;
  return q;
}

/*
  Create empty queue. By empty i mean it contains no heap memory for elements
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    //if memory is full return a NULL queue.
    if(q == NULL){
      return NULL;
    } else{
      //set the elements to NULL but dont allocate space yet, the grader doesnt like that
      q->head = NULL;
      q->tail = NULL;
      q->size = 0; //size needs to be set here or size will equal max int size
      return q;
    }
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    if(q==NULL){ //if its null theres nothing to free
      return;
    }
    if(queue_empty(q)){ //if its empty just free the queue struct
      free(q);
      return;
    }
    list_ele_t *current,*prev; //itterator variables
    current = q->head; // used to itterate through the list startning at head
    prev = NULL; //used to free
    while( current != NULL ) {
      prev = current; 
      current = current->next; //after prev is set to current move to the next before you change anything
      free(prev->value); //free up the space used by the string
      free(prev); //free up the space used by the ele
    }
    free(q); //free the queue struct when youre done
    return;
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if(q == NULL){
      return false; //you cant insert an ele into a null queue
    }
    if(queue_empty(q)){
      q = init_queue(q, s); //if its empty, create a queue and insert the one ele
      if(q){
        return true; //if this returns anything then it worked and you have a queu with 1 ele
      }
      else{
        return false; //there was a memory allocation error either in the string or ele
      }
    }
    newh = malloc(sizeof(list_ele_t)); //create memory for new ele
    if(newh==NULL){ //Make sure memory allocation didnt fail
      return false;
    }
    else{
      char *temp_str = malloc(strlen(s)+1); //create memory space to store the string
      if(temp_str==NULL){ //make sure the memory allocation didnt faul
        free(newh);
        return false;
      }else{
        strcpy(temp_str, s);
        newh->value = temp_str; //fill the new header
        newh->next = q->head;
        q->head = newh; //fix header
        q->size++; //increment queue size
        return true;
      }
    }
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newt;   //Create the new tail
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if(q == NULL){ //Make sure the queue isnt NULL
      return false;
    }
    if(queue_empty(q)){
      q = init_queue(q, s); //does the exact same thing that the insert head does on a empty q
      if(q){
        return true;
      }
      else{
        return false;
      }
    }
    newt = malloc(sizeof(list_ele_t)); //need space for new tail
    if(newt == NULL){   //Make sure memory allocation didt fail
      return false;
    }else{
      char *temp_str = malloc(strlen(s)+1); //allocate space for string, regardless of size+null
      if(temp_str==NULL){   //Make sure memory allocation didt fail
        free(newt);
        return false;
      }else{
        strcpy(temp_str, s);
        q->tail->next = newt;  //point the current tail to the temp
        newt->value = temp_str; //input values in the current temp tail
        newt->next = NULL; //make sure temp points to null
        q->tail = newt; //promote temp to tail
        q->size++; // increment queue size
        return true;     
      }
    }
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/

bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if(q == NULL || queue_empty(q)){
      return false;
    }
    list_ele_t *oldhead;
    oldhead = q->head;
    q->head = q->head->next;
    if(sp!=NULL){
      strncpy(sp, oldhead->value, bufsize-1);
      //This piece was messimg me up the most, didnt know i had to NULL terminate myself
      sp[bufsize - 1] = '\0';  
    }
    if(oldhead->value != NULL){
      free(oldhead->value);
    }
    free(oldhead);
    q->size--;
    return true;
}


/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    /*since q->size is set to zero during q_init i techiclly only have to put
    q==NULL for the if statement but adding empty q gives me peace of mind
    */ 
    if(q == NULL || queue_empty((q))){
      return 0;
    }else{ 
      return q->size; //size should be incremented and decremented any time q is changed
    }
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    //sine the queue will process lots of eles, recursion isnt practical
    if(q==NULL || queue_empty(q) || q->size == 1){
      return;
    }
    list_ele_t *prev,*curr,*next; //reference vars for itteration
    curr = q-> head; //so that im not changing the actual head (yet)
    q->tail = curr; //this was the last piece, i reversed and didnt restore the tail.
    prev = NULL;
    while(curr != NULL){ //until i hit the end of the list
      next = curr->next; //i need to know where the actual next is before i change it
      curr->next = prev; //reverse reverse, on initial run this will point to null of course
      prev = curr; //used to point for my next reverse
      curr = next; //move along
    }
    q->head = prev; //now we actually change the head, otherwise the q will only have one ele
}