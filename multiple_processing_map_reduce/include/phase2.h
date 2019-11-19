// Add Guard to header file
// Function prototypes for
//			map function that will go through text files in the Mapper_i.txt to get the (letter, wordcount)
#ifndef PHASE2_H
#define PHASE2_H
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

int exe_phase2(int mapper_count,int fds[][2]);

#endif
