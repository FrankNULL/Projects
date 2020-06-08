# Enhancing and Extending The Visual Transit System Simulator

### Version 1, April 13 Change in Deliverables and Submission: Failure to submit your deliverables in the required branch in your repository on github will result in a score of zero.
### Initial Release, April 11
## NOTE: This document will be subject to change. In most cases you will be notified of the changes via the announcement feature in Canvas, but you should check this document yourselves on a daily basis, as we will note the version and date of update in this document.

<hr>

**Congratulations!**  Iteration 2 is in the rear-view mirror. Onward to Iteration 3!

![Image of a simulation running with the observer pattern](observer_pattern.png)

In the second iteration you fixed your unit tests for the major classes, implemented regression testing, added an observer pattern to a single bus, and refactored your bus factory (bus depot) utilizing the strategy pattern . Most importantly, you created and augmented design documentation by updating the UML to incorporate the classes and methods you added.  You also documented your code using Doxygen and self-documenting code techniques. 

In this next iteration you will perform statistical analysis using the singleton pattern, change the color of the bus using the decorator pattern, change the intensity of the color of the bus based upon the number of passengers on the bus, and add an observer pattern to a single stop. These topics will be the focus of classroom lectures and labs.

<hr>

### Due Dates (are subject to change) and Content

| <span id="a1">Date</a> | Item | Description of Verification and Validation of Deliverable(s) |
|:----:|:-----|:------------|
| Fri, May 1, 11:55pm | Perform statistical analysis on the simulation output data using the singleton pattern. Implement a decorator pattern to change the color of a bus and change the intensity of the color of a bus based upon the number of passengers.  Add functionality to the observer pattern so it can be used to observe a single stop, and finally if needed, fix the problems/issues for your iteration 2 code. | Pass automated tests and by inspection |

Your completed project deliverables should demonstrate good software design by implementing the appropriate design methodologies and development practices. You should rigorously follow the process for using version control you learned in lab 10 and documentation procedures learned in lab 07. 

For this iteration there there is only one delivery date, and all final deliverables below are due on that date: 

