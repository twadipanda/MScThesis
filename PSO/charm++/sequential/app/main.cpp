#include <iostream>
#include <chrono>
#include "pso.hpp"
#include "benchmark.hpp"

int main() {
  Bench::Sphere sphere;
  SwarmOptimizer::PSO pso(sphere, 10000, 100, 10000, 0.5, 1.0, 2.0);
  auto start = std::chrono::high_resolution_clock::now();
  pso.iterate();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Global best fitness: " << pso.getGlobalBestFitness() << "\n";
  std::cout << "Execution time: " << elapsed.count() << " seconds\n";
  return 0;
}