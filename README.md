# Projects



Project 1 ----- Simple Make 

Parse the makefile and build a dependency graph for the (optional) provided target. Also, execute the recipes for the said target, by spawning a new process per recipe, via fork and exec, as determined by the graph traversal. If no target is specified as a command line argument, the first target in the makefile is chosen.

Alternatively, if your first argument is a print flag (-p) followed by the makefile, you must only print the target, dependencies, and recipes in the makefile. A second type of flag (-r) followed by the makefile must print the recipe order of the target. Do not fork/exec the recipes when running either of the flags.



Project 2 ----- Multiple Processing MapReduce  

Given a folder with multi-level hierarchy, i.e., folders with multiple level of folders and text files. Each textfile has a word per line. Your task is to count the number of words, per letter of the alphabet, i.e., comparethe first letter of each word to increment the count corresponding to a letter, in the entire folder hierarchy.The result should be reported in the alphabetical order.
Key parties involved in the project:

Master process - Parent process to all the spawned processes•Mapper processes - Executes the map function on the partitioned data. The number of mapperprocesses should be specified at the execution time as input argument•Reducer process - Executes the reduce function over the results from all the mapper process. 

We have only a single reducer process for this project.

There are four phases in this project. 
1) the data partitioning phase where the ’master’ will traversethrough the folder hierarchy, identify all the files and split them equally among the mapper processes. 
2) the ’mappers’ will process the files alloted to them by the ’master’ and each ofthem will come up with a list of per letter word count. 
3) each ’mapper’ will send theirlist to the ’reducer’ process, who will combine them all to give a single list. 
4) In the last phase, the final listis then taken by the ’master’ and reported.




Project 3 ----- Multiple Threads MapReduce  

In multithreading “word count statistics” application, the program contains: a master thread, one producer thread and many consumer threads. 

The producer and consumers will share a queue for data transfering. 

For program execution flow, the entire program contains 4 parts: 

1) the master thread initializes the shared queue, result histogram, producer thread and consumer threads; 2) the producer thread will read the input file, cut the data into smaller pieces and feed into the shared queue; 
3) the consumers will read from the shared queue, compute the “word count statistics” for its data pieces and synchronize the result with a global histogram; 
4) after producer and all consumers complete their work, the master thread writes the final result into the output file.