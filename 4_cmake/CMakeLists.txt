cmake_minimum_required(VERSION 3.0)
project(SOLDIERFIRE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGES} -Wall" )
set(CMAKE_BUILD_TYPE Debug) 

include_directories(./include)
aux_source_directory(./src SRC)

add_executable(mycmake_exe main.cpp ${SRC})