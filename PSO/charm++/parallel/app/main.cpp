#include "main.decl.h"
#include "main.h"
#include <iostream>
#include <chrono>
#include "pso.hpp"
#include "benchmark.hpp"

/* readonly */ CProxy_Main mainProxy;

std::chrono::_V2::system_clock::time_point start;

// Entry point of Charm++ application
Main::Main(CkArgMsg* msg) {
  numElements = 100;
  mainProxy = thisProxy;
  Bench::Sphere sphere;
  SwarmOptimizer::PSO pso(sphere, 10000, 100, 10000, 0.5, 1.0, 2.0);
  start = std::chrono::high_resolution_clock::now();
  pso.iterate();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Global best fitness: " << pso.getGlobalBestFitness() << "\n";
  std::cout << "Execution time: " << elapsed.count() << " seconds\n";
  return 0;
}

#include "main.def.h"