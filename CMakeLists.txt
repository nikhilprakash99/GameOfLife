cmake_minimum_required(VERSION 3.16.3)

project (GameOfLife)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

include_directories(
	"include"
)

add_executable(${PROJECT_NAME} src/main.cpp)