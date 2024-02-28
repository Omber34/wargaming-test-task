cmake_minimum_required(VERSION 3.23)
project(wargaming_test_task)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("3rd_party")

add_executable(wargaming_test_task main.cpp utility.cpp)
target_link_libraries(wargaming_test_task md5support)
target_include_directories(wargaming_test_task PRIVATE 3rd_party)

