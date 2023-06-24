cmake_minimum_required(VERSION 3.25)
project(csc212)

set(CMAKE_CXX_STANDARD 17)

add_executable(bag bag/bag_demo.cpp bag/bag.cpp)

add_executable(project1 project1/stats_exam.cpp project1/stats.h project1/stats.cpp)
add_executable(project2 project2/sequence_exam.cpp project2/sequence.h project2/sequence.cpp)
add_executable(project3 project3/sequence_exam.cpp project3/sequence.h project3/sequence.cpp)