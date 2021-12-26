cmake_minimum_required(VERSION 3.20)
project(lab6)

set(CMAKE_CXX_STANDARD 23)


add_executable(lab6
  figure.h
  main.cpp
  point.h point.cpp
  square.h square.cpp
  tallocation_block.cpp tallocation_block.h 
  titerator.h
  tqueue.cpp tqueue.h 
  tqueue.item.cpp tqueue_item.h
)