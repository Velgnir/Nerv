# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/l/Nerv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/l/Nerv/cmake-build-debug

# Utility rule file for Nerv.analyze.

# Include any custom commands dependencies for this target.
include CMakeFiles/Nerv.analyze.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Nerv.analyze.dir/progress.make

CMakeFiles/Nerv.analyze: ../bin/Nerv
CMakeFiles/Nerv.analyze: target.err
	cat target.err 1>&2

target.err: PVS-Studio/src/main.cpp.plog
target.err: PVS-Studio/src/buttoncustommenu.cpp.plog
target.err: PVS-Studio/includes/mainwindow.cpp.plog
target.err: PVS-Studio/includes/CustomScrollArea.cpp.plog
target.err: PVS-Studio/src/fileinlist.cpp.plog
target.err: PVS-Studio/src/filecontroller.cpp.plog
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/l/Nerv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating target.err"
	cat /home/l/Nerv/cmake-build-debug/PVS-Studio/src/main.cpp.plog /home/l/Nerv/cmake-build-debug/PVS-Studio/src/buttoncustommenu.cpp.plog /home/l/Nerv/cmake-build-debug/PVS-Studio/includes/mainwindow.cpp.plog /home/l/Nerv/cmake-build-debug/PVS-Studio/includes/CustomScrollArea.cpp.plog /home/l/Nerv/cmake-build-debug/PVS-Studio/src/fileinlist.cpp.plog /home/l/Nerv/cmake-build-debug/PVS-Studio/src/filecontroller.cpp.plog > target.err
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E remove -f target.err.pvs.raw
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E rename target.err target.err.pvs.raw
	/usr/bin/plog-converter -t errorfile target.err.pvs.raw -o target.err -a GA:1,2
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E remove -f target.err.pvs.raw

PVS-Studio/includes/CustomScrollArea.cpp.plog: ../includes/CustomScrollArea.cpp
PVS-Studio/includes/CustomScrollArea.cpp.plog: PVS-Studio.cfg
PVS-Studio/includes/CustomScrollArea.cpp.plog: ../includes/CustomScrollArea.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/l/Nerv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Analyzing CXX file includes/CustomScrollArea.cpp"
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E make_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/includes
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E remove_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/includes/CustomScrollArea.cpp.plog
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -D PVS_STUDIO_AS_SCRIPT=TRUE -D "PVS_STUDIO_COMMAND=/usr/bin/pvs-studio-analyzer;analyze;--output-file;/home/l/Nerv/cmake-build-debug/PVS-Studio/includes/CustomScrollArea.cpp.plog;--source-file;/home/l/Nerv/includes/CustomScrollArea.cpp;--cfg;/home/l/Nerv/cmake-build-debug/PVS-Studio.cfg;--platform;linux64;--preprocessor;gcc;--cxx;/usr/bin/c++;--cl-params;-I/usr/include;-I/usr/include;-I/home/l/Nerv/cmake-build-debug/Nerv_autogen/include;-I/home/l/Nerv/includes;-I/usr/include;-I/usr/include;-I/usr/include;-I/usr/include/qt/;-I/usr/include/qt/QtWidgets;-I/usr/include/qt/;-I/usr/include/qt/QtGui;-I/usr/include/qt/;-I/usr/include/qt/QtCore;-I/usr/lib/qt//mkspecs/linux-g++;-DBOOST_PROGRAM_OPTIONS_NO_LIB;-DBOOST_PROGRAM_OPTIONS_DYN_LINK;-DQT_WIDGETS_LIB;-DQT_GUI_LIB;-DQT_CORE_LIB;-DPVS_STUDIO;/home/l/Nerv/includes/CustomScrollArea.cpp" -P /home/l/Nerv/cmake/extra/PVS-Studio.cmake

PVS-Studio/includes/mainwindow.cpp.plog: ../includes/mainwindow.cpp
PVS-Studio/includes/mainwindow.cpp.plog: PVS-Studio.cfg
PVS-Studio/includes/mainwindow.cpp.plog: ../includes/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/l/Nerv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Analyzing CXX file includes/mainwindow.cpp"
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E make_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/includes
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E remove_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/includes/mainwindow.cpp.plog
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -D PVS_STUDIO_AS_SCRIPT=TRUE -D "PVS_STUDIO_COMMAND=/usr/bin/pvs-studio-analyzer;analyze;--output-file;/home/l/Nerv/cmake-build-debug/PVS-Studio/includes/mainwindow.cpp.plog;--source-file;/home/l/Nerv/includes/mainwindow.cpp;--cfg;/home/l/Nerv/cmake-build-debug/PVS-Studio.cfg;--platform;linux64;--preprocessor;gcc;--cxx;/usr/bin/c++;--cl-params;-I/usr/include;-I/usr/include;-I/home/l/Nerv/cmake-build-debug/Nerv_autogen/include;-I/home/l/Nerv/includes;-I/usr/include;-I/usr/include;-I/usr/include;-I/usr/include/qt/;-I/usr/include/qt/QtWidgets;-I/usr/include/qt/;-I/usr/include/qt/QtGui;-I/usr/include/qt/;-I/usr/include/qt/QtCore;-I/usr/lib/qt//mkspecs/linux-g++;-DBOOST_PROGRAM_OPTIONS_NO_LIB;-DBOOST_PROGRAM_OPTIONS_DYN_LINK;-DQT_WIDGETS_LIB;-DQT_GUI_LIB;-DQT_CORE_LIB;-DPVS_STUDIO;/home/l/Nerv/includes/mainwindow.cpp" -P /home/l/Nerv/cmake/extra/PVS-Studio.cmake

