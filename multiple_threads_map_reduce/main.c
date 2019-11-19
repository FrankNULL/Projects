

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
// pthread.h included in header.h
int main(int argc, char *argv[]){
  int consumer_count=atoi(argv[1]);
  pthread_t cond_consumer[consumer_count];
  struct consumer_args* ca[consumer_count];
  pthread_t cond_producer;
  struct Res* rh=(struct Res*) malloc(sizeof(struct Res));
  struct condBuffer* cq=(struct condBuffer*) malloc(sizeof(struct condBuffer));
  struct producer_args* pa=(struct producer_args*) malloc(sizeof(struct producer_args));
  cq->pflag=0;//-p option
  cq->bound=-1;//-b option
  //check the input arguments
  if(argc<3 || argc>5){
    printf("Wrong number of args\n");
    exit(1);
  }
  else if (argc==4){
    if(!strncmp(argv[3],"-p",2)){
      cq->pflag=1;
    }
    else{
      printf("argument mismatch\n");
    }
  }
  else if (argc==5){
    cq->cond2 = (pthread_cond_t*) malloc(sizeof(pthread_cond_t));
    pthread_cond_init(cq->cond2, NULL);
    if(!strncmp(argv[3],"-bp",3)){
      cq->pflag=1;
      cq->bound=atoi(argv[4]);
    }
    else if(!strncmp(argv[3],"-b",2)){
      cq->bound=atoi(argv[4]);
    }
    else {
      printf("argument mismatch\n");
    }
  }
  //create log file
  if(cq->pflag==1){
    cq->log=fopen("log.txt","w");
    if(cq->log==NULL){
      printf("unable to create log.txt\n");
    }
  }
  //initialization
  cq->q=(struct Queue*) malloc(sizeof(struct Queue));
  cq->q->front=NULL;
  cq->q->rear=NULL;
  cq->q->size=0;
  cq->EOF_flag=0;
  cq->cond = (pthread_cond_t*) malloc(sizeof(pthread_cond_t));
  rh->mutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
  cq->mutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
  pa->buffer=cq;
  pa->f=argv[2];
  pthread_cond_init(cq->cond, NULL);
  pthread_mutex_init(cq->mutex, NULL);
  pthread_mutex_init(rh->mutex, NULL);
  //create consumers and producer threads
  pthread_create(&cond_producer,NULL,producer,(void*) pa);
  for(int i=0;i<consumer_count;i++){
    ca[i]=(struct consumer_args*) malloc(sizeof(struct consumer_args));
    ca[i]->buffer=cq;//shared buffer
    ca[i]->result=rh;//shared result
    ca[i]->consumer_id=i;//consumer id
    pthread_create(&cond_consumer[i],NULL,consumer,(void*) ca[i]);
  }
  //join all the threads
  pthread_join(cond_producer, NULL);
	for (int i=0;i<consumer_count;i++){
    pthread_join(cond_consumer[i], NULL);
  }
  //print result into file result.txt
  FILE *fp;
  fp=fopen("result.txt","w");
  if(fp==NULL){
    printf("unable to create result.txt\n");
  }
  for(int i=0;i<26;i++){
    fprintf(fp,"%c: %d\n",'a'+i,rh->letter[i]);
  }

  return 0;
}
