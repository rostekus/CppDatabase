# Database Key-Value Implementation and HTTP Server

This repository contains a simple implementation of a key-value database and an HTTP server built from scratch using UNIX sockets. The project includes libraries in Python and Golang for interacting with the HTTP server.


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

## Python Library (python_db_lib)

The `python_db_lib` directory contains a Python library to interact with the HTTP server. Key files in this directory are:

- `python_db_lib/database.py`: Python library implementation for interacting with the HTTP server.
- `examples/example.py`: Example usage of the Python library.

## Golang Library (go_db_lib)

The `go_db_lib` directory contains a Golang library for communication with the HTTP server. The essential file here is:

- `go_db_lib/dblib/go-lib-db.go`: Golang library implementation for interacting with the HTTP server.

## Presentation Layer

The `presentation` directory contains the presentation layer for the application, including backend and frontend components.

### Backend

The backend is implemented in Python using FastAPI and includes the following components:

- `presentation/backend/app`: The main application directory containing the backend logic.
- `presentation/backend/app/db_lib/dblib.py`: Python module to interact with the HTTP server using the Python library.
- `presentation/backend/app/routes/db_routes.py`: Defines routes and request handlers for database-related actions.
- `presentation/backend/app/services/db_service.py`: Implements services for handling database operations.
- `presentation/backend/main.py`: Entry point for the backend application.

## Scripts

The `scripts` directory includes helper scripts for the project. For example, `format-all.sh` can be used for code formatting.

## Contribution

Contributions to this repository are welcome. If you find any issues or have improvements to suggest, feel free to open a pull request.

---

Please note that this README provides an overview of the repository structure and its contents. For detailed instructions on building, running, and using the components, refer to the individual directories and files within the repository.