PVS-Studio/src/buttoncustommenu.cpp.plog: ../src/buttoncustommenu.cpp
PVS-Studio/src/buttoncustommenu.cpp.plog: PVS-Studio.cfg
PVS-Studio/src/buttoncustommenu.cpp.plog: ../src/buttoncustommenu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/l/Nerv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Analyzing CXX file src/buttoncustommenu.cpp"
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E make_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/src
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E remove_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/src/buttoncustommenu.cpp.plog
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -D PVS_STUDIO_AS_SCRIPT=TRUE -D "PVS_STUDIO_COMMAND=/usr/bin/pvs-studio-analyzer;analyze;--output-file;/home/l/Nerv/cmake-build-debug/PVS-Studio/src/buttoncustommenu.cpp.plog;--source-file;/home/l/Nerv/src/buttoncustommenu.cpp;--cfg;/home/l/Nerv/cmake-build-debug/PVS-Studio.cfg;--platform;linux64;--preprocessor;gcc;--cxx;/usr/bin/c++;--cl-params;-I/usr/include;-I/usr/include;-I/home/l/Nerv/cmake-build-debug/Nerv_autogen/include;-I/home/l/Nerv/includes;-I/usr/include;-I/usr/include;-I/usr/include;-I/usr/include/qt/;-I/usr/include/qt/QtWidgets;-I/usr/include/qt/;-I/usr/include/qt/QtGui;-I/usr/include/qt/;-I/usr/include/qt/QtCore;-I/usr/lib/qt//mkspecs/linux-g++;-DBOOST_PROGRAM_OPTIONS_NO_LIB;-DBOOST_PROGRAM_OPTIONS_DYN_LINK;-DQT_WIDGETS_LIB;-DQT_GUI_LIB;-DQT_CORE_LIB;-DPVS_STUDIO;/home/l/Nerv/src/buttoncustommenu.cpp" -P /home/l/Nerv/cmake/extra/PVS-Studio.cmake

PVS-Studio/src/filecontroller.cpp.plog: ../src/filecontroller.cpp
PVS-Studio/src/filecontroller.cpp.plog: PVS-Studio.cfg
PVS-Studio/src/filecontroller.cpp.plog: ../src/filecontroller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/l/Nerv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Analyzing CXX file src/filecontroller.cpp"
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E make_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/src
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E remove_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/src/filecontroller.cpp.plog
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -D PVS_STUDIO_AS_SCRIPT=TRUE -D "PVS_STUDIO_COMMAND=/usr/bin/pvs-studio-analyzer;analyze;--output-file;/home/l/Nerv/cmake-build-debug/PVS-Studio/src/filecontroller.cpp.plog;--source-file;/home/l/Nerv/src/filecontroller.cpp;--cfg;/home/l/Nerv/cmake-build-debug/PVS-Studio.cfg;--platform;linux64;--preprocessor;gcc;--cxx;/usr/bin/c++;--cl-params;-I/usr/include;-I/usr/include;-I/home/l/Nerv/cmake-build-debug/Nerv_autogen/include;-I/home/l/Nerv/includes;-I/usr/include;-I/usr/include;-I/usr/include;-I/usr/include/qt/;-I/usr/include/qt/QtWidgets;-I/usr/include/qt/;-I/usr/include/qt/QtGui;-I/usr/include/qt/;-I/usr/include/qt/QtCore;-I/usr/lib/qt//mkspecs/linux-g++;-DBOOST_PROGRAM_OPTIONS_NO_LIB;-DBOOST_PROGRAM_OPTIONS_DYN_LINK;-DQT_WIDGETS_LIB;-DQT_GUI_LIB;-DQT_CORE_LIB;-DPVS_STUDIO;/home/l/Nerv/src/filecontroller.cpp" -P /home/l/Nerv/cmake/extra/PVS-Studio.cmake

