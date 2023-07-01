cmake_minimum_required(VERSION 3.20)

project(Database 
            VERSION 1.0
            DESCRIPTION "Simple Database implementation in C++")

add_subdirectory(src/cli)

add_subdirectory(src/db)

add_subdirectory(tests)
