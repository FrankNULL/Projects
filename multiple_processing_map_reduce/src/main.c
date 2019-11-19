#include "main.h"

int main(int argc, char *argv[]){

	// argument count check
	if (argc != 3) {
		printf("Wrong number of args, expected 2, given %d\n", argc - 1);
		exit(1);
	}
	//just make a function call to code in phase1.c
	//phase1 - Data Partition Phase
	int mapper_count=atoi(argv[2]);
	exe_phase1(argv[1],mapper_count);
	//create pipes

int fds[32][2];
for(int i=0;i<mapper_count;i++){
	pipe(fds[i]);
}
	//just make a function call to code in phase2.c
	//phase2 - Map Function
exe_phase2(mapper_count,fds);
	//just make a function call to code in phase3.c
	//phase3 - Reduce Function
exe_phase3(mapper_count,fds);
	//phase4
	//wait for all processes to reach this point
exe_phase4();
	//just make a function call to code in phase4.c
	//master process reports the final output

	return 0;

}
