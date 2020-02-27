 cmake_minimum_required(VERSION 3.0)

 set(CMAKE_BUILD_TYPE Debug)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(lista)

add_executable(
  lista
  linkedList.hpp
  Node.hpp
  main.cpp
  Cola.hpp
  Cola.cpp
  Edge.hpp
  Graph.hpp
  Graph.cpp
  NodeGraph.hpp
  nodoCola.hpp
)
