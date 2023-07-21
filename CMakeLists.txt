cmake_minimum_required(VERSION 3.12)

project(Database VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
enable_testing()

add_subdirectory("src")
#add_subdirectory("tests")

#add_test(NAME tests COMMAND example)
