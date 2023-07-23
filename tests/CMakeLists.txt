cmake_minimum_required(VERSION 3.12)

project(tests)
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(Tests
	parser-tests.cpp
	serializer-tests.cpp
	db-tests.cpp)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../src)
target_link_libraries(Tests PUBLIC db
	gtest_main)
