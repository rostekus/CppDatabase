cmake_minimum_required(VERSION 3.12)

add_executable(db-tests
    src/basic-tests.cpp
    include/catch.hpp
    include/tests.hpp
)

target_include_directories(db-tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(db-tests PRIVATE db)

target_compile_features(db-tests PRIVATE cxx_std_17)
