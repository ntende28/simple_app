cmake_minimum_required(VERSION 3.16.3)

project(student_app)

set(CMAKE_CXX_STANDARD 14)

#adding header files
include_directories(${CMAKE_SOURCE_DIR}/include)


#adding an executable
add_executable(${PROJECT_NAME} main.cpp src/student.cpp src/datastore.cpp)

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)