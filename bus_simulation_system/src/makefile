### CSci-3081W Project Support Code Makefile ###

# File History: This combines Prof. Keefe's Makefiles from past years
# with TA John Harwell's 3081W Makefiles from Fall 2016, which introduced
# auto-dependency generation and several other exciting features.


### Section 0: Change this when compiling on non-CSELabs machines ###

PROJECT_NAME = transit_sim

# Path to root of repo
REPOROOTDIR = $(shell git rev-parse --show-toplevel)

# Path to web, visualization, and library code
CS3081DIR = /classes/grades/Fall-2019/csci3081/project

### Section I: Definitions ###

# Root of the source tree for the project (e.g., could be just . or ./src)
SRCDIR = .
DRIVERDIR = ../drivers

# Output directories for the build process
PROJ_DIR = $(REPOROOTDIR)/project
WEBCODEDIR = $(PROJ_DIR)/web_code
BUILDDIR = $(PROJ_DIR)/build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj/$(PROJECT_NAME)
WEBOBJDIR = $(BUILDDIR)/webobj/visualizer_sim
DRIVEROBJDIR = $(BUILDDIR)/objdrivers
VISLIBS =  -lCppWebServer -lwebsockets -lcrypto -lssl -lz
LIBDIRS = -L$(CS3081DIR)/external/lib # $(BUILDDIR)/lib
EXTERNAL_DIR = $(PROJ_DIR)/src/external
#MINGFX_DIR = $(EXTERNAL_DIR)/MinGfx/build/install  #not using in F19

# The name of the executable to create
EXEFILE = $(BINDIR)/$(PROJECT_NAME)