1. Final deliverables: 

    1. Fix the pause button from iteration from iteration 1, which we broke in iteration 2.
    2. If necessary, fix your observer pattern for one bus from iteration 2. </br>
            a. If you did not use templates in the implementation of your observer pattern for one bus, then change the implementation to use templates. 
    3.  If necessary, fix your implementation of a Bus Depot to employ different strategies for the deployment of buses based upon differing sets of criteria. For example: time of day and/or route information, etc. Further details can be found in the iteration 2 requirements. The strategy pattern may be useful for designing and implementing this capability.
         >  **See: [Strategy Pattern](https://www.geeksforgeeks.org/strategy-pattern-set-1/)** for an overview of the strategy pattern.  
         The following links contain examples of implementation of the strategy patten in Java and C++: </br>
            - https://www.geeksforgeeks.org/strategy-pattern-set-2 (in Java), </br>
            - https://sourcemaking.com/design_patterns/strategy/cpp/1) (in C++)</br>
    4. Implement the functionality to observe one stop (which may be changed during execution) using the observer pattern.   
         > **See: [Observer Pattern]( https://www.geeksforgeeks.org/observer-pattern-set-1-introduction/)** for an overview of the observer pattern. Further details can be found in the section Deliverables and Submission Process. 
   5. Implement the singleton pattern to help formulate statistics from the output of the transit simulation. 
      > **See: [Singleton Pattern](https://www.geeksforgeeks.org/singleton-design-pattern-introduction/?ref=lbp)** for an overview of the singleton pattern. Further details can be found in the section Deliverables and Submission.
   6. You will be using the decorator pattern to change the color of the bus depending if it is inbound or outbound and to change the intensity of the color which will be dependent on the number of passengers on the bus. 
      > **See: [Decorator Pattern](https://www.geeksforgeeks.org/decorator-pattern/?ref=lbp)** for an overview of the decorator pattern. Further details can be found in the section Deliverables and Submission
   7. In your Doxygen mainpage add a section named: **"Designing and Implementing the Decorator Pattern"** that discusses:  
      - the design and implementation of your decorator pattern for changing the color of the bus depending on whether it is on the inbound or outbound route. Additionally,  your design and implementation should also include functionality for changing the intensity of the bus color based upon the number of passengers. 
      - The classes and methods you had to add and where you had to add them   
         > Include a UML in your discussion.
      - At least two designs, one which you implemented and one which you did not implement.  
         >Your discussion should include at least one advantage and one disadvantage for each design. 
      - Which parts of the design and implementation were most difficult for you, and include any tips or advice on how to understand and implement the pattern  
         > for example, what sources of information (e.g. documentation, lecture, lab) helped you understand that pattern, and fianlly, what enabled you to design and implement it (e.g. links to web sites, books, lectures, lab).
    8.  Ensure all **new classes and methods you have written are properly documented**. All header files must document the classes and their methods using Doxygen, and all implementation (that is, \*.cc) files must have self-documenting code. 
         > **You do not need to document the web GRAPHICS code base.** 
    9. Correct and update your UML class diagram from Iteration 3 to include the changes to your code, including all classes you added to complete the iteration 3 requirements and their relationships to each other and the previously existing classes.
    
**NOTE, if you are unable to complete all or a portion of an implementation item, include a discussion of your PROPOSED design of the decorator pattern in your mainpage, and your PROPOSED class design / changes for all your implementation items in your UML, and note that in a paragraph at the top of your mainpage so you receive credit for your design efforts. (Tell us what you did not sucessfully implement -- success is defined as the functionality compiles and executes.)**

#### Deliverables and Submission Process

With the exception of the PDF versions of your UML diagrams, which will be submitted via an assignment item on Canvas, you will submit all your deliverables via GitHub according to the process specified lab 10.  We will tag and pull your repository at the specified due date and grade them according to the contents at that time. With the exeception of your updated/corrected UML diagram - **All, your  final deliverables (due May 1) should in your master branch.** **Note -** *failure to submit your deliverables in the required branch in your repository on github will result in a score of zero.*

>#### You must verify that your submission compiles on a cselabs machine and it is complete. You will receive zero or be heavily penalized if your code does not compile and/or we cannot generate documentation using Doxygen as specified in Lab 7 upon submission.

The schedule is tight, and it is important that you keep up with the project. The project is **due on May 1 and we will not accept any late assignments after this date.** You will receive partial credit for partial completion of the requirements -- so **ALWAYS MAKE SURE TO SUBMIT SOMETHING - SOME POINTS ARE BETTER THAN NONE**.

You can convert this requirements document to pdf using this tool: http://www.markdowntopdf.com/

<hr>

### Overview

In this iteration, you will do the following development:

- enhancing/modifying the base code.
- collecting and formulating statistics on the simulation by implementing the singleton pattern.
- implementing the observer pattern to enable the GUI to observe a stop.
- implementing at least two new design patterns: the singleton pattern and the decorator pattern.
- augmenting the simulation class structure. 
- augmenting the design discussion in your Doxygen mainpage to include a discussion on your design and implementation of the decorator pattern. 
- ensuring Google style guide compliance.
- modifying/updating your iteration UML design documentation to include the classes and methods you add or refactor in iteration 3.
- using Doxygen to document all new classes and methods you add or modify in iteration 3 **(in the header files only)** and generate documentation.
- using Git, and producing self-documenting code (i.e. good organization and naming conventions in the header and cc files). 

Teaching staff (Undergraduate TA's, Graduate TA's, and Instructors)  will also be working diligently to provide the structure and support for development, testing, and documentation. Automation in unit testing, style compliance, in-house GitHub testing, and documentation will make this an easier process, however, it means that you will have to develop within the constraints of these systems. Often there is a learning curve and a lot of systems troubleshooting to get it all working, so start early!

In the first and second iterations, you enhanced the core functionality of the simulation. In this iteration, you will design and implement: a singleton pattern to collect statistical data;  an observer pattern to display information about a single stop to the user; and using the decorator pattern to apply color to the bus to indicate if the bus is either inbound/outbound and changing the color intensity of the bus based upon the number of passengers currently on the bus. 

<hr>

## Documentation and Code Implementation Requirements

### Overview

In this iteration, we need to add a few new elements to our design in order to allow for configuration and visualization of our simulation. Much of this has already been designed and implemented. The primary task will be to extend your domain elements to produce the data needed for visualization, and to merge the provided configuration and visualization code into your project code.

### Functional Requirements

> This is just functionality. Along the way, please document the code you write for this iteration using
Doxygen syntax and test for Google Style compliance using cpplint.

Below we specify the five sets of functionality you are to design and deliver for this iteration.

#### Priority Level 1 : Fixing your Pause Button, the Observer Pattern for a single bus, and the Bus Depot (Refactor the Factory) so it uses Deployment Strategies

How to implement the Pause button functionality  the the Observer pattern have been covered in labs. Class lectures were also used to cover the design and implementation details of the observer pattern. The details on how to implement the bus depot can be found in the iteration 2 requirements.
 

#### Priority Level 2 : Gather Statistics of the simulation by implementing the Singleton Pattern

For this part of the implementation the output from the Report methods in all of your bus classes will also be output to a file in csv format.  This should be accomplished by implementing the Singleton Pattern to write information to the file. This can be accomplished by adding appropriate classes to 'project/src' that will "write" the information generated by the Report method to an ostringstream object. 

You will need to parse the ostringstream object to format the CSV file with the relevant information which will be used to calculate the statistics specified below. 

Statistics that need to be calculated are:
 - the average wait times for passengers, 
 - the average number of passengers per bus, and
 - the total number of passengers that rode the bus during the simulation. 

> Designing and implementing the Singleton Pattern for statistical analysis will be covered in more detail in lecture and lab.  
      - [The singleton pattern](https://www.geeksforgeeks.org/singleton-design-pattern-introduction/?ref=lbp)  
      - [Statistical Definitions](https://www.statisticssolutions.com/common-statistical-formulas/)  
      - The stringstream classes in C++ you might find useful: [stringstream](http://www.cplusplus.com/reference/sstream/stringstream/) and [ostringstream](http://www.cplusplus.com/reference/sstream/ostringstream/)
   
#### Priority Level 3 : Coloring the bus using the Decorator Pattern

In the current implementation the bus color remains the same throughout the simulation process. A bus on an inbound route is the same color as the outbound route which makes them indistinguishable. For this part of the implementation you will need to make the color of the bus distinguishable depending on if the bus is on inbound route or an outbound route. This can be accomplished by using the decorator pattern and implementing the appropriate logic to change the color of the bus dependent on the type of route the bus is currently traveling. The two colors to use are marooon and gold since this is the University of Minnesota Transit System. 

> Designing and implementing the above Decorator Pattern for coloring the bus will be covered in more detail in lecture and lab.

#### Priority Level 4 : Implement an Observer Pattern to Display Relevant Stop Information for One Stop.

This will allow the user of the simulation to gather information on a specific stop via the simulation display. 

To accomplish this, it is recommended you modify two classes: the observer class (abstract/interface) and an observable/subject class using Templates. The observer pattern will be utilized to observe a single bus and a single stop. Since the functionality/algorithm would be the same except for the data type, a template should be used to avoid code duplication. 

Implementing the observer pattern for two subjects will entail two AddListenerCommands, one for the bus and one for the stop. In addition, these listeners need to be attached to the subject they are observing. Remember to clear all previous observers before attaching the observer to its appropriate subject. 

Implementing the additional observer pattern will entail modifying the graphical user interface, and once again require the addition of a command to the command pattern implemented in the `my_web_server_command` files in the directory `project/web_code/web`. 

#### Priority Level 5 : Changing the color intensity of the bus dependent on the number of passengers on the bus throughout the route.

For this implementation the intensity of the color should change as the number of passengers load/unload. It should increase in intensity (brighter) as the number of passengers increase and approach the capacity of the bus. Likewise the intensity should decrease (grow dimmer) as the number of passengers decrease during the simulation. In essence, you are introducing a color gradient. 

Designing and implementing the above will be covered in more detail in lecture and lab. 

#### Challenge:  Fix your regression test to work for iteration 3 updated bus, passenger, stop, and factory classes.

For regression tests, the goal is to verify that features that worked once still work, even as you continue to fix, add, and/or refactor the code base and the development environment (e.g. makefiles).

For our transit simulation, that means designing and implementing a structured scenario that can be run repeatedly and produce the same output each time it is executed while employing as many of the domain classes as possible.

While developing this test, you should store any config files you need in `project/config/` and anything else that might be helpful in a new directory you create named `project/resources/`, to ensure that changes you make to create the regression test do not break anything that was already working.

<hr>

### [Unit Testing with Google Test](https://github.com/google/googletest)


Unit tests are essential in a large-scale project, because the entire code base can be tested regularly and automatically as it is being developed. In the strictest application of Test-Driven Development (TDD), the tests are written _before_ the code, which helps solidify requirements and write testable code. Modify your unit tests based upon the feedback you have received, and ensure your existing unit tests (which tested the methods present in iteration 1 - even if they have been modified in successive iterations) compile and execute for iteration 3.  
> For this iteration, they should all be on the master branch on github. 

### [Google Style Guide Compliance](https://google.github.io/styleguide/cppguide.html)

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
- Doxygen generated web pages for all new and modifed code (classes and methods in the .h files) including mainpage.h 
- Self-Documenting code that is Google Style compliant (for all new and modified iteration 3 code in the .cc files)

Code documentation comes in many forms for many audiences. For this project, **your audience is other programmers**, who need to understand class interfaces, function parameters, function behavior, code organization, class organization, and code logic. Self-documenting code (i.e. using good organization and naming conventions) is an efficient means of communicating, since you have to write the code anyway. _Good_ comments -- not too much, not too little -- help guide others through the logic and class interfaces. For the larger picture of code and class structure, use UML diagrams and Doxygen-generated (automatic) web pages.

#### UML

The UML diagram is a visual aid that helps other programmers better understand the code structure. It should include only those aspects that are essential, otherwise your diagram will get too cluttered and overwhelm the reader. Here are some things to keep in mind as you are designing your UML:

- Make the most important classes prominent in the layout (i.e. your eye tends to focus in that general area when you first look at it).
- Lay out the classes so that the connections have as few crossovers as possible.
- Do not include setters and getters in your methods list unless there is something special about them that you need to communicate.
- You should not include structs or enumerated types unless they add value to the understanding of the overall code structure.
- If a class is composed of another class, you can show that association with a solid line arrow (if there is only 1) or using the _compose_ diamond.
- Include cardinality where appropriate.
- Add comments to classes and/or relationships to clarify the interaction or to point out subtleties that are essential to using the code.

The final diagram you submit for iteration 2 UML should reflect the changes you made while completing the code requirements. We will be looking for proper use of UML components, and a correct depiction of the code structure.

There are many free tools that you can use to create the UML including Doxygen, and  [draw.io](https://www.draw.io). **Submit your UML in a .pdf file via the submission item on Canvas**.

#### Doxygen

Doxygen automatically generates documentation of class and code structure when you follow some simple conventions for commenting within your code (_see_ http://www.doxygen.nl/manual/index.html and https://caiorss.github.io/C-Cpp-Notes/Doxygen-documentation.html). You have had a lab on Doxygen (Lab 7) and we will likely cover a bit more in class. To start with, look over the documentation provided with the code base to understand how to document classes, methods, parameters, and even _todo's_ and _bugs_ in your code. In Lab 7, you learned how to compile with your Doxyfile and generate web pages. Please look over the generated web pages for missing and incorrect information. The requirements for Doxygen include:

- the file `project/docs/Doxyfile` to generate documentation (in your `project/docs` directory).

- a _mainpage.h_ file that serves as the homepage of your automated documentation. The information that you added from iterations 1 and 2 should remain and be updated as necessary. You should have a `mainpage.h` file that you can extend in your `project/src` directory. 

- document all classes, methods, and functions that you add or update in interation 3 in their header (.h) files. 

-  add a section named: **"Designing and Implementing the Decorator Pattern"** that discusses the design and implementation of your decorator pattern for the bus, as per the description in the final deliverables discussion above. 


#### FINALLY: The /html directory generated by Doxygen should NOT be in your repo in github.umn.edu - nor should your build directory, executable files, or object files. ***Your submission will be assessed a penalty if they are!***

> As part of your fresh clone prior to submission, please also compile the Doxygen documentation and look at the generated webpages.

All of these elements of documentation will be assessed, accounting for a significant portion of your grade for each iteration (for this iteration, iteration 3, documentation will account for 1/2 of your grade). Consider these two extremes: 1) your code functions perfectly and you have almost no documentation -- you will likely fail on this iteration 2 ) your code is not functional and will only compile when you comment most of it out, but if you have complete, great documentation. If you follow option 2 you likely get a better grade than if you follow option 1, and will likely get a decent grade on this iteration. **Get in the habit of creating the design before the code, and documentation along with the code - and then update it when you complete your development and testing.**

<hr>

## Assessment

Your software **must compile on a cselabs machine or it will not be graded, and you will receive a zero for your submission**. For this iteration, your software **must compile on the _master_ branch or it will not be graded, and you will receive a zero for your submission**. We will not grade your project unless it compiles. As long as you provide a version that compiles, we will evaluate those aspects that are partially functional for partial credit. In other words, <u>comment code out if it breaks compilation</u>.

At the deadline, all submissions will be downloaded.   The process for testing will be to `make clean` then `make` followed by automated and manual assessment of the requirements for each submission. Thus,  we **vehemently encourage** you to create a new folder on a **cselabs machine**, clone your repo on a **cselabs machine** in that folder, then run  `make clean` and `make` in your newly cloned repo, followed by a run of your tests to confirm all is working well before submitting your tests and code.

This is the breakdown for point distribution:

20% : Iteration \#2
-  5% : Fixing Pause Button/Observer Pattern/Bus Depot
- 50% : Final Documentation
- 45% : Final Code

### Complete Iteration Documentation Assessment ( 50% )

#### Design Document and UML 

Documentation includes a design overview of the core domain elements (the classes you're building) provided in mainpage.h in /src and your final updated UML diagram in PDF file format. The mainpage should be augmented to add a design and implementation discussion of the Decorator Pattern (**"Designing and Implementing the Decorator Pattern"**) as specified above. It should be as long as you need it to be to write a discussion that addresses all items noted in the requirements above  (if it were on an 8.5x11 paper) - but should probably not be more than 3.5 pages.  We will look for a well written and well organized document that clearly articulates the design. It must stand alone in the sense that anyone reading it should not have to look at code to understand the design. This will likely require images of UML and/or snippets of code included. 

Your final UML diagram from iteration 2 should be updated to include the class(es), methods, and relationships that you have added or changed during your iteration 3 development activities. The UML syntax you should use is specified and documented [here](https://cppcodetips.wordpress.com/2013/12/23/uml-class-diagram-explained-with-c-samples/). We will be looking for general proper use of UML syntax, and a correct depiction of the code structure of the existing project code (code from shared-upstream's support-code branch). 

**Submit your final version of your UML diagram in a .pdf file via the submission item on Canvas.**

#### Google Style Compliance

We will run the automated test using 'cpplint' to check compliance. There are a few additional elements for compliance that _cpplint_ does not check for, thus TAs will inspect for those. In general, 1 or 2 minor or isolating deviations from the Google Style guide are acceptable. Significant and persistent variations, however, will be docked.

#### Doxygen Documentation

We will compile the code to generate _Doxygen_ web pages. All classes and major functions must be documented as specified in the _Doxygen_ documentation. 

#### GitHub Issues

Your repository must include Issues that communicate to the TAs. If there are no bugs in your code, include a GitHub Issue that states that there are no known bugs to report  and that further verification is necessary (never say that there aren't bugs, because we know that that is typically not the case :-). We anticipate that a few bugs will exist in your project and they will reveal themselves during testing. If you have a few bugs AND you report them, then you will lose fewer points than if you don't report them - provided the bugs aren't preventing the simulation from running to completion. 

Once again, for this iteration, every time you create or fix the functionality required by the iteration, you should follow the process documented in lab 10.  Create an issue, a new branch, address the issue (add or fix functionality, etc.), test.  When the new or updated/fixed functionality works,  commit and include a **meaningful** commit message (what did you fix, add, etc.),  merge the new branch back in with the development branch, and then test again.  We will grade you on your adherence to the process. You should have at LEAST as many issues, branches, commits, and merges as there are updates and new functionality required by the iteration. 

#### Self-Documenting Code

TAs will inspect code for good naming conventions, good code organization, and internal comments to highlight logic. You should not nest conditional statements too deep. Methods should not occupy more than one screen, if possible. Names should be descriptive of the variable's or function's purpose. Like elements should be next to each other in the file.  Review Chapter 32 in the McConnell text, available on the Class Canvas site, for more information on how to create self-documenting code. 
Finally, self-documenting code should be present for all classes, methods, and functions that you implement in the .cc files in iteration 3. **Note: self-documenting code is not done with Doxygen -- follow the guidelines specified in McConnell, Code Complete, Chapter 32**

### Code Assessment ( 50% )

_Remember to GIT ADD, GIT COMMIT and GIT PUSH a version of your code that compiles and executes to your master branch and github.umn.edu before the deadline_

#### Completed Iteration Code ( 45% )

We expect you to have some completed functionality implemented running by the end of week two of Iteration 3. By doing so, you will have an indication of  _some_ of the elements we'll be testing in our assessment. You should run and review the feedback from your unit tests prior to final submission, as it may identify any issues with your code. Instructional staff assessment will include a visual inspection of the simulation and its output, as well as a visual inspection of the code, in addition to our automated assessment.

<hr>


## Important notes to remember

>Your software is a reflection of your understanding of the requirements as specified in this document. If you do not understand any portion of the requirements or you think that the requirements are underspecified, it is your responsibility to get clarification from the instructor or a TA. Please read this document carefully and review it prior to turning in your iteration for assessment.

>The ONLY supported environment is the CSELabs environment. This is where we will run your code for assessment, and where you should absolutely ensure that your project will compile and run. It is recommended to log onto a CSELabs machine, do a **clean** pull of your repo (i.e., pull into a brand new directory), and then build and test your project.


<hr>

## Additional Resources

Local System and Compilation:
- [Repo](https://github.umn.edu/umn-csci-3081-s20/csci3081-shared-upstream)
- [Compilation](https://gcc.gnu.org/)
- [Linux quick reference](https://files.fosswire.com/2007/08/fwunixref.pdf)
- [Makefile Resources](https://www.cs.bu.edu/teaching/cpp/writing-makefiles/)


Testing:
- [Google Testing](https://github.com/google/googletest)
- [Unit Testing](https://martinfowler.com/bliki/UnitTest.html)

Style:
- [cppguide style guide](https://google.github.io/styleguide/cppguide.html)
- [cpplint](https://github.com/google/styleguide/tree/gh-pages/cpplint)
- [python](https://www.python.org/downloads/)

Documentation:
- [Markdown-cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

IDEs:
- [Xemacs](https://www.xemacs.org/)
- [vi](http://www.lagmonster.org/docs/vi.html)
- [Atom](https://atom.io/)
- [Sublime](https://www.sublimetext.com/)
- [Eclipse](https://eclipse.org/)
