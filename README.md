[![Run GTests](https://github.com/rostekus/db/actions/workflows/gtest.yaml/badge.svg?branch=main)](https://github.com/rostekus/db/actions/workflows/gtest.yaml)

# Database Key-Value Implementation and HTTP Server

This repository contains a simple implementation of a key-value database and a HTTP server built from scratch using UNIX sockets. The project includes libraries in Python and Golang for interacting with the HTTP server.

## Table of Contents

## Table of Contents

- [Introduction](#introduction)
   - [Functionality](#functionality)
- [Building the Repository](#building-the-repository)
  - [Prerequisites](#prerequisites)
  - [Build Steps](#build-steps)
- [HTTP Server (C++)](#http-server-c)
   - [Further Development](#further-development)
- [Python Library (python_db_lib)](#python-library-python_db_lib)
- [Golang Library (go_db_lib)](#golang-library-go_db_lib)
- [Presentation Layer](#presentation-layer)

## Introduction

### Functionality

#### 1. Set Key-Value Pair
To store a key-value pair in the database, you can send an HTTP POST request. The server will store the provided key-value pair in the database.

#### 2. Get Value by Key:
To retrieve the value associated with a specific key, you can send an HTTP GET. The server will fetch the value from the database and return it in the response.

#### 3. Get All Key-Value Pairs:
To retrieve all key-value pairs stored in the database, you can send an HTTP GET request to the server without any parameters. The server will fetch all key-value pairs from the database and return them in the response.

#### Example:
Request
```bash
curl -X POST -H "Content-Type: application/json" -d '{"key":"example_key","value":"example_value"}' http://localhost:8080/keyvalue
```
Response Body:
```bash
{
"key": "SET"
}
```

## Building the Repository

## Prerequisites
- C++ compiler that supports C++17 (e.g., GCC or Clang)
- CMake (version 3.0 or higher)
- Gtest Library

## Build Steps

1. Clone the repository to your local machine.

2. Navigate to the root directory of the cloned repository.

3. **Building the C++ Key-Value Database Library:**

   - Create a build directory and navigate into it:
     ```bash
     mkdir build
     cd build
     ```

   - Generate the build files using CMake:
     ```bash
     cmake ..
     ```

   - Build the project:
     ```bash
     cmake --build .
     ```


The `src` directory contains the C++ implementation of the key-value database library. The relevant files are:

- `Database/ExtDatabase.cpp` and `Database/ExtDatabase.hpp`: Implementation of an extended database class that handles key-value pairs.
- `Database/IDatabase.cpp` and `Database/IDatabase.hpp`: Interface for the database to ensure extensibility.
- `Network/API/IHandler.hpp`, `Network/API/IRequestParser.hpp`, and `Network/API/IRouter.hpp`: Interfaces for building the HTTP server.

## HTTP Server (C++)

The HTTP server is designed from scratch and located in the `src/Network` directory. The files related to the server include:

- `HTTPServer.cpp` and `HTTPServer.hpp`: Implementation of the HTTP server class.
- `RequestParser.cpp` and `RequestParser.hpp`: Parsing HTTP requests.
- `ResponseSerializer.cpp` and `ResponseSerializer.hpp`: Serializing HTTP responses.
- `Router.cpp` and `Router.hpp`: Handling routing logic for different HTTP requests.
- `Handlers.cpp` and `Handlers.hpp`: Implementing various request handlers.

### Further Development
If you want add your own handler all you need to do is implement IHandler interface:
```cpp
class IHandler {
 public:
  virtual Response handle(Request req) = 0;
};
```
And then register it in router:
```cpp
router->registerRoute("/path", httpserver::Method::GET,
                        std::move(yourHandler));
```

## Python Library (python_db_lib)

The `python_db_lib` directory contains a Python library to interact with the HTTP server. Key files in this directory are:

- `python_db_lib/database.py`: Python library implementation for interacting with the HTTP server.
- `examples/example.py`: Example usage of the Python library.

## Golang Library (go_db_lib)

The `go_db_lib` directory contains a Golang library for communication with the HTTP server. The essential file here is:

- `go_db_lib/dblib/go-lib-db.go`: Golang library implementation for interacting with the HTTP server.

## Presentation Layer

The `presentation` directory contains the presentation layer for the application.

### Backend

The backend is implemented in Python using FastAPI and includes the following components:

- `presentation/backend/app`: The main application directory containing the backend logic.
- `presentation/backend/app/db_lib/dblib.py`: Python module to interact with the HTTP server using the Python library.
- `presentation/backend/app/routes/db_routes.py`: Defines routes and request handlers for database-related actions.
- `presentation/backend/app/services/db_service.py`: Implements services for handling database operations.
- `presentation/backend/main.py`: Entry point for the backend application.

## Contribution

Contributions to this repository are welcome. If you find any issues or have improvements to suggest, feel free to open a pull request.

---

Please note that this README provides an overview of the repository structure and its contents. For detailed instructions on building, running, and using the components, refer to the individual directories and files within the repository.
