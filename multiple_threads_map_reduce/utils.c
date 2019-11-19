

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
// pthread.h included in header.h

// implement shared queue, final histogram here..
//enqueue put the node in the tail
void enQueue(struct Queue* q,struct QNode* new_node){
  new_node->next=NULL;
  if(q->rear==NULL){//if the queue is empty
    q->front=new_node;
    q->rear=new_node;
  }
  else{
    q->rear->next=new_node;
    q->rear=new_node;
  }
  q->size=q->size+1;
}

struct QNode* deQueue(struct Queue* q){
  struct QNode* temp;
  if(q->front==NULL){//if the queue is empty
    return NULL;
  }
  temp=q->front;
  q->front=temp->next;
  if(q->front==NULL){//if the queue is empty after dequeue
    q->rear=NULL;
  }
  q->size=q->size-1;
  return temp;
}
