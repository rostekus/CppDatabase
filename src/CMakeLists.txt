cmake_minimum_required(VERSION 3.12)

project(Database VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(db Database/IDatabase.cpp
        Database/IDatabase.hpp
        Database/ExtDatabase.cpp
        Database/ExtDatabase.hpp
        Network/HTTPServer.hpp
        Network/HTTPServer.cpp
		Network/Types/Request.hpp
		Network/Types/Response.hpp
		Network/RequestParser.cpp
		Network/RequestParser.hpp
		Network/Router.cpp
		Network/Router.hpp
		Network/HTTPServer.cpp
		Network/HTTPServer.hpp
		Network/API/IHandler.hpp
		Network/API/IRequestParser.hpp
		Network/API/IRouter.hpp
		Network/Handlers.cpp
		Network/Handlers.hpp
		Network/ResponseSerializer.hpp
		Network/ResponseSerializer.cpp
		)

add_executable(Database main.cpp)
target_link_libraries(Database PUBLIC db)

