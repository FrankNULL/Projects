#include "phase1.h"

// You are free to use your own logic. The following points are just for getting started
/* 	Data Partitioning Phase - Only Master process involved
	1) 	Create 'MapperInput' folder
	2) 	Traverse the 'Sample' folder hierarchy and insert the text file paths
		to Mapper_i.txt in a load balanced manner
	3) 	Ensure to keep track of the number of text files for empty folder condition

*/
char *file_path[50];
int file_count=0;
FILE *fp[32];

int get_filepath(char* path){
  DIR *dr=opendir(path);
  struct dirent* de;
  struct stat buf;
  //traverse directories
  while((de=readdir(dr)) != NULL){
    // if it is a directory, call recursive function
    if(de->d_type==DT_DIR && strncmp(de->d_name,".",1) && strncmp(de->d_name,"..",2)){
        char* new_dir=malloc(sizeof(char)*256);
        new_dir[0]='\0';
        strcat(new_dir,path);
        strcat(new_dir,"/");
        strcat(new_dir,de->d_name);
        get_filepath(new_dir);
    }
    // if it is a file, store path
    else if (de->d_type==DT_REG){
      char* new_file=malloc(sizeof(char)*256);
      new_file[0]='\0';
      strcat(new_file,path);
      strcat(new_file,"/");
      strcat(new_file,de->d_name);
      lstat(new_file,&buf);
      if(!(S_ISLNK(buf.st_mode))){
        file_path[file_count]=new_file;
        file_count++;
      }
    }
  }
return 0;
}


int exe_phase1(char *path,int mapper_count){
  if (get_filepath(path)!=0){
    printf("Unable to get the file path\n");
    exit(1);
  }
  if(file_count==0){
    printf("The %s folder is empty\n",path);
    exit(1);
  }
  if (mkdir("MapperInput",0777)==-1){
    printf("Failed to create directory\n");
    exit(1);
  }
  chdir("MapperInput");
  char file_name[20];
  for(int i=0;i<mapper_count;i++){
    sprintf(file_name,"Mapper_%d.txt",i);
    fp[i]=fopen(file_name,"w");
  }
  for(int i=0;i<file_count;i++){
    fprintf(fp[i%mapper_count],"%s\n",file_path[i]);
  }
  for(int i=0;i<mapper_count;i++){
    fclose(fp[i]);
  }
  chdir("..");
  return 0;
}
