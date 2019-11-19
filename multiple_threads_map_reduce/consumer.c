
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
// pthread.h included in header.h
void *consumer(void* args){
  struct consumer_args* ca=(struct consumer_args*) args;
  struct QNode* node= (struct QNode*) malloc(sizeof(struct QNode));
  if(ca->buffer->pflag==1){
    fprintf(ca->buffer->log,"consumer %d\n",ca->consumer_id);
  }
  while(1){
    pthread_mutex_lock(ca->buffer->mutex);
    while(ca->buffer->q->size==0){
      //if the queue is empty
      if(ca->buffer->EOF_flag==1){
        //if reach the end_of_file,signal the waiting consumers
        //unlock and exit the thread
        pthread_cond_signal(ca->buffer->cond);
        pthread_mutex_unlock(ca->buffer->mutex);
        if(ca->buffer->pflag==1){
          fprintf(ca->buffer->log,"consumer %d: -1\n",ca->consumer_id);
        }
        pthread_exit(NULL);
      }
      //if the queue is empty but the EOF flag is not set
      pthread_cond_wait(ca->buffer->cond,ca->buffer->mutex);
    }
    node=deQueue(ca->buffer->q);
    if(ca->buffer->pflag==1){
        fprintf(ca->buffer->log,"consumer %d: %d\n",ca->consumer_id,node->line_num);
      }
    if(ca->buffer->bound>0){
      //if we set the bound signal the producer
      pthread_cond_signal(ca->buffer->cond2);
    }
    pthread_mutex_unlock(ca->buffer->mutex);
    //word count statistics algorithm
    char *str=node->line;
    int f=1;//set f to 0 if get an alphabetic character
    //set to 1 if get a nonalphabetic character
    int count[26]={};
    for(int i=0;i<strlen(str);i++){
      if(str[i] >= 'a' && str[i] <= 'z'){
        if(f==1){
          count[str[i]-'a']++;
          f=0;
        }
      }
      else if (str[i] >='A' && str[i]<='Z'){
        if(f==1){
          count[str[i]-'A']++;
          f=0;
        }
      }
      else{//nonalphabetic character
        f=1;
      }
    }
    //put count into the shared result histogram
    pthread_mutex_lock(ca->result->mutex);
    for(int i=0;i<26;i++){
      ca->result->letter[i]=ca->result->letter[i]+count[i];
    }
    pthread_mutex_unlock(ca->result->mutex);
  }
  return 0;
}
