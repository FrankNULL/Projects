#include "phase2.h"

// You are free to use your own logic. The following points are just for getting started
/* 	Map Function
	1)	Each mapper selects a Mapper_i.txt to work with
	2)	Creates a list of letter, wordcount from the text files found in the Mapper_i.txt
	3)	Send the list to Reducer via pipes with proper closing of ends
*/

FILE *fps[500];
FILE *fp[32];
char buffer[256];
int letter[26];

int exe_phase2(int mapper_count,int fds[][2]){
  for(int i=0;i<mapper_count;i++){
    pid_t pid=fork();
    if(pid>0){
      wait(NULL);
    }
    else{
      char file_name[40];
      int file_count=0;
      sprintf(file_name,"./MapperInput/Mapper_%d.txt",i);
      fp[i]=fopen(file_name,"r");
      //get path from the mapper_i.txt
      while(fgets(buffer,256,fp[i])!= NULL){
          buffer[strlen(buffer)-1] = '\0';
          fps[file_count] = fopen(buffer,"r");
          if (fps[file_count] == NULL) {
              printf("Could not open file %s\n", buffer);
          }
          file_count++;
      }
      for(int j=0;j<file_count;j++){
        char str[128];
        while(fgets(str,128,fps[j])!= NULL ){
        // Increment count for each character and store in an array
            if (str[0] >= 'a' && str[0] <= 'z'){
                letter[str[0]-'a']++;

            }
            else if (str[0] >='A' && str[0]<='Z'){
                letter[str[0]-'A']++;
            }
        }
      }
      close(fds[i][0]);
      write(fds[i][1],letter,sizeof(letter));
      exit(0);
    }
  }
  return 0;
}
