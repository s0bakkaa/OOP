cmake_minimum_required(VERSION 3.20)
project(lab5)

set(CMAKE_CXX_STANDARD 14)


add_executable(lab5
  figure.h
  main.cpp
  point.h point.cpp
  square.h square.cpp
  titerator.h
  tqueue.h tqueue.cpp
  tqueue_item.h tqueue.item.cpp
)
