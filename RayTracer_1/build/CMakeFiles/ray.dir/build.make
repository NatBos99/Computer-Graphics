# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build

# Include any dependencies generated for this target.
include CMakeFiles/ray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray.dir/flags.make

CMakeFiles/ray.dir/Code/objloader.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/objloader.cpp.o: ../Code/objloader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ray.dir/Code/objloader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/objloader.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/objloader.cpp

CMakeFiles/ray.dir/Code/objloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/objloader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/objloader.cpp > CMakeFiles/ray.dir/Code/objloader.cpp.i

CMakeFiles/ray.dir/Code/objloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/objloader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/objloader.cpp -o CMakeFiles/ray.dir/Code/objloader.cpp.s

CMakeFiles/ray.dir/Code/objloader.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/objloader.cpp.o.requires

CMakeFiles/ray.dir/Code/objloader.cpp.o.provides: CMakeFiles/ray.dir/Code/objloader.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/objloader.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/objloader.cpp.o.provides

CMakeFiles/ray.dir/Code/objloader.cpp.o.provides.build: CMakeFiles/ray.dir/Code/objloader.cpp.o


CMakeFiles/ray.dir/Code/triple.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/triple.cpp.o: ../Code/triple.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ray.dir/Code/triple.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/triple.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/triple.cpp

CMakeFiles/ray.dir/Code/triple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/triple.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/triple.cpp > CMakeFiles/ray.dir/Code/triple.cpp.i

CMakeFiles/ray.dir/Code/triple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/triple.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/triple.cpp -o CMakeFiles/ray.dir/Code/triple.cpp.s

CMakeFiles/ray.dir/Code/triple.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/triple.cpp.o.requires

CMakeFiles/ray.dir/Code/triple.cpp.o.provides: CMakeFiles/ray.dir/Code/triple.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/triple.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/triple.cpp.o.provides

CMakeFiles/ray.dir/Code/triple.cpp.o.provides.build: CMakeFiles/ray.dir/Code/triple.cpp.o


CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o: ../Code/shapes/cylinder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/cylinder.cpp

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/cylinder.cpp > CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.i

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/cylinder.cpp -o CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.s

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o


CMakeFiles/ray.dir/Code/shapes/quad.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/quad.cpp.o: ../Code/shapes/quad.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ray.dir/Code/shapes/quad.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/quad.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/quad.cpp

CMakeFiles/ray.dir/Code/shapes/quad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/quad.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/quad.cpp > CMakeFiles/ray.dir/Code/shapes/quad.cpp.i

CMakeFiles/ray.dir/Code/shapes/quad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/quad.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/quad.cpp -o CMakeFiles/ray.dir/Code/shapes/quad.cpp.s

CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/quad.cpp.o


CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o: ../Code/shapes/mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/mesh.cpp

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/mesh.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/mesh.cpp > CMakeFiles/ray.dir/Code/shapes/mesh.cpp.i

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/mesh.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/mesh.cpp -o CMakeFiles/ray.dir/Code/shapes/mesh.cpp.s

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o


CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o: ../Code/shapes/sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/sphere.cpp

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/sphere.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/sphere.cpp > CMakeFiles/ray.dir/Code/shapes/sphere.cpp.i

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/sphere.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/sphere.cpp -o CMakeFiles/ray.dir/Code/shapes/sphere.cpp.s

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o


CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o: ../Code/shapes/triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/triangle.cpp

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/triangle.cpp > CMakeFiles/ray.dir/Code/shapes/triangle.cpp.i

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/shapes/triangle.cpp -o CMakeFiles/ray.dir/Code/shapes/triangle.cpp.s

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o


CMakeFiles/ray.dir/Code/main.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/main.cpp.o: ../Code/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ray.dir/Code/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/main.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/main.cpp

CMakeFiles/ray.dir/Code/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/main.cpp > CMakeFiles/ray.dir/Code/main.cpp.i

CMakeFiles/ray.dir/Code/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/main.cpp -o CMakeFiles/ray.dir/Code/main.cpp.s

CMakeFiles/ray.dir/Code/main.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/main.cpp.o.requires

CMakeFiles/ray.dir/Code/main.cpp.o.provides: CMakeFiles/ray.dir/Code/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/main.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/main.cpp.o.provides

CMakeFiles/ray.dir/Code/main.cpp.o.provides.build: CMakeFiles/ray.dir/Code/main.cpp.o


CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o: ../Code/lode/lodepng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/lode/lodepng.cpp

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/lode/lodepng.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/lode/lodepng.cpp > CMakeFiles/ray.dir/Code/lode/lodepng.cpp.i

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/lode/lodepng.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/lode/lodepng.cpp -o CMakeFiles/ray.dir/Code/lode/lodepng.cpp.s

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.requires

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.provides: CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.provides

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.provides.build: CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o


CMakeFiles/ray.dir/Code/image.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/image.cpp.o: ../Code/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ray.dir/Code/image.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/image.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/image.cpp

CMakeFiles/ray.dir/Code/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/image.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/image.cpp > CMakeFiles/ray.dir/Code/image.cpp.i

CMakeFiles/ray.dir/Code/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/image.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/image.cpp -o CMakeFiles/ray.dir/Code/image.cpp.s

CMakeFiles/ray.dir/Code/image.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/image.cpp.o.requires

CMakeFiles/ray.dir/Code/image.cpp.o.provides: CMakeFiles/ray.dir/Code/image.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/image.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/image.cpp.o.provides

CMakeFiles/ray.dir/Code/image.cpp.o.provides.build: CMakeFiles/ray.dir/Code/image.cpp.o


CMakeFiles/ray.dir/Code/scene.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/scene.cpp.o: ../Code/scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ray.dir/Code/scene.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/scene.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/scene.cpp

CMakeFiles/ray.dir/Code/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/scene.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/scene.cpp > CMakeFiles/ray.dir/Code/scene.cpp.i

CMakeFiles/ray.dir/Code/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/scene.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/scene.cpp -o CMakeFiles/ray.dir/Code/scene.cpp.s

CMakeFiles/ray.dir/Code/scene.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/scene.cpp.o.requires

CMakeFiles/ray.dir/Code/scene.cpp.o.provides: CMakeFiles/ray.dir/Code/scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/scene.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/scene.cpp.o.provides

CMakeFiles/ray.dir/Code/scene.cpp.o.provides.build: CMakeFiles/ray.dir/Code/scene.cpp.o


CMakeFiles/ray.dir/Code/raytracer.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/raytracer.cpp.o: ../Code/raytracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ray.dir/Code/raytracer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/raytracer.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/raytracer.cpp

CMakeFiles/ray.dir/Code/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/raytracer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/raytracer.cpp > CMakeFiles/ray.dir/Code/raytracer.cpp.i

CMakeFiles/ray.dir/Code/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/raytracer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/Code/raytracer.cpp -o CMakeFiles/ray.dir/Code/raytracer.cpp.s

CMakeFiles/ray.dir/Code/raytracer.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/Code/raytracer.cpp.o.requires

CMakeFiles/ray.dir/Code/raytracer.cpp.o.provides: CMakeFiles/ray.dir/Code/raytracer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/raytracer.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/raytracer.cpp.o.provides

CMakeFiles/ray.dir/Code/raytracer.cpp.o.provides.build: CMakeFiles/ray.dir/Code/raytracer.cpp.o


# Object files for target ray
ray_OBJECTS = \
"CMakeFiles/ray.dir/Code/objloader.cpp.o" \
"CMakeFiles/ray.dir/Code/triple.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/quad.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o" \
"CMakeFiles/ray.dir/Code/main.cpp.o" \
"CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o" \
"CMakeFiles/ray.dir/Code/image.cpp.o" \
"CMakeFiles/ray.dir/Code/scene.cpp.o" \
"CMakeFiles/ray.dir/Code/raytracer.cpp.o"

# External object files for target ray
ray_EXTERNAL_OBJECTS =

ray: CMakeFiles/ray.dir/Code/objloader.cpp.o
ray: CMakeFiles/ray.dir/Code/triple.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/quad.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o
ray: CMakeFiles/ray.dir/Code/main.cpp.o
ray: CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o
ray: CMakeFiles/ray.dir/Code/image.cpp.o
ray: CMakeFiles/ray.dir/Code/scene.cpp.o
ray: CMakeFiles/ray.dir/Code/raytracer.cpp.o
ray: CMakeFiles/ray.dir/build.make
ray: CMakeFiles/ray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray.dir/build: ray

.PHONY : CMakeFiles/ray.dir/build

CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/objloader.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/triple.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/main.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/image.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/scene.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/raytracer.cpp.o.requires

.PHONY : CMakeFiles/ray.dir/requires

CMakeFiles/ray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ray.dir/clean

CMakeFiles/ray.dir/depend:
	cd /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1 /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1 /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_1/build/CMakeFiles/ray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ray.dir/depend

