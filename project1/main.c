#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/wait.h>

#include "graph.h"
#include "queue.h"
#include "util.c"

//Parse the input makefile to determine targets, dependencies, and recipes
int process_file(char *fname)
	{
		FILE *fp = fopen(fname, "r");
		char line[LINE_SIZE];
		int i = 0;

		if (!fp)
			{
				printf("Failed to open the file: %s \n", fname);
				exit(EXIT_FAILURE);
			}

	//Read the contents and store in lines, skip blank lines
		while (fgets(line, LINE_SIZE, fp)){
			if(strchr(line,':')!=NULL || strchr(line,'\t')!=NULL)
				strncpy(lines[i++], line, strlen(line));
		}
	fclose(fp);
	return 0;
	}

//Validate the input arguments, bullet proof the program
int main(int argc, char *argv[])
	{
  	if(argc>3)
			{
				printf("too many arguments\n");
				exit(EXIT_FAILURE);
			}
			//$./mymake Makefile
		if (argc == 2)
			{
				process_file(argv[1]);//read file
				parse(0);//split targets,dep,recipes, 0 flag means do not print
				add_target_to_graph();//add target into adjacent matrix
				perform_TopoSort(0,1);//0 flag for the first target, 1 flag for execution
			}

		if (argc == 3)
			{
			//$./mymake Makefile target
		if (strncmp(argv[1], "-p", 2) &&strncmp(argv[1], "-r", 2))
			{
				process_file(argv[1]);//read file
				parse(0);//split targets,dep,recipes, 0 flag means do not print
				int index = find_target(argv[2]);//find the index for given target
				if (index == -1)
					{
						printf("target does not exist\n");
						exit(EXIT_FAILURE);
					}
				add_target_to_graph();//add target into adjacent matrix
				perform_TopoSort(index,1);//perform toposort on the target of index, 1 flag for execution
		}
		else if (!strncmp(argv[1], "-p", 2))
						{
				//$./mymake -p Makefile
							process_file(argv[2]);//read file
							parse(1);//split targets,dep,recipes, 1 flag means print the content
						}

			//$./mymake -r Makefile
		if (!strncmp(argv[1], "-r", 2))
			{
				process_file(argv[2]);//read file
				parse(0);//split targets,dep,recipes, 0 flag: do not print
				add_target_to_graph();//add target into adjacent matrix
				perform_TopoSort(0,0);//the first 0 flag for the first target
			}                       //the second 0 flag means do not execution, only print the recipe
	}
	exit(EXIT_SUCCESS);
	}
