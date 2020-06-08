# Understanding and  Extending the Visual Transit System Simulator

## Iteration 1 - **NOTE, THE REQUIREMENTS IN THIS DOCUMENT ARE SUBJECT TO CHANGE. CHECK IT EVERY DAY OR TWO**<hr>
### Version 1 Issued February 24th
### UPDATE 1 - March 2nd - Updated Assessment Discussion on Google Tests
### UPDATE 2 - March 5th - More clarification on Google Tests (Iteration 1, Deliverable 2)
### UPDATE 3 - March 17th - Adjusted due dates following COVID-19 impacts (Iteration 1, Deliverable 3)
### UPDATE 4 - March 19th - Updated Doxygen requirements (Iteration 1, Deliverable 3)

| Date | Item | Description of Verification and Validation of Deliverable(s) |
|:----:|:-----|:------------|
| FRI, Feb 28, 11:55pm | UML diagram of the existing simulation (in the `project/src` directory and *visual\_simulation* class in the `project/web_code/web` directory - submit via Canvas | inspection |
| FRI, March 6, 11:55pm | Preliminary Google Tests for 'Bus', 'Stop', 'Passenger' and 'Route'   | Pass automated tests and inspection |
| TUE, March 24, 11:55pm | Documentation and Code Implementation | Automated tests and inspection |

In lab 9, you are (were) given a working version of a transit system simulation with a visualization capability.  For this semester's 3081 project, you will refactor (update and extend) the functionality of the  simulation you were given in lab 9 while rigorously following the process for using version control specified in lab 10. The current simulation models transit around the University of Minnesota campus via bus. The simulation you were given consists a single route with multiple stops and runs until the upper bound number of update time steps  specified in the simulation is reached. 

Your completed project deliverables should demonstrate good software design and development practices using good design methodologies, and rigorously follow the process for using version control you learned in lab 10.

Intermediate deadlines are designed to keep you on  track in the iterative development process you are using to develop iteration 1 and the rest of the project this semester. 

For this iteration you will be submitting the following deliverables  based upon the timetable specified above. Below is the order of submission:

1. First deliverable:  Create a UML class diagram of the domain classes in the `project/src` directory and the visualization\_simulator class in the `project/web_code/web` directory  you were given in Lab 09.  
2. Second deliverable:  Create Google Unit tests for the classes 'Bus', 'Stop'', 'Passenger', and 'Route' classes in the ` project/src` directory. As specified in lab 9, you create the tests, make the tests, and run the tests from the `project/tests` directory. Refer to lab 8 for a review of how to create, compile, and execute google tests. See the assessment section below and the item Iteration 1, Deliverable 2 in Week 7 of your class Canvas site for additional details on delivery.
3. Third set of deliverables:
    1. *Clean up* a few existing issues
    2.  Add a new route to the simulation by adding it to the config.txt file in the `project/config` directory.
    3.  Design and Implement a bus factory capable of  creating small, regular, and large buses, and update your initial UML diagram to include it. 
    4.  Add a pause button to the simulation.
    5.  Add the ability for the bus to skip a stop if there are no passengers waiting at an upcoming stop, and no passengers are planning to unload at the upcoming stop. 
    6.  In your Doxygen mainpage, create a user guide that tutors a new user, with your level of experience, on  obtaining, configuring, compiling, and running the simulation, and discuss the alternate design choices you considered for your bus factory. Your discussion should include  at least one pro and con of each design, and why you chose to implement the design you implemented. 
    7.  Ensure all new classes and methods you have written are properly documented. All header files must document the classes and their methods using Doxygen, and all implementation (that is, *.cc) files must have self-documenting code.
    8. Correct and update the first UML diagram you delivered to include changes to your code including your factory class(es) and their relationships to the classes that already existed in the simulation. 


### Deliverables and Submission Process
With the exception of the PDF versions of your UML diagrams, which will be submitted via an assignment item on Canvas, you will submit all your deliverables via GitHub according to the process specified lab 10.  We will tag and pull your repository at the specified due dates and grade them according to the contents at that time.

>#### You must verify that your submission compiles on a cselabs machine and it is complete. You will receive zero or be heavily penalized if your code does not compile and/or we cannot generate documentation using Doxygen as specified in  Lab 7 upon submission.

The schedule is very tight, and it is important that you keep up with the project. The project will continue to build throughout the semester, and if you get behind, it will be very difficult to catch up. For this reason, **late
assignments will not be accepted**, but you will receive partial credit for partial completion of the requirements - so **ALWAYS MAKE SURE TO SUBMIT SOMETHING - SOME POINTS ARE BETTER THAN NONE**.

You can convert this requirements document to pdf using this tool: http://www.markdowntopdf.com/

<hr>

## Documentation and Code Implementation Requirements

### Overview

The goal of this software project is to enhance a rudimentary transit simulator in which the simulation can be controlled via external configuration (without code change) and be visualized within a graphics window. 

In this iteration, you do the following development including:

- enhancing/modifying the base code
- formulating unit tests with Google Test
- adding to the simulation class structure 
- ensuring Google style guide compliance
- create design documentation using UML
- using Doxygen to document and generate documentation
- Use git, and produce self-documenting code (i.e. good organization and naming conventions). 

Teaching staff (Undergraduate TA's, Graduate TA's, and Instructors)  will also be working diligently to provide the structure and support for development, testing, and documentation. Automation in unit testing, style compliance, in-house github testing, and documentation will make this an easier process, however it means that you will have to develop within the constraints of these systems. Often there is a learning curve and a lot of systems trouble-shooting to get it all working, so start early!

In the first iteration, you will be enhancing the core functionality of the simulation to by designing and implementing the items listed above,  to a  simulation which currently consists of a single scenario involving campus transit via bus here at the University of Minnesota. This will suit us fine as we are just beginning to understand the structure and capability of the existing simulation. Iterations 2 and 3 will include more changes, enhancements/extensions, and put the core functionality to greater use. 

### Functional Requirements

You are being provided with a significant initial code base. The first iteration is focused on building domain entities and getting practiced in the software development process. It is also a drop into the depths of C++ syntax. If you have questions about the code provided, please ask. We do not expect you to understand all the constructs in this code. Below is an outline of the existing functionality.

The code is organized such that simulation behavior (i.e. the model) is separate from visualization (i.e. the view), which allows for automated unit testing using Google Test. In addition, there have been a few entities which have been made into abstractions to allow for extension (and for grading). The  primary driver of the visual simulation is you, the user, via the simulation graphics panel (which displays the map, sliders for configuring the simulation, and the start button, which starts the execution of the simulation).  The code that drives the simulation can be found in the JavaScript file `sketch.js` located in the directory `project/web_graphics`.

The *main function* (in the file *main.cc*) and the *visualization\_simulator* class in the directory `project/web_code/web` are used to configure the transit simulation and facilitate communication via the simulation domain classes (found in the `project/src` directory) and the graphical user interface displayed on a web page via a *web\_server* (whose code is also found in `project/web_code/web`). 

<hr>

**REQUIREMENTS you need to fulfill**

> This is just functionality. Along the way, make sure to document the code using
Doxygen syntax in the header files, and self documenting code (as discussed in McConnell's text in Chapter 32) in the class implementation (\*.cc) files and the main function.  You should also test for Google Style compliance using cpplint.

Below is a prioritized list of feature enhancements, fixes, and refactoring of the code. **Complete all functionality in one priority level before moving on to the next.** In this way, if we run out of time, the low priority items will be dropped from the requirements.

#### General understanding

The statistics we have are route-based, we know how likely it is that a passenger will show up at that stop in each time unit. When more than one bus is generated for a route, we need to take care with stops. After a bus has passed a stop, but has not yet finished their route, it is possible for passengers to "show up" to stops the bus has already passed. However, when another bus is created for the same route, it should come and pick up these passengers. This means that each bus may have its own understanding of its own route, but the stops have relationships with multiple buses in the simulation. This is something we will discuss and work through in class.

Buses do not make more than one trip through their routes. When they finish both of their routes (outbound and inbound), the bus is  from the simulation. This prevents us from doing interesting things with fuel cost and tracking, but also lowers complexity in a few different places.

Before discussing various levels of priority for iteration 1 development, there is one method which requires a special note.

###### _Report_

All of our principal domain entities (passenger, bus, stop, route) have this method. This method was created during the high-level design discussions. This output format has been specified and will very likely not change.  It is used not only for functional purposes for visualization of data in a non-graphical application, but also for verifying functional operation in testing.

#### Priority Level 1 : Clean up a few items in the simulation and add a new Route

##### Step 1
###### Clean up the following items in the code that you were given
In the `project/src` directory:

1. Fix the indentation in the` Bus` class in any areas that need it (check both the `h` and `cc` file)
2. Change the definition of `PassengerLoader::LoadPassenger()` so it returns a `bool` instead of an `int` - and make sure it the result is style compliant
3. Refactor naming:  Change `Route::NextStop` to `Route::ToNextStop`

In the `project/web_code/web` directory:

1. Fix the indentation in the file `main.cc`

###### Step 2

Add a new route to the file `config.txt` in the directory `project/config`.  Note the route should have two components, and outgoing and incoming component, and outgoing and incoming routes should start and end at the same locations  - as follows.  The start for the outgoing route should be the end for the incoming route, and the start for the incoming route should be the end for the outgoing route. 

You can create a new route that is a subset of the route that was given in the `config.txt` file (an express route), or an entirely new route.  To obtain the longitude and latitude of locations, use google maps!

Any route you create should use locations that are currently within the bounds of the map currently displayed by the simulation we gave you. 

It should be noted that when a real-world stop on a bus schedule has stopping locations on opposite sides of the street, we treat these as two different Stops in our vernacular.

One other note, the probability of a passenger being generated during a simulation update for a stop is the last value for a stop.

##### Priority Level 2:  Design a bus factory and implement it in the simulation

You should create a bus factory class that is capable of creating large, regular, or small capacity busses and implement it in the simulation.  You can do this by creating a concrete factory class or an abstract factory.

Note the values of small, regular, and large should be 30, 60, 90.  Moreover, this document will be updated with more information specific requirements for the factory as we discuss it further in class.

##### Priority Level 3: Add Functionality to Pause / Resume

Add a pause/resume  button to the simulation.  If a user presses the pause/resume button, the simulation should pause.  When the user presses the button again, the simulation should resume from where it left off.

This will entail adding a button to the graphical user interface, and depending on the design, could require the addition of command to the command pattern implemented in the `my_web_server_command` files in the directory `project/web_code/web`.  This document will by updated with more information on the specifications for this functionality in the coming weeks.

##### Priority Level 4: Skip Stops

The current version of the simulation stops at every stop along a route whether there are passengers at the stop or not.  Add functionality that enables the functionality enabling a  bus to skip a stop if there are no passengers waiting at an upcoming stop, and no passengers are planning to unload at the upcoming stop. 

##### Challenge  [NOTE: This is UNGRADED, only for fun.]

In early prototyping and debugging of individual units, it is very common to simply use the display for output of information. std::cout is a familiar friend in this. However, once we get to a point where we want to have a persistent access to results, flexibility in operation and easier ability to test program output. To this end, we  refactor our code to allow for the use of other ostream objects in place of std::cout for the 'Report() 'methods that exist within our system.

Refactor the  code to include the ability to accept the name of an output file on the command line to which all output will be written.  If no name is provided on the command line, the simulation should write its output  to std::cout

<hr>

### Unit Testing with Google Test

https://github.com/google/googletest

Unit tests are essential in a large-scale project, because the entire code base can be tested regularly and automatically as it is being developed. In the strictest application of Test-Driven Development (TDD), the tests are written _before_ the code, which helps solidify requirements and write testable code.

A sample test file is provided in the /project/tests directory. This directory must be a sibling to your _src_ directory. When you _make_ the tests by running the makefile in the `project/tests` directory , they will generate an executable (in build/bin) which, when executed, displays a report of the tests. Use this file as a guide to your own testing. While the requirements for testing in Preliminary Turn-in #2 (more later) are rather light, you can expect a much more robust testing requirement in later iterations. Do not slack on making good tests for your code!

### Google Style Guide Compliance

https://google.github.io/styleguide/cppguide.html

Consistency in code organization, naming conventions, file structure, and formatting makes code easier to read and integrate. There are many options with various merits, so it is up to the development team to establish these
conventions, or, in the words of Kevin Wendt, an instructor for previous iterations of the course, "The only style guide that really matters is the one your boss uses." We decided to use the Google style guide because it is published, documented, and has automated tests. We don't agree with every decision, but we are complying so that we are all coding to a single standard.

To test your code for Google style compliance, you can run cpplint on a cselabs machine (and will how style compliance will be automatically checked on submission):

```
cd src
../../cpplint/cpplint-cse.sh --root=.. *.h *.cc
```

The tag `--root=..` impacts the header guard. The header guards provided in the base code all start with `SRC`. If you are getting errors due to the header guard because it is expecting `INCLUDE_SRC` or no `SRC` **do not change the header guard.** Instead, check that the flag is set properly. If the `--root` flag is not working, please notify staff so that we can figure out how to fix it.

<hr>

## Documentation

- UML diagrams
- Doxygen generated web pages including mainpage.h 
- Self-Documenting code that is Google Style compliant

Code documentation comes in many forms for many audiences. For this project, **your audience is other programmers**, who need to understand class interfaces, function parameters, function behavior, code organization, class organization, and code logic. Self-documenting code (i.e. using good organization and naming conventions) is an efficient means of communicating, since you have to write the code anyway. _Good_ comments - not too much, not too little - help guide others through the logic and class interfaces. For the larger picture of code and class structure, use UML diagrams and Doxygen-generated (automatic) web pages.

#### UML

The UML diagram is a visual aid that helps other programmers better understand the code structure. It should include only those aspects that are essential, otherwise your diagram will get too cluttered and overwhelm the reader. Here are some things to keep in mind as you are designing your UML:

- Make the most important classes prominent in the layout (i.e. your eye tends to focus in that general area when you first look at it).
- Lay out the classes so that the connections have as few crossovers as possible.
- Do not include setters and getters in your methods list unless there is something special about them that you need to communicate.
- You should not include structs or enumerated types unless they add value to the understanding of the overall code structure.
- If a class is composed of another class, you can show that association with a solid line arrow (if there is only 1) or using the _compose_ diamond.
- Include cardinality where appropriate.
- Add comments to classes and/or relationships to clarify the interaction or to point out subtleties that are essential to using the code.

The final diagram you submit for iteration 1 UML should reflect the changes you made while completing the code requirements. We will be looking for proper use of UML components, and a correct depiction of the code structure.

There are many free tools that you can use to create the UML including Doxygen, and  draw.io (see: https://www.draw.io/). **Submit your UML  in a .pdf file  via the submission item on Canvas**.

#### Doxygen

Doxygen automatically generates documentation of class and code structure when you follow some simple conventions for commenting within your code (_see_ http://www.doxygen.nl/manual/index.html and https://caiorss.github.io/C-Cpp-Notes/Doxygen-documentation.html). You have had a lab on Doxygen (lab 7) and we will likely cover a bit more in class. To start with, look over the documentation provided with the code base to understand how to document classes, methods, parameters, and even _todo's_ and _bugs_ in your code. In lab 7, you learned how to compile with your Doxyfile and generate web pages. Please look over the generated web pages for missing and incorrect information. The requirements for Doxygen include:

- the file `project/docs/Doxyfile` to generate documentation (after you complete lab 9, you should have this in your `project/docs` directory).

- a _mainpage.h_ file that serves as the homepage of your automated documentation. This is an introduction to the code to other programmers who might be new to the project and need to know how to obtain it, configure it, compile it, and execute it. After you complete lab 9, you should have a mainpage.h file that you can extend in your `project/src` directory. 

- full documentation for new classes and methods.

- a discussion of at least two ways in which you could have implemented the bus factory.  The discussion should clearly describe each possible implementation (use a UML diagram), and discuss at least one pro and one con of implementing each of the alternatives.  Finally, you should specify which alternative you implemented, and why. 

- The /html directory should *not* be in your repo in github.umn.edu - nor should your build directory, executable files, or object files.

> As part of your fresh clone prior to submission, please also compile the Doxygen and look at the generated webpages.

All of these elements of documentation will be assessed, accounting for a significant portion of your grade for each iteration (for this iteration - iteration 1, documentation will account for 1/2 of your grade). Think about these two extremes: 1) your code functions perfectly and you have almost no documentation - you will likely fail on this iteration; 2) your code is not functional and will only compile when you comment most of it out, but if you have complete, great documentation - you will likely get a decent grade on this iteration. **Get in the habit of creating the documentation along with the code.**

<hr>

## Assessment

Your software **must compile on a cselabs machine or it will not be graded, and you will recieve a zero for your submission**. We will not grade your project unless it compiles. As long as you provide a version that compiles, we will evaluate those aspects that are partially functional for partial credit. In other words, <u>comment it out if it breaks compilation</u>.

Your software will be assessed through automatic testing and by the TAs. You will receive immediate feedback whenever you push to github (although not now - we will let you know when those scripts are in place). At the deadline, all submissions will be downloaded and the automated testing will no longer be available. Through both automated testing and the TAs, the process for testing will be to `make clean` then `make`. We **highly encourage** you too freshly clone your repo on a **cselabs machine** and to then `make clean` and `make`, followed by a run of your tests to confirm all is working well before submitting your tests and code.

This is the breakdown for point distribution:

20% : Iteration \#1
- 5% : UML (base code, draft). Refine for submission with Final Documentation.
- 10% : Preliminary Testing Submission
- 45% : Final Documentation
- 40% : Final Code

### Documentation Assessment ( 50% )

#### Draft of UML Class Diagrams ( 5% )

Preliminary Turn-in #1 will require you to turn in a UML diagram of the project code. You will depict project code you've already been given in the `project/src` directory and the visual\_simulation class in the `project/web/web_code` directory. **__At this point in time, the reality is that it is YOU who needs to understand the code we have provided,  and this exercise will be a tremendous help in that regard, saving you hours when you start to code.__**  Keep in mind that UML is a visual aid and should include only those aspects that are essential, otherwise your diagram will get too cluttered and overwhelming to the reader. Keep in mind that you can add notes and clarification within the document.

This is a draft of the final product, and we anticipate that it will be revised and improved. We will be looking for general proper use of UML syntax, and a correct depiction of the code structure of the existing project code (code from shared-upstream's support-code branch). The UML syntax you should use is specified and documented here: https://cppcodetips.wordpress.com/2013/12/23/uml-class-diagram-explained-with-c-samples/

#### Complete Iteration Documentation ( 45% )

#### Design Document and UML

Documentation includes a design overview of the core domain elements (the classes you're building) provided in mainpage.h in /src and your final updated UML diagram in PDF file format. The mainpage instructions for how to obtain, configure, compile, and execute the simulation should be written in prose and your discussion of the design and implementation of your factory class should be at least 2 pages of text (if it were on an 8.5x11 paper), probably not more than 3.5. Your should highlight important elements of your bus factory design and implementation,  and the structure of your domain elements. We will look for a well written and well organized document that clearly articulates the design. It must stand alone in the sense that anyone reading it should not have to look at code to understand the design. This will likely require images of UML and/or snippets of code included. 

Your initial UML diagram should be updated to include the class(es), methods, and relationships that you have added or changed during your iteration 1 developement activities. **Submit your final version of your UML diagram in a .pdf file via the submission item on Canvas.**

#### Google Style Compliance

We will run the automated test using 'cpplint' to check compliance. There are a few additional elements for compliance that _cpplint_ does not check for, thus TAs will inspect for those. In general, 1 or 2 minor or isolating deviations from the Google Style guide are acceptable. Significant and persistent variations, however, will be docked.

#### Doxygen Documentation

We will compile the code to generate _Doxygen_ web pages. All classes and major functions must be documented as specified in the _Doxygen_ documentation.

#### GitHub Issues

Your repository must include Issues that communicate to the TAs. If there are no bugs in your code, include a GitHub Issue that states that there are no known bugs to report  and that further verification is necessary (never say that there aren't bugs, because we know that that is typically not the case :-). We anticipate that a few bugs will exist in your project and they will reveal themselves during testing. If you have a few bugs AND you report them, then you will lose fewer points than if you don't report them - provided the bugs aren't preventing the simulation from running to completion. Also, keep in mind that development will continue throughout the semester, and if you can't fix your code this iteration, you *might* have an opportunity in successive iterations to do so(there are no implied guarantees on this though), so keep use github to keep track of all your bugs.

For this iteration, every time you make one single change to your code, you should follow the process documented in lab 10.  Create an issue, a new branch, address the issue (add or fix functionality, etc.), test.  When it works, commit and include a **meaningful** commit message (what did you fix, add, etc.),  merge the new branch back in with the development branch, and then test again.  We will grade you on your adherence to the process. You should have at LEAST as many issues, branches, commits, and merges as there are updates and new functionality required by the iteration. 

#### Self-Documenting Code

TAs will inspect code for good naming conventions, good code organization, and internal comments to highlight logic. You should not nest conditional statements too deep. Methods should not be more than a screen full, if possible. Names should be descriptive of the variable's or function's purpose. Like elements should be next to each other in the file.  Review Chapter 32 in the McConnell text, available on the Class Canvas site, for more information on how to create self-documenting code. 

### Code Assessment ( 50% )

#### Preliminary Testing Submission ( 10% )  **UPDATE**

In the week prior to the due date of the completed iteration, we will confirm that you have submitted work for Preliminary Turn-in #2. You must include tests for **all** public methods in the Passenger class, and at a minimum, the constructors of the Bus, Stop, and Route class, along with any methods that return a Boolean value to receive full points for the preliminary submission. There will be no manual inspection of the code at this point -- it is strictly a test for completed functionality and testing. We will ensure that your tests are effective using automatic means, similar to the Testing lab (Lab 8). There will be transparency in this process in that you will know what functionality will be tested, and you will see the results. Points earned at this stage are independent of the 40% points for the final submission.

In the `project/tests` directory, the file `passenger_UT.cc` has been started as an example for you. You should add the rest of the required tests to this file, and create `bus_UT.cc`, `stop_UT.cc`, and `route_UT.cc` files in the same directory to test the other classes.

Your tests do not have to be google style compliant, and you do not need to follow the version control development process specified in lab 10 to design and implement your tests

**Your google tests should be in the development branch in your repository on github.umn.edu by the end of the day Friday,  March 3.**  _Remember to GIT ADD, GIT COMMIT and GIT PUSH them before the deadline_

##### Note that your google tests are not required to be google-style compliant.  You should put the tests under revision control using git, but you do not have to follow the process specified in lab 10 to create, compile and run your google tests. Finally, see the README.md  file in the `project/src` directory for instructions on how to compile and run your google tests. 

#### Completed Iteration Code ( 40% )

Code functionality will be tested with automated tests through Github, which in turn run the automated unit tests of Google Test. We expect you to have basic feedback running by the end of week two of Iteration 1. In that case, you will see _some_ of the elements we'll be testing in our assessment. Review the automated feedback prior to final submission, as it will identify any issues with directory structure, compilation issues, or failed unit tests. Assessment will also include a visual inspection of the simulation and its output, as well as a visual inspection of the code.

<hr>

## Getting Started

AFTER reading this document, if you have not done so, complete lab 9. If you have completed lab 9 and 10, then you are ready to start refactoring and augmenting the simulation - make sure you follow the process documented in lab 10 when doing so. 

<hr>

## Important notes to remember

>Your software is a reflection of your understanding of the requirements as specified in this document. If you do not understand any portion of the requirements or you think that the requirements are underspecified, it is your responsibility to get clarification from the instructor or a TA. Please read this document carefully and review it prior to turning in your iteration for assessment.

>The ONLY supported environment is the CSELabs environment. This is where we will run your code for assessment, and where you should absolutely ensure that your project will compile and run. It is recommended to log onto a CSELabs machine, do a **clean** pull of your repo (i.e., pull into a brand new directory), and then build and test your project.


<hr>

## Additional Resources

Local System and Compilation:
- Repo: https://github.umn.edu/umn-csci-3081-s20/csci3081-shared-upstream
- Compilation: https://gcc.gnu.org/
- Linux quick reference: https://files.fosswire.com/2007/08/fwunixref.pdf
- Makefile Resources: https://www.cs.bu.edu/teaching/cpp/writing-makefiles/


Testing:
- https://github.com/google/googletest
- Unit Testing: https://martinfowler.com/bliki/UnitTest.html

Style:
- https://google.github.io/styleguide/cppguide.html
- https://github.com/google/styleguide/tree/gh-pages/cpplint
- https://www.python.org/downloads/

Documentation:
- https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet

IDEs:
- Xemacs: https://www.xemacs.org/
- vi: http://www.lagmonster.org/docs/vi.html
- Atom: https://atom.io/
- Sublime: https://www.sublimetext.com/
- Eclipse: https://eclipse.org/















