cmake_minimum_required(VERSION 3.10.2)

project(Folder1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Folder1 main.cpp)

install(TARGETS Folder1 DESTINATION bin)
install(FILES main.cpp DESTINATION src)
