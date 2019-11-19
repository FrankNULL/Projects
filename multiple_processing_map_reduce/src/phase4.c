#include "phase4.h"

// You are free to use your own logic. The following points are just for getting started
/* Final Result
	1)	The master process reads the "ReducerResult.txt"
	2) 	Print the contents to standard output which is redirected to "FinalResult.txt"
			i.e., on using printf, the statement should be written to "FinalResult.txt"
*/

int exe_phase4(){
  FILE *fp;
  char letter[20];
  fp=fopen("ReducerResult.txt","r");
  int file_desc = open("FinalResult.txt", O_WRONLY | O_APPEND| O_CREAT,S_IRWXU | S_IRWXG);
  if(dup2(file_desc,STDOUT_FILENO)==-1){
    printf("failed to redirect standard output");
  }
  while(fgets(letter,20,fp)!=NULL){
      printf("%s",letter);
 }
  return 0;
}
