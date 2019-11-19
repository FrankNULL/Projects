#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "queue.h"

int makeargv(const char *s, const char *delimiters, char ***argvp)//helper funtion in textbook
{
   int error;
   int i;
   int numtokens;
   const char *snew;
   char *t;

   if ((s == NULL) || (delimiters == NULL) || (argvp == NULL))
   {
      errno = EINVAL;
      return -1;
   }
   *argvp = NULL;
   snew = s + strspn(s, delimiters); /* snew is real start of string */
   if ((t = malloc(strlen(snew) + 1)) == NULL)
      return -1;
   strcpy(t, snew);
   numtokens = 0;
   if (strtok(t, delimiters) != NULL) /* count the number of tokens in s */
      for (numtokens = 1; strtok(NULL, delimiters) != NULL; numtokens++)
         ;

   /* create argument array for ptrs to the tokens */
   if ((*argvp = malloc((numtokens + 1) * sizeof(char *))) == NULL)
   {
      error = errno;
      free(t);
      errno = error;
      return -1;
   }
   /* insert pointers to tokens into the argument array */
   if (numtokens == 0)
      free(t);
   else
   {
      strcpy(t, snew);
      **argvp = strtok(t, delimiters);
      for (i = 1; i < numtokens; i++)
         *((*argvp) + i) = strtok(NULL, delimiters);
   }
   *((*argvp) + numtokens) = NULL; /* put in final NULL pointer */
   return numtokens;
}

void parse(int p_flag)//print plag, 0:do not print, 1:print
{

   int i = 0;
   int j;
   char ***dtokens = malloc(sizeof(char ***));//dep tokens
   char ***rtokens = malloc(sizeof(char ***));//recipe tokens
   int dnumtokens, rnumtokens;//dep number, recipe number
   while (i < MAX_LINES)
   {
   while (strchr(lines[i], ':') == NULL && i < MAX_LINES)//find next target
      i++;
   
   if (i >= MAX_LINES)
   {
      break;
   }
      target *tar = malloc(sizeof(target));//temporary container for the target
      rnumtokens = 0;
      dnumtokens = makeargv(lines[i], ": \n", dtokens);//split target and dep
      i++;
      while (i < MAX_LINES)
      {
         if (lines[i][0] == '\t')
         {
           makeargv(lines[i],"\t,\n",rtokens);
           j=0;
           while(rtokens[0][j]!=NULL){//put recipe into the container
             tar->recipe[rnumtokens]=rtokens[0][j];
             j++;
             rnumtokens++;
           }
            i++;
         }
         else{
            break;
         }
      }
      if(p_flag==1){//always check the flag before print
          printf("target %s has %d dependencies and %d recipes\n", dtokens[0][0], dnumtokens - 1, rnumtokens);
      }
      tar->name = dtokens[0][0];
      tar->dep_count = dnumtokens - 1;
      tar->recipe_count = rnumtokens;

      for (j = 0; j < dnumtokens - 1; j++)
      {
         tar->depend[j] = dtokens[0][j + 1];
         if(p_flag==1){
           printf("dependency %d is %s\n", j, dtokens[0][j + 1]);
         }
      }
      for (j = 0; j < rnumtokens; j++)
      {
         if(p_flag==1){
           printf("recipe %d is %s\n", j, tar->recipe[j]);
         }
      }
      if(p_flag==1){
        printf("\n");
      }
      targets[targetCount] = tar;
      targetCount++;
   }
}

void show_recipes(int index)//print the recipe for target of index
{
   for (int i = 0; i < targets[index]->recipe_count; i++)
   {
      printf("%s\n", targets[index]->recipe[i]);
   }
}

//add edge to the graph
void addEdge(int tar, int dep)
{
   adjMatrix[tar][dep] = 1;
}

void topoSort(int u)
{
   targets[u]->visited = 1; //set as the node v is visited
   for (int v = 0; v < targetCount; v++)
   {
         if (adjMatrix[u][v] == 1)
         { //for allvertices v adjacent to u
            if (targets[v]->visited == 0)
               topoSort(v);
         }

   }
   add(u); //add starting vertex into the queue
}

void perform_TopoSort(int t_index,int exe_flag)//t_index for the index of the given target
{                                              //exe_flag 0:only print, 1:do not print but execute
   for (int i = 0; i < targetCount; i++)
   {
     targets[i]->visited = 0; //initially all nodes are unvisited
   }
  topoSort(t_index);//topological sorting, add target into a queue in order
  if(exe_flag==1)
  {
    while (!is_empty())//while queue is not empty
    {
      int index = get_front();
      front++;
      for (int i = 0; i < targets[index]->recipe_count; i++)
      {
        pid_t pid=fork();
         if (pid > 0)
         {
            wait(NULL);
         }
         else if(pid==0)
         {//split file and arguments, then execute
           char *** tokens = malloc(sizeof(char***));
           makeargv(targets[index]->recipe[i]," \n", tokens);
           char *args[LINE_SIZE];
           int j=0;
           while (tokens[0][j]!=NULL)
           {
             args[j]=tokens[0][j];
             j++;
           }
           args[j]=NULL;
           execvp(args[0],args);
         
         }
      }
   }
  }
  else
  {
   while (!is_empty())
   {
      show_recipes(get_front());//print recipes
      front++;
   }
  }
}

// decide if targetName appearss as targets
int find_target(char *targetName)
{
   for (int i = 0; i < targetCount; i++)
   {
      if (targets[i] != NULL)
      {
         if (strcmp(targetName, targets[i]->name) == 0)
         {

            return i;
         }
      }
   }
   return -1;
}
//generate the adjacent Matrix
void add_target_to_graph()
{
   for (int i = 0; i < targetCount; i++)
   {
         for (int j = 0; j < targets[i]->dep_count; j++)
         {
            //if we can find this depend in target list
            if (find_target(targets[i]->depend[j]) != -1)
            {
               addEdge(i, find_target(targets[i]->depend[j]));
            }
         }

   }
}
