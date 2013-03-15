# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /afs/cs.wisc.edu/s/cmake-2.8.7/@sys/bin/cmake

# The command to remove a file.
RM = /afs/cs.wisc.edu/s/cmake-2.8.7/@sys/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /afs/cs.wisc.edu/s/cmake-2.8.7/@sys/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /p/paradyn/development/bernat/builds/dyninst

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /p/paradyn/development/bernat/builds/dyninst

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/afs/cs.wisc.edu/s/cmake-2.8.7/@sys/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/afs/cs.wisc.edu/s/cmake-2.8.7/@sys/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/afs/cs.wisc.edu/s/cmake-2.8.7/@sys/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/afs/cs.wisc.edu/s/cmake-2.8.7/@sys/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/afs/cs.wisc.edu/s/cmake-2.8.7/@sys/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip
.PHONY : install/strip/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/afs/cs.wisc.edu/s/cmake-2.8.7/@sys/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /p/paradyn/development/bernat/builds/dyninst/CMakeFiles /p/paradyn/development/bernat/builds/dyninst/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /p/paradyn/development/bernat/builds/dyninst/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named common

# Build rule for target.
common: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 common
.PHONY : common

# fast build rule for target.
common/fast:
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/build
.PHONY : common/fast

#=============================================================================
# Target rules for targets named dynElf

# Build rule for target.
dynElf: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dynElf
.PHONY : dynElf

# fast build rule for target.
dynElf/fast:
	$(MAKE) -f elf/CMakeFiles/dynElf.dir/build.make elf/CMakeFiles/dynElf.dir/build
.PHONY : dynElf/fast

#=============================================================================
# Target rules for targets named dynDwarf

# Build rule for target.
dynDwarf: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dynDwarf
.PHONY : dynDwarf

# fast build rule for target.
dynDwarf/fast:
	$(MAKE) -f dwarf/CMakeFiles/dynDwarf.dir/build.make dwarf/CMakeFiles/dynDwarf.dir/build
.PHONY : dynDwarf/fast

#=============================================================================
# Target rules for targets named instructionAPI

# Build rule for target.
instructionAPI: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 instructionAPI
.PHONY : instructionAPI

# fast build rule for target.
instructionAPI/fast:
	$(MAKE) -f instructionAPI/CMakeFiles/instructionAPI.dir/build.make instructionAPI/CMakeFiles/instructionAPI.dir/build
.PHONY : instructionAPI/fast

#=============================================================================
# Target rules for targets named symtabAPI

# Build rule for target.
symtabAPI: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 symtabAPI
.PHONY : symtabAPI

# fast build rule for target.
symtabAPI/fast:
	$(MAKE) -f symtabAPI/CMakeFiles/symtabAPI.dir/build.make symtabAPI/CMakeFiles/symtabAPI.dir/build
.PHONY : symtabAPI/fast

#=============================================================================
# Target rules for targets named symLite

# Build rule for target.
symLite: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 symLite
.PHONY : symLite

# fast build rule for target.
symLite/fast:
	$(MAKE) -f symlite/CMakeFiles/symLite.dir/build.make symlite/CMakeFiles/symLite.dir/build
.PHONY : symLite/fast

#=============================================================================
# Target rules for targets named parseAPI

# Build rule for target.
parseAPI: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 parseAPI
.PHONY : parseAPI

# fast build rule for target.
parseAPI/fast:
	$(MAKE) -f parseAPI/CMakeFiles/parseAPI.dir/build.make parseAPI/CMakeFiles/parseAPI.dir/build
.PHONY : parseAPI/fast

#=============================================================================
# Target rules for targets named patchAPI

# Build rule for target.
patchAPI: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 patchAPI
.PHONY : patchAPI

# fast build rule for target.
patchAPI/fast:
	$(MAKE) -f patchAPI/CMakeFiles/patchAPI.dir/build.make patchAPI/CMakeFiles/patchAPI.dir/build
.PHONY : patchAPI/fast

