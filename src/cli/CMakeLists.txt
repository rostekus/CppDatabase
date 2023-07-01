cmake_minimum_required(VERSION 3.12)

add_executable(db-cli main.cpp)

target_link_libraries(db-cli PRIVATE db)

target_compile_features(db-cli PRIVATE cxx_std_17)

include_directories(${db_SOURCE_DIR})

install(TARGETS db-cli
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} 
)
