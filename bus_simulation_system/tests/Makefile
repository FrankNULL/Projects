### CSci-3081W Project Support Code Makefile ###

# This Makefile is a bit different from the other project makefiles
# because it compiles both the project code in the src directory
# and the google test testing code in the tests code to create an
# executable called bin/unittest.  This also assumes that google
# test project has already been compiled into a gtest_main.a library
# that is available on the system.  This should be the case on the
# lab machines, but students compiling on their own machines should
# first build google test and then adjust the GTEST_DIR variable
# below to point to their local version of google test install dir.



# File History: This combines Prof. Keefe's Makefiles from past years
# with TA John Harwell's 3081W Makefiles from Fall 2016, which introduced
# auto-dependency generation and several other exciting features.


### Section 0: Change this when compiling on non-CSELabs machines ###

# Path to pre-installed cs3081 support libraries (Google Test, libsimple_graphics, nanogui, ...)
ROOTDIR = $(shell git rev-parse --show-toplevel)
CS3081DIR = $(ROOTDIR)/external/install

# The command to run for the C++ compiler and linker
CXX = g++

-include $(ROOTDIR)/external/etc/env

### Section I: Definitions ###

# Students: Uncomment the lines below to enable more feedback tests as
# you continue to write your code.  Before turning in your assignment
# you should be able to uncomment each of the tests and successfully
# build and run the unittest executable.

# Directory of source files for the project we wish to test
PROJROOTDIR = ..
PROJSRCDIR = $(PROJROOTDIR)/src

# Directory of source files for the unit tests themselves
TESTSRCDIR = .

# Output directories for the build process
BUILDDIR = ../build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj/tests

# The name of the executable to create
EXEFILE = $(BINDIR)/unittest

# Google Test includes its own main() function, so we do not want to
# compile the project's main function into our tests.  We will filter
# these files out from the list of project sources.
# Also, since our tests do not require graphics, we can also filter
# out the RobotViewer source files and avoid the dependency on the
# pre-installed graphics libraries on the CSELabs machines, making it
# a bit easier to develop and test project code on non-CSELabs machines.
MAINSRCFILES = $(PROJSRCDIR)/main.cc $(PROJSRCDIR)/main.cpp

