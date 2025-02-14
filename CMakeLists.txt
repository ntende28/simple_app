cmake_minimum_required(VERSION 3.22.1)

project(student_app)

set(CMAKE_CXX_STANDARD 14)

#adding header files
include_directories(${CMAKE_SOURCE_DIR}/include)


#adding an executable
add_executable(${PROJECT_NAME} main.cpp src/student.cpp src/datastore.cpp)

