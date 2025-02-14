cmake_minimum_required(VERSION 3.15...3.22)

project(
  kmeans
  VERSION 1.0
  LANGUAGES CXX)

add_executable(kmeans app/main.cpp)
add_library(read STATIC src/read.cpp include/read.hpp)
target_include_directories(read PUBLIC include)
target_link_libraries(kmeans PUBLIC read)
target_compile_features(read PUBLIC cxx_std_20)