#=============================================================================
# Target rules for targets named pcontrol

# Build rule for target.
pcontrol: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 pcontrol
.PHONY : pcontrol

# fast build rule for target.
pcontrol/fast:
	$(MAKE) -f proccontrol/CMakeFiles/pcontrol.dir/build.make proccontrol/CMakeFiles/pcontrol.dir/build
.PHONY : pcontrol/fast

#=============================================================================
# Target rules for targets named stackwalker

# Build rule for target.
stackwalker: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 stackwalker
.PHONY : stackwalker

# fast build rule for target.
stackwalker/fast:
	$(MAKE) -f stackwalk/CMakeFiles/stackwalker.dir/build.make stackwalk/CMakeFiles/stackwalker.dir/build
.PHONY : stackwalker/fast

#=============================================================================
# Target rules for targets named dyninstAPI

# Build rule for target.
dyninstAPI: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dyninstAPI
.PHONY : dyninstAPI

# fast build rule for target.
dyninstAPI/fast:
	$(MAKE) -f dyninstAPI/CMakeFiles/dyninstAPI.dir/build.make dyninstAPI/CMakeFiles/dyninstAPI.dir/build
.PHONY : dyninstAPI/fast

#=============================================================================
# Target rules for targets named dyninstAPI_RT

# Build rule for target.
dyninstAPI_RT: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dyninstAPI_RT
.PHONY : dyninstAPI_RT

# fast build rule for target.
dyninstAPI_RT/fast:
	$(MAKE) -f dyninstAPI_RT/CMakeFiles/dyninstAPI_RT.dir/build.make dyninstAPI_RT/CMakeFiles/dyninstAPI_RT.dir/build
.PHONY : dyninstAPI_RT/fast

#=============================================================================
# Target rules for targets named dyninstAPI_RT_m32

# Build rule for target.
dyninstAPI_RT_m32: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dyninstAPI_RT_m32
.PHONY : dyninstAPI_RT_m32

# fast build rule for target.
dyninstAPI_RT_m32/fast:
	$(MAKE) -f dyninstAPI_RT/CMakeFiles/dyninstAPI_RT_m32.dir/build.make dyninstAPI_RT/CMakeFiles/dyninstAPI_RT_m32.dir/build
.PHONY : dyninstAPI_RT_m32/fast

#=============================================================================
# Target rules for targets named dyninstAPI_RT_m32_static

# Build rule for target.
dyninstAPI_RT_m32_static: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dyninstAPI_RT_m32_static
.PHONY : dyninstAPI_RT_m32_static

# fast build rule for target.
dyninstAPI_RT_m32_static/fast:
	$(MAKE) -f dyninstAPI_RT/CMakeFiles/dyninstAPI_RT_m32_static.dir/build.make dyninstAPI_RT/CMakeFiles/dyninstAPI_RT_m32_static.dir/build
.PHONY : dyninstAPI_RT_m32_static/fast

#=============================================================================
# Target rules for targets named dyninstAPI_RT_static

# Build rule for target.
dyninstAPI_RT_static: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dyninstAPI_RT_static
.PHONY : dyninstAPI_RT_static

# fast build rule for target.
dyninstAPI_RT_static/fast:
	$(MAKE) -f dyninstAPI_RT/CMakeFiles/dyninstAPI_RT_static.dir/build.make dyninstAPI_RT/CMakeFiles/dyninstAPI_RT_static.dir/build
.PHONY : dyninstAPI_RT_static/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... common"
	@echo "... dynElf"
	@echo "... dynDwarf"
	@echo "... instructionAPI"
	@echo "... symtabAPI"
	@echo "... symLite"
	@echo "... parseAPI"
	@echo "... patchAPI"
	@echo "... pcontrol"
	@echo "... stackwalker"
	@echo "... dyninstAPI"
	@echo "... dyninstAPI_RT"
	@echo "... dyninstAPI_RT_m32"
	@echo "... dyninstAPI_RT_m32_static"
	@echo "... dyninstAPI_RT_static"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