PVS-Studio/src/fileinlist.cpp.plog: ../src/fileinlist.cpp
PVS-Studio/src/fileinlist.cpp.plog: PVS-Studio.cfg
PVS-Studio/src/fileinlist.cpp.plog: ../src/fileinlist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/l/Nerv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Analyzing CXX file src/fileinlist.cpp"
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E make_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/src
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E remove_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/src/fileinlist.cpp.plog
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -D PVS_STUDIO_AS_SCRIPT=TRUE -D "PVS_STUDIO_COMMAND=/usr/bin/pvs-studio-analyzer;analyze;--output-file;/home/l/Nerv/cmake-build-debug/PVS-Studio/src/fileinlist.cpp.plog;--source-file;/home/l/Nerv/src/fileinlist.cpp;--cfg;/home/l/Nerv/cmake-build-debug/PVS-Studio.cfg;--platform;linux64;--preprocessor;gcc;--cxx;/usr/bin/c++;--cl-params;-I/usr/include;-I/usr/include;-I/home/l/Nerv/cmake-build-debug/Nerv_autogen/include;-I/home/l/Nerv/includes;-I/usr/include;-I/usr/include;-I/usr/include;-I/usr/include/qt/;-I/usr/include/qt/QtWidgets;-I/usr/include/qt/;-I/usr/include/qt/QtGui;-I/usr/include/qt/;-I/usr/include/qt/QtCore;-I/usr/lib/qt//mkspecs/linux-g++;-DBOOST_PROGRAM_OPTIONS_NO_LIB;-DBOOST_PROGRAM_OPTIONS_DYN_LINK;-DQT_WIDGETS_LIB;-DQT_GUI_LIB;-DQT_CORE_LIB;-DPVS_STUDIO;/home/l/Nerv/src/fileinlist.cpp" -P /home/l/Nerv/cmake/extra/PVS-Studio.cmake

PVS-Studio/src/main.cpp.plog: ../src/main.cpp
PVS-Studio/src/main.cpp.plog: PVS-Studio.cfg
PVS-Studio/src/main.cpp.plog: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/l/Nerv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Analyzing CXX file src/main.cpp"
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E make_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/src
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E remove_directory /home/l/Nerv/cmake-build-debug/PVS-Studio/src/main.cpp.plog
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -D PVS_STUDIO_AS_SCRIPT=TRUE -D "PVS_STUDIO_COMMAND=/usr/bin/pvs-studio-analyzer;analyze;--output-file;/home/l/Nerv/cmake-build-debug/PVS-Studio/src/main.cpp.plog;--source-file;/home/l/Nerv/src/main.cpp;--cfg;/home/l/Nerv/cmake-build-debug/PVS-Studio.cfg;--platform;linux64;--preprocessor;gcc;--cxx;/usr/bin/c++;--cl-params;-I/usr/include;-I/usr/include;-I/home/l/Nerv/cmake-build-debug/Nerv_autogen/include;-I/home/l/Nerv/includes;-I/usr/include;-I/usr/include;-I/usr/include;-I/usr/include/qt/;-I/usr/include/qt/QtWidgets;-I/usr/include/qt/;-I/usr/include/qt/QtGui;-I/usr/include/qt/;-I/usr/include/qt/QtCore;-I/usr/lib/qt//mkspecs/linux-g++;-DBOOST_PROGRAM_OPTIONS_NO_LIB;-DBOOST_PROGRAM_OPTIONS_DYN_LINK;-DQT_WIDGETS_LIB;-DQT_GUI_LIB;-DQT_CORE_LIB;-DPVS_STUDIO;/home/l/Nerv/src/main.cpp" -P /home/l/Nerv/cmake/extra/PVS-Studio.cmake

PVS-Studio.cfg:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/l/Nerv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Generating PVS-Studio.cfg"
	/home/l/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E echo analysis-mode=31 > /home/l/Nerv/cmake-build-debug/PVS-Studio.cfg

Nerv.analyze: CMakeFiles/Nerv.analyze
Nerv.analyze: PVS-Studio.cfg
Nerv.analyze: PVS-Studio/includes/CustomScrollArea.cpp.plog
Nerv.analyze: PVS-Studio/includes/mainwindow.cpp.plog
Nerv.analyze: PVS-Studio/src/buttoncustommenu.cpp.plog
Nerv.analyze: PVS-Studio/src/filecontroller.cpp.plog
Nerv.analyze: PVS-Studio/src/fileinlist.cpp.plog
Nerv.analyze: PVS-Studio/src/main.cpp.plog
Nerv.analyze: target.err
Nerv.analyze: CMakeFiles/Nerv.analyze.dir/build.make
.PHONY : Nerv.analyze

# Rule to build all files generated by this target.
CMakeFiles/Nerv.analyze.dir/build: Nerv.analyze
.PHONY : CMakeFiles/Nerv.analyze.dir/build

CMakeFiles/Nerv.analyze.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Nerv.analyze.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Nerv.analyze.dir/clean

CMakeFiles/Nerv.analyze.dir/depend:
	cd /home/l/Nerv/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/l/Nerv /home/l/Nerv /home/l/Nerv/cmake-build-debug /home/l/Nerv/cmake-build-debug /home/l/Nerv/cmake-build-debug/CMakeFiles/Nerv.analyze.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Nerv.analyze.dir/depend

