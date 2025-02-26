#include<vector>
#include<iostream>
#include <chrono>
#include "ga.hpp"
#include "benchmark.hpp"
#include "selectionHeuristic.hpp"
#include "crossoverHeuristic.hpp"
#include "mutationHeuristic.hpp"

int main() {
  Bench::Sphere benchmark;
  Heuristcs::Tournament selectionHeuristic;
  Heuristcs::SimulatedBinary crossoverHeuristic;
  Heuristcs::Gausian mutationHeuristic;
  std::vector<std::pair<int, double>> fitness;
  double selectionCriteria = 10;
  double percentageElite = 0.05;
  std::cout << "Starting" << "\n";
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<std::vector<double>> population = EA::GA().initialize(10000, 1000);
  for (int i = 0; i < 10000; i++) {
    population = EA::GA().iterate(population, selectionCriteria, percentageElite, selectionHeuristic, crossoverHeuristic, mutationHeuristic, benchmark);
    fitness = EA::GA().evaluate(population, benchmark);
    // std::cout << "Top Fitness: " << fitness[0].second << " Top Index: " << fitness[0].first << "\n";
    // std::cout << "Top Individual: " << population[0][0] << population[0][1] << population[0][2] << "\n";
  }
  // for (const auto& pair : fitness) {
  //   std::cout << "Top Fitness: " << pair.second << "\n";
  // }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Finished!" << "\n";
  // std::cout << "Took " << iterations << " iterations!\n";
  std::cout << "Top Fitness: " << fitness[0].second << " Top Index: " << fitness[0].first << "\n";
  std::cout << "Top Individual: " << population[0][0] << population[0][1] << population[0][2] << "\n";
  std::cout << "Execution time: " << elapsed.count() << " seconds\n";
};