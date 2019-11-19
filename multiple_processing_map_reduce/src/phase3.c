#include "phase3.h"
// You are free to use your own logic. The following points are just for getting started
/* Reduce Function
	1)	The reducer receives the list from 'm' mappers via pipes
	2)	Ensure proper closing of pipe ends
	3) 	Combine the lists to create a single list
	4) 	Write the list to "ReducerResult.txt" in the current folder
*/

int exe_phase3(int mapper_count,int fds[][2]){
  pid_t pid=fork();
  if(pid>0){
    wait(NULL);
  }
  else{
    for(int i=0;i<mapper_count;i++){
      close(fds[i][1]);
      read(fds[i][0],temp,sizeof(temp));//read arrays from pipes
      for(int j=0;j<26;j++){
        letter[j]=temp[j]+letter[j];
      }
    }
    FILE *fp;
    fp=fopen("ReducerResult.txt","w");
    if(fp==NULL){
      printf("unable to create ReducerResult.txt\n");
    }
    for(int i=0;i<26;i++){
      fprintf(fp,"%c %d\n",'A'+i,letter[i]);//output this array to ReducerResult.txt 
    }
    exit(0);
  }
  return 0;
}
