cmake_minimum_required(VERSION 3.5)
project(pendulum)

find_package(OpenGL)
find_package(GLUT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lglut -lGL -lGLU")

set(SOURCE_FILES main.cpp)
add_executable(pendulum ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} ${GLUT_LIBRARIES} )