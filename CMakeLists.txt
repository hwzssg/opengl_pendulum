cmake_minimum_required(VERSION 3.5)
project(pendulum)

find_package(OpenGL)
find_package(GLUT)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp draw.cpp draw.h)
add_executable(pendulum ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} ${GLUT_LIBRARIES} )