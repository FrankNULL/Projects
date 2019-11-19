// Add Guard to header file
// Function prototype for
//			reduce function that will receive list from all the Mappers to create a single list
//			the single list is then written to ReducerResult.txt
#ifndef PHASE3_H
#define PHASE3_H
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>


int letter[26];
int temp[26];

int exe_phase3(int mapper_count,int fds[][2]);
#endif
