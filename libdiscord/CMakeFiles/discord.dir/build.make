# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cyb3rc001/Projects/Ferrum/libdiscord

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cyb3rc001/Projects/Ferrum/libdiscord

# Include any dependencies generated for this target.
include CMakeFiles/discord.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/discord.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/discord.dir/flags.make

CMakeFiles/discord.dir/lib/libdiscord.c.o: CMakeFiles/discord.dir/flags.make
CMakeFiles/discord.dir/lib/libdiscord.c.o: lib/libdiscord.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyb3rc001/Projects/Ferrum/libdiscord/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/discord.dir/lib/libdiscord.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/discord.dir/lib/libdiscord.c.o   -c /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/libdiscord.c

CMakeFiles/discord.dir/lib/libdiscord.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/discord.dir/lib/libdiscord.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/libdiscord.c > CMakeFiles/discord.dir/lib/libdiscord.c.i

CMakeFiles/discord.dir/lib/libdiscord.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/discord.dir/lib/libdiscord.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/libdiscord.c -o CMakeFiles/discord.dir/lib/libdiscord.c.s

CMakeFiles/discord.dir/lib/REST.c.o: CMakeFiles/discord.dir/flags.make
CMakeFiles/discord.dir/lib/REST.c.o: lib/REST.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyb3rc001/Projects/Ferrum/libdiscord/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/discord.dir/lib/REST.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/discord.dir/lib/REST.c.o   -c /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/REST.c

CMakeFiles/discord.dir/lib/REST.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/discord.dir/lib/REST.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/REST.c > CMakeFiles/discord.dir/lib/REST.c.i

CMakeFiles/discord.dir/lib/REST.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/discord.dir/lib/REST.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/REST.c -o CMakeFiles/discord.dir/lib/REST.c.s

CMakeFiles/discord.dir/lib/log.c.o: CMakeFiles/discord.dir/flags.make
CMakeFiles/discord.dir/lib/log.c.o: lib/log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyb3rc001/Projects/Ferrum/libdiscord/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/discord.dir/lib/log.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/discord.dir/lib/log.c.o   -c /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/log.c

CMakeFiles/discord.dir/lib/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/discord.dir/lib/log.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/log.c > CMakeFiles/discord.dir/lib/log.c.i

CMakeFiles/discord.dir/lib/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/discord.dir/lib/log.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/log.c -o CMakeFiles/discord.dir/lib/log.c.s

CMakeFiles/discord.dir/lib/json.c.o: CMakeFiles/discord.dir/flags.make
CMakeFiles/discord.dir/lib/json.c.o: lib/json.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyb3rc001/Projects/Ferrum/libdiscord/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/discord.dir/lib/json.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/discord.dir/lib/json.c.o   -c /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/json.c

CMakeFiles/discord.dir/lib/json.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/discord.dir/lib/json.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/json.c > CMakeFiles/discord.dir/lib/json.c.i

CMakeFiles/discord.dir/lib/json.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/discord.dir/lib/json.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/json.c -o CMakeFiles/discord.dir/lib/json.c.s

CMakeFiles/discord.dir/lib/utils.c.o: CMakeFiles/discord.dir/flags.make
CMakeFiles/discord.dir/lib/utils.c.o: lib/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyb3rc001/Projects/Ferrum/libdiscord/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/discord.dir/lib/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/discord.dir/lib/utils.c.o   -c /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/utils.c

CMakeFiles/discord.dir/lib/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/discord.dir/lib/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/utils.c > CMakeFiles/discord.dir/lib/utils.c.i

CMakeFiles/discord.dir/lib/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/discord.dir/lib/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cyb3rc001/Projects/Ferrum/libdiscord/lib/utils.c -o CMakeFiles/discord.dir/lib/utils.c.s

# Object files for target discord
discord_OBJECTS = \
"CMakeFiles/discord.dir/lib/libdiscord.c.o" \
"CMakeFiles/discord.dir/lib/REST.c.o" \
"CMakeFiles/discord.dir/lib/log.c.o" \
"CMakeFiles/discord.dir/lib/json.c.o" \
"CMakeFiles/discord.dir/lib/utils.c.o"

# External object files for target discord
discord_EXTERNAL_OBJECTS =

libdiscord.so.0.3.0: CMakeFiles/discord.dir/lib/libdiscord.c.o
libdiscord.so.0.3.0: CMakeFiles/discord.dir/lib/REST.c.o
libdiscord.so.0.3.0: CMakeFiles/discord.dir/lib/log.c.o
libdiscord.so.0.3.0: CMakeFiles/discord.dir/lib/json.c.o
libdiscord.so.0.3.0: CMakeFiles/discord.dir/lib/utils.c.o
libdiscord.so.0.3.0: CMakeFiles/discord.dir/build.make
libdiscord.so.0.3.0: CMakeFiles/discord.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cyb3rc001/Projects/Ferrum/libdiscord/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C shared library libdiscord.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/discord.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libdiscord.so.0.3.0 libdiscord.so.0.3.0 libdiscord.so

libdiscord.so: libdiscord.so.0.3.0
	@$(CMAKE_COMMAND) -E touch_nocreate libdiscord.so

# Rule to build all files generated by this target.
CMakeFiles/discord.dir/build: libdiscord.so

.PHONY : CMakeFiles/discord.dir/build

CMakeFiles/discord.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/discord.dir/cmake_clean.cmake
.PHONY : CMakeFiles/discord.dir/clean

CMakeFiles/discord.dir/depend:
	cd /home/cyb3rc001/Projects/Ferrum/libdiscord && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cyb3rc001/Projects/Ferrum/libdiscord /home/cyb3rc001/Projects/Ferrum/libdiscord /home/cyb3rc001/Projects/Ferrum/libdiscord /home/cyb3rc001/Projects/Ferrum/libdiscord /home/cyb3rc001/Projects/Ferrum/libdiscord/CMakeFiles/discord.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/discord.dir/depend
