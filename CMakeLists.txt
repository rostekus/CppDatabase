cmake_minimum_required(VERSION 3.12)

project(Database VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()


add_executable(Database src/main.cpp
        src/Database/IDatabase.cpp
        src/Database/IDatabase.hpp
        src/Database/ExtDatabase.cpp
        src/Database/ExtDatabase.hpp
        src/Network/HTTPServer.hpp
        src/Network/HTTPServer.cpp
        src/Log/Logger.cpp
        src/Log/Logger.hpp)


target_link_libraries(Database PRIVATE spdlog::spdlog)
target_link_libraries(Database PRIVATE spdlog::spdlog_header_only)
