#ifndef __GRAPH_H
#define __GRAPH_H

#define LINE_SIZE 128
#define MAX_LINES 128
#define MAX_DEP 8
//Account for extra credit
#define MAX_RECIPES_PT 8
#define MAX_TARGETS 128
#define MAX_PARM 32

typedef struct target_block
{
	char *name;
	char *depend[MAX_DEP];
	char *recipe[MAX_RECIPES_PT];
	int dep_count;
	int recipe_count;
	int visited; // 0 is unvisted 1 is visited
} target;

//target array

target *targets[MAX_TARGETS];
int targetCount=0;
//adjacency matrix
int adjMatrix[MAX_TARGETS][MAX_TARGETS]={0};

// lines for reading
char lines[MAX_LINES][LINE_SIZE];

//add edge to edge array
void addEdge(int start, int end);

//helper funtion for perform_TopoSort
void topoSort(int u);
//topological sorting
//t_index is the index for given target, default value 0 for the first target
//exe_flag 1 for execution, 0 for not execution
void perform_TopoSort(int t_index, int exe_flag);
//add targets index into the adjacent matrix
void add_target_to_graph();

#endif
