# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Volumes/Data/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Volumes/Data/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/max/Documents/LastCourseWork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/max/Documents/LastCourseWork

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Volumes/Data/CLion.app/Contents/bin/cmake/mac/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Volumes/Data/CLion.app/Contents/bin/cmake/mac/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/max/Documents/LastCourseWork/CMakeFiles /Users/max/Documents/LastCourseWork/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/max/Documents/LastCourseWork/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named LastCourseWork

# Build rule for target.
LastCourseWork: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 LastCourseWork
.PHONY : LastCourseWork

# fast build rule for target.
LastCourseWork/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/build
.PHONY : LastCourseWork/fast

#=============================================================================
# Target rules for targets named LastCourseWork_autogen

# Build rule for target.
LastCourseWork_autogen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 LastCourseWork_autogen
.PHONY : LastCourseWork_autogen

# fast build rule for target.
LastCourseWork_autogen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork_autogen.dir/build.make CMakeFiles/LastCourseWork_autogen.dir/build
.PHONY : LastCourseWork_autogen/fast

LastCourseWork_autogen/mocs_compilation.o: LastCourseWork_autogen/mocs_compilation.cpp.o

.PHONY : LastCourseWork_autogen/mocs_compilation.o

# target to build an object file
LastCourseWork_autogen/mocs_compilation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/LastCourseWork_autogen/mocs_compilation.cpp.o
.PHONY : LastCourseWork_autogen/mocs_compilation.cpp.o

LastCourseWork_autogen/mocs_compilation.i: LastCourseWork_autogen/mocs_compilation.cpp.i

.PHONY : LastCourseWork_autogen/mocs_compilation.i

# target to preprocess a source file
LastCourseWork_autogen/mocs_compilation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/LastCourseWork_autogen/mocs_compilation.cpp.i
.PHONY : LastCourseWork_autogen/mocs_compilation.cpp.i

LastCourseWork_autogen/mocs_compilation.s: LastCourseWork_autogen/mocs_compilation.cpp.s

.PHONY : LastCourseWork_autogen/mocs_compilation.s

# target to generate assembly for a file
LastCourseWork_autogen/mocs_compilation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/LastCourseWork_autogen/mocs_compilation.cpp.s
.PHONY : LastCourseWork_autogen/mocs_compilation.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/main.cpp.s
.PHONY : main.cpp.s

mainwindow.o: mainwindow.cpp.o

.PHONY : mainwindow.o

# target to build an object file
mainwindow.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/mainwindow.cpp.o
.PHONY : mainwindow.cpp.o

mainwindow.i: mainwindow.cpp.i

.PHONY : mainwindow.i

# target to preprocess a source file
mainwindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/mainwindow.cpp.i
.PHONY : mainwindow.cpp.i

mainwindow.s: mainwindow.cpp.s

.PHONY : mainwindow.s

# target to generate assembly for a file
mainwindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/mainwindow.cpp.s
.PHONY : mainwindow.cpp.s

rsa.o: rsa.cpp.o

.PHONY : rsa.o

# target to build an object file
rsa.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/rsa.cpp.o
.PHONY : rsa.cpp.o

rsa.i: rsa.cpp.i

.PHONY : rsa.i

# target to preprocess a source file
rsa.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/rsa.cpp.i
.PHONY : rsa.cpp.i

rsa.s: rsa.cpp.s

.PHONY : rsa.s

# target to generate assembly for a file
rsa.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/LastCourseWork.dir/build.make CMakeFiles/LastCourseWork.dir/rsa.cpp.s
.PHONY : rsa.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... LastCourseWork_autogen"
	@echo "... LastCourseWork"
	@echo "... LastCourseWork_autogen/mocs_compilation.o"
	@echo "... LastCourseWork_autogen/mocs_compilation.i"
	@echo "... LastCourseWork_autogen/mocs_compilation.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... mainwindow.o"
	@echo "... mainwindow.i"
	@echo "... mainwindow.s"
	@echo "... rsa.o"
	@echo "... rsa.i"
	@echo "... rsa.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

