cmake_minimum_required(VERSION 3.12)

project(Database VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

add_library(db Database/IDatabase.cpp
        Database/IDatabase.hpp
        Database/ExtDatabase.cpp
        Database/ExtDatabase.hpp
        Network/HTTPServer.hpp
        Network/HTTPServer.cpp
        Log/Logger.cpp
        Log/Logger.hpp
		Network/Types/Request.cpp
		Network/Types/Request.hpp
		Network/BodyParser.cpp
		Network/BodyParser.hpp
		)

add_executable(Database main.cpp)
target_link_libraries(Database PUBLIC db)


target_link_libraries(Database PRIVATE spdlog::spdlog)
target_link_libraries(Database PRIVATE spdlog::spdlog_header_only)
