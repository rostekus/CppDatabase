add_library(db STATIC src/db.cpp)
target_include_directories(db PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
