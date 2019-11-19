
/*
header.h, header for all source files
it will:
- structure definition
- global variable, lock declaration (extern)
- function declarations
*/

#ifndef _HEADER_H_
#define _HEADER_H_
#include <sys/types.h>
#include<pthread.h>

struct Res{//result histogram shared by consumers
  int letter[26];
  pthread_mutex_t* mutex;
};

struct QNode {//queue node
    char* line;
    struct QNode* next;
    int line_num;
};
struct Queue {//shared queue where consumers get data from the head
    struct QNode *front, *rear;//producer put data in the tail
    int size;//restricted by the bound if -b flag exists
};
struct condBuffer {//shared information buffer used by consumers and producer
    struct Queue* q;//shared queue
    int EOF_flag;//end of file flag
    int pflag;//print log flag
    int bound;//bound if -b enabled
    FILE *log;//pointer to the log file
    pthread_cond_t* cond;
    pthread_cond_t* cond2;
    pthread_mutex_t* mutex;
};
struct producer_args {//arguments give to the producer
  struct condBuffer* buffer;//shared buffer
  char* f;//input file name
};

struct consumer_args{//arguments give to consumers
  struct condBuffer* buffer;//shared buffer
  struct Res* result;//shared result between consumers
  int consumer_id;//consumer id
};
void *producer(void* args);
void *consumer(void* args);
void enQueue(struct Queue* q,struct QNode* new_node);
struct QNode* deQueue(struct Queue* q);
#endif
