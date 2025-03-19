cmake_minimum_required(VERSION 3.15...3.22)

project(
  kmeans
  VERSION 1.0
  LANGUAGES CXX)

add_executable(app app/main.cpp)
add_library(read STATIC src/read.cpp include/read.hpp)
add_library(distanceMetrics STATIC src/distanceMetrics.cpp include/distanceMetrics.hpp)
add_library(kmeans STATIC src/kmeans.cpp include/kmeans.hpp)
target_include_directories(read PUBLIC include)
target_include_directories(distanceMetrics PUBLIC include)
target_include_directories(kmeans PUBLIC include)
target_link_libraries(app PUBLIC read)
target_link_libraries(app PUBLIC distanceMetrics)
target_link_libraries(app PUBLIC kmeans)
target_compile_features(read PUBLIC cxx_std_20)
target_compile_features(distanceMetrics PUBLIC cxx_std_20)
target_compile_features(kmeans PUBLIC cxx_std_20)