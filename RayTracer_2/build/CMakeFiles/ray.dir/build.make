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
CMAKE_SOURCE_DIR = /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build

# Include any dependencies generated for this target.
include CMakeFiles/ray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray.dir/flags.make

CMakeFiles/ray.dir/src/objloader.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/objloader.cpp.o: ../src/objloader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ray.dir/src/objloader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/objloader.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/objloader.cpp

CMakeFiles/ray.dir/src/objloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/objloader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/objloader.cpp > CMakeFiles/ray.dir/src/objloader.cpp.i

CMakeFiles/ray.dir/src/objloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/objloader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/objloader.cpp -o CMakeFiles/ray.dir/src/objloader.cpp.s

CMakeFiles/ray.dir/src/objloader.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/objloader.cpp.o.requires

CMakeFiles/ray.dir/src/objloader.cpp.o.provides: CMakeFiles/ray.dir/src/objloader.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/objloader.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/objloader.cpp.o.provides

CMakeFiles/ray.dir/src/objloader.cpp.o.provides.build: CMakeFiles/ray.dir/src/objloader.cpp.o


CMakeFiles/ray.dir/src/triple.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/triple.cpp.o: ../src/triple.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ray.dir/src/triple.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/triple.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/triple.cpp

CMakeFiles/ray.dir/src/triple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/triple.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/triple.cpp > CMakeFiles/ray.dir/src/triple.cpp.i

CMakeFiles/ray.dir/src/triple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/triple.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/triple.cpp -o CMakeFiles/ray.dir/src/triple.cpp.s

CMakeFiles/ray.dir/src/triple.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/triple.cpp.o.requires

CMakeFiles/ray.dir/src/triple.cpp.o.provides: CMakeFiles/ray.dir/src/triple.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/triple.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/triple.cpp.o.provides

CMakeFiles/ray.dir/src/triple.cpp.o.provides.build: CMakeFiles/ray.dir/src/triple.cpp.o


CMakeFiles/ray.dir/src/shapes/solvers.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/shapes/solvers.cpp.o: ../src/shapes/solvers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ray.dir/src/shapes/solvers.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/shapes/solvers.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/shapes/solvers.cpp

CMakeFiles/ray.dir/src/shapes/solvers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/shapes/solvers.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/shapes/solvers.cpp > CMakeFiles/ray.dir/src/shapes/solvers.cpp.i

CMakeFiles/ray.dir/src/shapes/solvers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/shapes/solvers.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/shapes/solvers.cpp -o CMakeFiles/ray.dir/src/shapes/solvers.cpp.s

CMakeFiles/ray.dir/src/shapes/solvers.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/shapes/solvers.cpp.o.requires

CMakeFiles/ray.dir/src/shapes/solvers.cpp.o.provides: CMakeFiles/ray.dir/src/shapes/solvers.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/shapes/solvers.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/shapes/solvers.cpp.o.provides

CMakeFiles/ray.dir/src/shapes/solvers.cpp.o.provides.build: CMakeFiles/ray.dir/src/shapes/solvers.cpp.o


CMakeFiles/ray.dir/src/shapes/quad.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/shapes/quad.cpp.o: ../src/shapes/quad.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ray.dir/src/shapes/quad.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/shapes/quad.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/shapes/quad.cpp

CMakeFiles/ray.dir/src/shapes/quad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/shapes/quad.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/shapes/quad.cpp > CMakeFiles/ray.dir/src/shapes/quad.cpp.i

CMakeFiles/ray.dir/src/shapes/quad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/shapes/quad.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/shapes/quad.cpp -o CMakeFiles/ray.dir/src/shapes/quad.cpp.s

CMakeFiles/ray.dir/src/shapes/quad.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/shapes/quad.cpp.o.requires

CMakeFiles/ray.dir/src/shapes/quad.cpp.o.provides: CMakeFiles/ray.dir/src/shapes/quad.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/shapes/quad.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/shapes/quad.cpp.o.provides

