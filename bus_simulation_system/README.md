
### Running the Transit Simulator and Visualization:

#### Step by step for instructions for CSE Labs machines or vole users

**<port_number> below should be a number above 8000 that includes the last 3 digits of your student id.**
**So, if your student id number is: 1459345, use 8345, or 9345**
1. Navigate to base project directory(project/)  
2. Make and run the server:
```
$ cd src
$ make 
$ cd ..
$./build/bin/vis_sim <port_number>
```
#### You must run by doing `./build/bin/vis_sim <port_number>`.
#### You _cannot_ cd to bin/ and run `./vis_sim <port_number>`
3. Run your browser on vole or CSE Labs machine, and enter following address in the address bar of your browser (Firefox/Chrome):
```
http://127.0.0.1:<port_number>/web_graphics/project.html
```
#### Step by step instructions for ssh users
You can SSH using a Windows machine with Git Bash.
```
**<port_number> below should be a number above 8000 that includes the last 3 digits of your student id.**
**So, if your student id number is: 1459345, use 8345, or 9345**

ssh -L <port number>:127.0.0.1:<port_number> <x500>@<cse_labs_computer>.cselabs.umn.edu
```

1. Navigate to base project directory(project/)  
2. make and start server:
```
$ cd src
$ make 
$ cd ..
$./build/bin/vis_sim <port_number>
```
#### You must run by doing `./build/bin/vis_sim <port_number>`.
#### You _cannot_ cd to bin/ and run `./vis_sim <port_number>`
3. Navigate to the following address into the address bar of a browser (Firefox/Chrome) running on your LOCAL machine (e.g, your PC):
```
http://127.0.0.1:<port_number>/web_graphics/project.html
```
**NOTE**: As part of your development process, you should ensure that **all Tests** pass before pushing any changes. 

### To Compile and Run Unit Tests created with Google Test:

- cd `tests`
- `make`
- `../build/bin/unittest`

### Style Check:

- `[path_to_cpplint]/cpplint/cpplint-cse.sh --root=[path_target_dir] [file_name]`


