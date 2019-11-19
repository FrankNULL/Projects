#ifndef __DFS_QUEUE_H
#define __DFS_QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

//queue
int queue[MAX_TARGETS];
int rear=-1;
int front=0;
//add an element into the end of the queue
void add(int item){
  rear++;
  queue[rear]=item;
}
//decide if it is empty
bool is_empty(){
  return rear<front;
}
//get an element at the begnning of the queue
int get_front(){
    return queue[front];
}

#endif