CMakeFiles/ray.dir/src/shapes/quad.cpp.o.provides.build: CMakeFiles/ray.dir/src/shapes/quad.cpp.o


CMakeFiles/ray.dir/src/shapes/sphere.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/shapes/sphere.cpp.o: ../src/shapes/sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ray.dir/src/shapes/sphere.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/shapes/sphere.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/shapes/sphere.cpp

CMakeFiles/ray.dir/src/shapes/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/shapes/sphere.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/shapes/sphere.cpp > CMakeFiles/ray.dir/src/shapes/sphere.cpp.i

CMakeFiles/ray.dir/src/shapes/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/shapes/sphere.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/shapes/sphere.cpp -o CMakeFiles/ray.dir/src/shapes/sphere.cpp.s

CMakeFiles/ray.dir/src/shapes/sphere.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/shapes/sphere.cpp.o.requires

CMakeFiles/ray.dir/src/shapes/sphere.cpp.o.provides: CMakeFiles/ray.dir/src/shapes/sphere.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/shapes/sphere.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/shapes/sphere.cpp.o.provides

CMakeFiles/ray.dir/src/shapes/sphere.cpp.o.provides.build: CMakeFiles/ray.dir/src/shapes/sphere.cpp.o


CMakeFiles/ray.dir/src/main.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ray.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/main.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/main.cpp

CMakeFiles/ray.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/main.cpp > CMakeFiles/ray.dir/src/main.cpp.i

CMakeFiles/ray.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/main.cpp -o CMakeFiles/ray.dir/src/main.cpp.s

CMakeFiles/ray.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/main.cpp.o.requires

CMakeFiles/ray.dir/src/main.cpp.o.provides: CMakeFiles/ray.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/main.cpp.o.provides

CMakeFiles/ray.dir/src/main.cpp.o.provides.build: CMakeFiles/ray.dir/src/main.cpp.o


CMakeFiles/ray.dir/src/lode/lodepng.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/lode/lodepng.cpp.o: ../src/lode/lodepng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ray.dir/src/lode/lodepng.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/lode/lodepng.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/lode/lodepng.cpp

CMakeFiles/ray.dir/src/lode/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/lode/lodepng.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/lode/lodepng.cpp > CMakeFiles/ray.dir/src/lode/lodepng.cpp.i

CMakeFiles/ray.dir/src/lode/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/lode/lodepng.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/lode/lodepng.cpp -o CMakeFiles/ray.dir/src/lode/lodepng.cpp.s

CMakeFiles/ray.dir/src/lode/lodepng.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/lode/lodepng.cpp.o.requires

CMakeFiles/ray.dir/src/lode/lodepng.cpp.o.provides: CMakeFiles/ray.dir/src/lode/lodepng.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/lode/lodepng.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/lode/lodepng.cpp.o.provides

CMakeFiles/ray.dir/src/lode/lodepng.cpp.o.provides.build: CMakeFiles/ray.dir/src/lode/lodepng.cpp.o


CMakeFiles/ray.dir/src/image.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/image.cpp.o: ../src/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ray.dir/src/image.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/image.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/image.cpp

CMakeFiles/ray.dir/src/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/image.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/image.cpp > CMakeFiles/ray.dir/src/image.cpp.i

CMakeFiles/ray.dir/src/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/image.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/image.cpp -o CMakeFiles/ray.dir/src/image.cpp.s

CMakeFiles/ray.dir/src/image.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/image.cpp.o.requires

CMakeFiles/ray.dir/src/image.cpp.o.provides: CMakeFiles/ray.dir/src/image.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/image.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/image.cpp.o.provides

CMakeFiles/ray.dir/src/image.cpp.o.provides.build: CMakeFiles/ray.dir/src/image.cpp.o


CMakeFiles/ray.dir/src/scene.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/scene.cpp.o: ../src/scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ray.dir/src/scene.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/scene.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/scene.cpp

CMakeFiles/ray.dir/src/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/scene.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/scene.cpp > CMakeFiles/ray.dir/src/scene.cpp.i