# The list of files to compile for this project.  Defaults to all
# of the .cpp and .cc files in the source directory.  (We use both .cpp
# and .cc in order to support two different popular naming conventions.)
SRCFILES = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/*.cc) 
WEBSRCFILES = $(wildcard $(WEBCODEDIR)/web/*.cpp) $(wildcard $(WEBCODEDIR)/web/*.cc)

# For each of the source files found above, replace .cpp (or .cc) with
# .o in order to generate the list of .o files make should create.
OBJFILES = $(notdir $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(SRCFILES))))
WEBOBJFILES = $(notdir $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(WEBSRCFILES))))

# Add -Idirname to add directories to the compiler search path for finding .h files
INCLUDEDIRS = -I.. -I$(SRCDIR) -I$(SRCDIR)/.. -I$(DRIVERDIR) -I$(WEBCODEDIR)/web -I$(CS3081DIR)/external/include -I$(CS3081DIR)/external/include/cppwebserver -I$(CS3081DIR)/external/include/gtest -I$(CS3081DIR)/external/include/websockets

# The command to run for the C++ compiler and linker
CXX = /soft/gcc/7.1.0/Linux_x86_64/bin/g++
#CXX = g++
OMP = -fopenmp

# Arguments to pass to the C++ compiler.
# -c is required, it tells the compiler to output a .o file
#CXXFLAGS = -W -Werror -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c $(INCLUDEDIRS)

CXXFLAGS = -W -Wall -Wextra -fdiagnostics-color=always -Wfloat-equal -Wshadow -Wcast-align -Wcast-qual -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wswitch-default -Wsuggest-override -Wstrict-null-sentinel -Wsign-promo -Wold-style-cast -Woverloaded-virtual -Wctor-dtor-privacy -Wno-old-style-cast -Wno-cast-align -g -std=c++11 -c $(INCLUDEDIRS)

-include ../../Makefile.local

# Arguments to pass to the C++ linker, such as -L, but not -lfoo, which should go in LDLIBS¬
LDFLAGS = $(LIBDIRS)

# Library names to pass to the C++ linker, such as -lfoo¬
LDLIBS = $(VISLIBS)



# This is a list of "phony targets" -- targets that do not specify the name of a file.
# Rather they specify the name of a recipe to run whenever make is envoked with the target name.
.PHONY: clean all $(BINDIR) $(OBJDIR) $(WEBOBJDIR)


# The default target which will be run if the user just types "make"
all:  vis_sim #config_sim 

# This rule says that each .o file in $(OBJDIR)/ depends on the
# presence of the $(OBJDIR)/ directory.
$(addprefix $(OBJDIR)/, $(OBJFILES)): | $(OBJDIR)
$(addprefix $(WEBOBJDIR)/, $(WEBOBJFILES)): | $(WEBOBJDIR)

# And, this rule provides a recipe for creating that objdir.  The same rule applies
# to the bindir, where the exe will be output.
$(WEBOBJDIR) $(OBJDIR) $(BINDIR) $(DRIVEROBJDIR):
	@mkdir -p $@



# COMPILING (USING A PATTERN RULE):
# Since every .cpp (or .cc) file must be compiled into a .o, we will write this
# recipe using a pattern rule.  Using this recipe, any file that matches the pattern
# $(SRCDIR)/filename.cpp can be turned into $(OBJDIR)/filename.o.

# The same thing will also work for files with a .cc extension
$(OBJDIR)/%.o: $(SRCDIR)/%.cc 
	@echo "==== Auto-Generating Dependencies for $<. ===="
	@$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	@$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

# The same thing will also work for files with a .cc extension
$(DRIVEROBJDIR)/%_driver.o: $(DRIVERDIR)/%_driver.cc | $(DRIVEROBJDIR)
	@echo "==== Auto-Generating Dependencies for $<. ===="
	@$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	@$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

#NEED TO ADD EXECUTABLE RULE FOR BUILDING TransitSim.obj
$(DRIVEROBJDIR)/$(PROJECT_NAME).o: $(DRIVERDIR)/$(PROJECT_NAME).cc | $(DRIVEROBJDIR)
	@echo "==== Auto-Generating Dependencies for $<. ===="
	@$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	@$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

# Visualization
$(WEBOBJDIR)/%.o: $(WEBCODEDIR)/web/%.cpp
	@echo "==== Auto-Generating Dependencies for $<. ===="
	@$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	@$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

$(WEBOBJDIR)/%.o: $(WEBCODEDIR)/web/%.cc
	@echo "==== Auto-Generating Dependencies for $<. ===="
	@$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	@echo "==== Compiling $< into $@. ===="
	@$(CXX) $(OMP) $(CXXFLAGS) $(CXXLIBDIRS) -c -fPIC -o  $@ $<

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
-include $(addprefix $(WEBOBJDIR)/,$(WEBOBJFILES:.o=.d))


# LINKING:
# This rule is for the linking step of building a program.  The dependencies mean that
# the executable target that we are building depends upon all of the .o files that are
# generated by the compiler as well as the $(BINDIR), which must exist so we can
# output the exe there.  The recipe that follows calls g++ to tell it to link all the
# .o files into an executable program.

vis_sim: $(addprefix $(OBJDIR)/, $(OBJFILES)) $(addprefix $(WEBOBJDIR)/, $(WEBOBJFILES)) | $(BINDIR) 
	@echo "==== Linking $@. ===="
	@$(CXX) $(OMP) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) $(addprefix $(WEBOBJDIR)/, $(WEBOBJFILES)) -o $(BINDIR)/$@ $(LDLIBS)

$(EXEFILE): $(addprefix $(OBJDIR)/, $(OBJFILES)) $(DRIVEROBJDIR)/$(PROJECT_NAME).o | $(BINDIR) 
	@echo "==== Linking $@. ===="
	@$(CXX) $(OMP) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) $(DRIVEROBJDIR)/$(PROJECT_NAME).o -o $@ $(LDLIBS)

%_test: $(DRIVEROBJDIR)/%_driver.o $(addprefix $(OBJDIR)/, $(OBJFILES)) | $(BINDIR)
	@echo "==== Linking $@. ===="
	@$(CXX) $(OMP) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) $< -o $(BINDIR)/$@ $(LDLIBS)
	
check-style:
	@echo "==== Checking style is correct ===="
	@$(REPOROOTDIR)/cpplint/cpplint.py --root=.. *.cc *.h

check-style-cse:
	@echo "==== Checking style is correct ===="
	@$(REPOROOTDIR)/cpplint/cpplint-cse.sh --root=.. *.cc *.h

# Clean up the project, removing ALL files generated during a build.
#TODO - Need to add driver cleaning here
clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(WEBOBJDIR)
	@rm -rf $(EXEFILE)
	@rm -rf $(BINDIR)/*_test
	
