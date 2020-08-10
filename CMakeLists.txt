cmake_minimum_required(VERSION 3.16.3)

project (GameOfLife)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

find_package(SFML 2.5.1 COMPONENTS graphics audio)
set(SFML_STATIC_LIBRARIES TRUE)

include_directories(
	"include"
)

file(GLOB SOURCES
	"src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)