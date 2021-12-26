cmake_minimum_required(VERSION 3.20)
project(lab4)

set(CMAKE_CXX_STANDARD 14)


add_executable(lab4
  figure.h
  main.cpp
  point.h point.cpp
  square.h square.cpp
  tqueue.h tqueue.cpp
  tqueue_item.h tqueue.item.cpp
)
