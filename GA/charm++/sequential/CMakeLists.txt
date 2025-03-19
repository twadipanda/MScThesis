cmake_minimum_required(VERSION 3.15...3.22)

project(
  geneticAlgo
  VERSION 1.0
  LANGUAGES CXX)

add_executable(app app/main.cpp)
add_library(ga STATIC src/ga.cpp include/ga.hpp)
add_library(benchmark STATIC src/benchmark.cpp include/benchmark.hpp)
add_library(selectionHeuristic STATIC src/selectionHeuristic.cpp include/selectionHeuristic.hpp)
add_library(crossoverHeuristic STATIC src/crossoverHeuristic.cpp include/crossoverHeuristic.hpp)
add_library(mutationHeuristic STATIC src/mutationHeuristic.cpp include/mutationHeuristic.hpp)
target_include_directories(ga PUBLIC include)
target_include_directories(benchmark PUBLIC include)
target_include_directories(selectionHeuristic PUBLIC include)
target_include_directories(crossoverHeuristic PUBLIC include)
target_include_directories(mutationHeuristic PUBLIC include)
target_link_libraries(app PUBLIC ga)
target_link_libraries(app PUBLIC benchmark)
target_link_libraries(app PUBLIC selectionHeuristic)
target_link_libraries(app PUBLIC crossoverHeuristic)
target_link_libraries(app PUBLIC mutationHeuristic)
target_compile_features(ga PUBLIC cxx_std_20)
target_compile_features(benchmark PUBLIC cxx_std_20)
target_compile_features(selectionHeuristic PUBLIC cxx_std_20)
target_compile_features(crossoverHeuristic PUBLIC cxx_std_20)
target_compile_features(mutationHeuristic PUBLIC cxx_std_20)