# The list of files to compile for this project.  Defaults to all
# of the .cpp and .cc files in the source directory.  (We use both .cpp
# and .cc in order to support two different popular naming conventions.)
PROJSRCFILES = $(filter-out $(MAINSRCFILES), $(wildcard $(PROJSRCDIR)/*.cpp) $(wildcard $(PROJSRCDIR)/*.cc))

# Same as above, but captures the test files, which are in a different dir.
TESTSRCFILES = $(wildcard $(TESTSRCDIR)/*.cpp) $(wildcard $(TESTSRCDIR)/*.cc)

# For each of the source files found above, replace .cpp (or .cc) with
# .o in order to generate the list of .o files make should create.
OBJFILES = $(notdir $(patsubst %.cpp,%.o,$(patsubst %.cc,%.o,$(PROJSRCFILES)))) \
           $(notdir $(patsubst %.cpp,%.o,$(patsubst %.cc,%.o,$(TESTSRCFILES))))


# Add -Idirname to add directories to the compiler search path for finding .h files
INCLUDEDIRS = -I$(CS3081DIR)/include -I$(PROJROOTDIR) -I$(TESTSRCDIR) -isystem$(CS3081DIR)/include 

# Add -Ldirname to add directories to the linker search path for finding libraries
LIBDIRS = -L$(CS3081DIR)/lib

# Add -llibname to link with external libraries
LIBS = -lgtest_main -lgtest -lgmock -Wl,-rpath,$(CS3081DIR)/lib

UNAME = $(shell uname)
ifeq ($(UNAME), Darwin) # Mac OSX
	LIBS += -framework opengl
else # LINUX
	LIBS += -lGL
endif

# Arguments to pass to the C++ compiler.
# -c is required, it tells the compiler to output a .o file
# Optionally include -g to turn on debugging or include -O or -O2 to turn on optimizations instead
# Optionally include -Wall to turn on most warnings
CXXFLAGS = -g -Wall -Wextra -pthread -fprofile-arcs -ftest-coverage -c $(INCLUDEDIRS) $(DEFINES) -std=c++11

# Arguments to pass to the C++ linker, such as -L, but not -lfoo, which should go in LDLIBS
LDFLAGS = $(LIBDIRS) -pthread -fprofile-arcs -ftest-coverage

# Library names to pass to the C++ linker, such as -lfoo
LDLIBS = $(LIBS)


### Section II: Rules ###


# This is a list of "phony targets" -- targets that do not specify the name of a file.
# Rather they specify the name of a recipe to run whenever make is envoked with the target name.
.PHONY: clean all $(BINDIR) $(OBJDIR)


# The default target which will be run if the user just types "make"
all: $(CS3081DIR) $(EXEFILE)

# This rule says that each .o file in $(OBJDIR)/ depends on the
# presence of the $(OBJDIR)/ directory.
$(addprefix $(OBJDIR)/, $(OBJFILES)): | $(OBJDIR)

# And, this rule provides a recipe for creating that objdir.  The same rule applies
# to the bindir, where the exe will be output.
$(OBJDIR) $(BINDIR):
	@mkdir -p $@



# COMPILING (USING A PATTERN RULE):
# Since every .cpp (or .cc) file must be compiled into a .o, we will write this
# recipe using a pattern rule.  Using this recipe, any file that matches the pattern
# $(SRCDIR)/filename.cpp can be turned into $(OBJDIR)/filename.o.
$(OBJDIR)/%.o: $(PROJSRCDIR)/%.cpp
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(CXXFLAGS) $(CXXLIBDIRS) -c -o  $@ $<

# The same thing will also work for files with a .cc extension
$(OBJDIR)/%.o: $(PROJSRCDIR)/%.cc
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(CXXFLAGS) $(CXXLIBDIRS) -c -o  $@ $<


# Repeat the two pattern rules above for .cc/.cpp files in the test dir
$(OBJDIR)/%.o: $(TESTSRCDIR)/%.cpp
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(CXXFLAGS) $(CXXLIBDIRS) -c -o  $@ $<

$(OBJDIR)/%.o: $(TESTSRCDIR)/%.cc
	@echo "==== Auto-Generating Dependencies for $<. ===="
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	$(CXX) $(CXXFLAGS) $(CXXLIBDIRS) -c -o  $@ $<

# WITH AUTO-GENERATED DEPENDENCIES:
# Note that there are actually two steps to the compiling recipe above.  The second
# step should be familiar, it just calls g++ to compile the .cpp into a .o.  But,
# the first step is an advanced topic.  It calls the custom function make-depend-cxx()
# defined below, which calls the g++ compiler with special flags (the -M* parts)
# that tell g++ to output a make-compatable list of all of the .h files included
# by the specified C++ source file.  All of these .h files should be listed as
# dependencies of the .cpp file that is being compiled because if any of the included
# .h files change, our .cpp file will need to be recompiled in order to stay up to
# date.  So, we want to be thorough and capture all of these dependencies in our
# Makefile.  We could do this manually.  For each .cpp file we would need to add a
# rule to this Makefile that lists dependies, and would look something like this:
#    file1.o:  file1.cpp file1.h file2.h mydir/file3.h myotherdir/file4.h
# where all of the .h files are either included by file1.cpp or by each other.
# It's tedious and error prone to try to track down all these dependencies manually.
# So, instead, we ask the compiler to generate a list of dependencies for us and
# save it out to a new text file with a .d extension.  This text file lists the
# dependencies using the same Makefile syntax we would use if we wrote them down
# manually.  Read more about auto-dependency generation here:
# http://make.mad-scientist.net/papers/advanced-auto-dependency-generation
# usage: $(call make-depend,source-file,object-file,depend-file)
make-depend-cxx=$(CXX) -MM -MF $3 -MP -MT $2 $(CXXFLAGS) $1

# Once the make-depend-cxx() function auto-generates the .d text file of additional
# dependency rules, we need to load it into make, as if those rules were actually
# written in this file.  This is done with make's own "include" command, which
# enables us to include one Makefile within another.
-include $(addprefix $(OBJDIR)/,$(OBJFILES:.o=.d))



# LINKING:
# This rule is for the linking step of building a program.  The dependencies mean that
# the executable target that we are building depends upon all of the .o files that are
# generated by the compiler as well as the $(BINDIR), which must exist so we can
# output the exe there.  The recipe that follows calls g++ to tell it to link all the
# .o files into an executable program.
$(EXEFILE): $(addprefix $(OBJDIR)/, $(OBJFILES)) | $(BINDIR)
	@echo "==== Linking $@. ===="
	$(CXX) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) -o $@ $(LDLIBS)



# Clean up the project, removing ALL files generated during a build.
clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(EXEFILE)

# Check Style
check-style:
	@echo "==== Checking style is correct ===="
	$(ROOTDIR)/cpplint/cpplint.py --root=.. *.cc *.h

check-style-cse:
	@echo "==== Checking style is correct ===="
	$(ROOTDIR)/cpplint/cpplint-cse.sh --root=.. *.cc *.h

# External libraries
$(CS3081DIR):
	cd $(ROOTDIR)/external; make

clobber: clean
	cd $(ROOTDIR)/external; make clobber