CMakeFiles/ray.dir/src/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/scene.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/scene.cpp -o CMakeFiles/ray.dir/src/scene.cpp.s

CMakeFiles/ray.dir/src/scene.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/scene.cpp.o.requires

CMakeFiles/ray.dir/src/scene.cpp.o.provides: CMakeFiles/ray.dir/src/scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/scene.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/scene.cpp.o.provides

CMakeFiles/ray.dir/src/scene.cpp.o.provides.build: CMakeFiles/ray.dir/src/scene.cpp.o


CMakeFiles/ray.dir/src/raytracer.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/src/raytracer.cpp.o: ../src/raytracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ray.dir/src/raytracer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/src/raytracer.cpp.o -c /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/raytracer.cpp

CMakeFiles/ray.dir/src/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/src/raytracer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/raytracer.cpp > CMakeFiles/ray.dir/src/raytracer.cpp.i

CMakeFiles/ray.dir/src/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/src/raytracer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/src/raytracer.cpp -o CMakeFiles/ray.dir/src/raytracer.cpp.s

CMakeFiles/ray.dir/src/raytracer.cpp.o.requires:

.PHONY : CMakeFiles/ray.dir/src/raytracer.cpp.o.requires

CMakeFiles/ray.dir/src/raytracer.cpp.o.provides: CMakeFiles/ray.dir/src/raytracer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/src/raytracer.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/src/raytracer.cpp.o.provides

CMakeFiles/ray.dir/src/raytracer.cpp.o.provides.build: CMakeFiles/ray.dir/src/raytracer.cpp.o


# Object files for target ray
ray_OBJECTS = \
"CMakeFiles/ray.dir/src/objloader.cpp.o" \
"CMakeFiles/ray.dir/src/triple.cpp.o" \
"CMakeFiles/ray.dir/src/shapes/solvers.cpp.o" \
"CMakeFiles/ray.dir/src/shapes/quad.cpp.o" \
"CMakeFiles/ray.dir/src/shapes/sphere.cpp.o" \
"CMakeFiles/ray.dir/src/main.cpp.o" \
"CMakeFiles/ray.dir/src/lode/lodepng.cpp.o" \
"CMakeFiles/ray.dir/src/image.cpp.o" \
"CMakeFiles/ray.dir/src/scene.cpp.o" \
"CMakeFiles/ray.dir/src/raytracer.cpp.o"

# External object files for target ray
ray_EXTERNAL_OBJECTS =

ray: CMakeFiles/ray.dir/src/objloader.cpp.o
ray: CMakeFiles/ray.dir/src/triple.cpp.o
ray: CMakeFiles/ray.dir/src/shapes/solvers.cpp.o
ray: CMakeFiles/ray.dir/src/shapes/quad.cpp.o
ray: CMakeFiles/ray.dir/src/shapes/sphere.cpp.o
ray: CMakeFiles/ray.dir/src/main.cpp.o
ray: CMakeFiles/ray.dir/src/lode/lodepng.cpp.o
ray: CMakeFiles/ray.dir/src/image.cpp.o
ray: CMakeFiles/ray.dir/src/scene.cpp.o
ray: CMakeFiles/ray.dir/src/raytracer.cpp.o
ray: CMakeFiles/ray.dir/build.make
ray: CMakeFiles/ray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable ray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray.dir/build: ray

.PHONY : CMakeFiles/ray.dir/build

CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/objloader.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/triple.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/shapes/solvers.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/shapes/quad.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/shapes/sphere.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/main.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/lode/lodepng.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/image.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/scene.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/src/raytracer.cpp.o.requires

.PHONY : CMakeFiles/ray.dir/requires

CMakeFiles/ray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ray.dir/clean

CMakeFiles/ray.dir/depend:
	cd /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2 /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2 /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build /home/s3475344/Desktop/cg/new/a1/Computer-Graphics/RayTracer_2/build/CMakeFiles/ray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ray.dir/depend

