cmake_minimum_required(VERSION 3.10)
project("VoxelVeiwer" C)

add_executable(VoxelVeiwer src/Main.c
				src/Cube.c
				src/Camera.c
				src/GLUtils.c
				src/Init.c
				src/MatrixManipulation.c
				src/TrigUtils.c
				src/Window.c
				src/GLUTFunctions.c
				src/Render.c
				src/VoxelArray.c)

target_compile_options(VoxelVeiwer PRIVATE "-Wall" "-g" "-O9")
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries(VoxelVeiwer ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES} m)
