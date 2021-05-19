cmake_minimum_required(VERSION 3.19)
project(splay2)

set(CMAKE_CXX_STANDARD 14)

add_executable(splay2 main.cpp SplayTree.cpp SplayTree.h SplaySet.cpp SplaySet.h splay_iterator.h TreeTraversal.cpp TreeTraversal.h)