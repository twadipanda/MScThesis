#include<vector>
#include<iostream>
#include <chrono>
#include "ga.hpp"
#include "benchmark.hpp"
#include "selectionHeuristic.hpp"
#include "crossoverHeuristic.hpp"
#include "mutationHeuristic.hpp"

/**
 * @brief Main function to execute the Genetic Algorithm and measure its performance.
 *
 * Initializes a population of 10,000 individuals with 100 genes each, runs the GA for 10,000 iterations
 * with a tournament selection size of 2 and 2% elitism, and reports the top fitness and execution time.
 *
 * @return int Exit status (0 for success).
 */
int main() {
  Bench::Sphere benchmark;                     ///< Sphere function as the fitness benchmark.
  Heuristcs::Tournament selectionHeuristic;    ///< Tournament selection heuristic.
  Heuristcs::SimulatedBinary crossoverHeuristic; ///< Simulated Binary Crossover heuristic.
  Heuristcs::Gausian mutationHeuristic;        ///< Gaussian mutation heuristic.
  std::vector<std::pair<int, double>> fitness; ///< Fitness values with indices.
  double selectionCriteria = 2;                ///< Tournament selection size.
  double percentageElite = 0.02;               ///< Percentage of population preserved as elites (2%).
  
  std::cout << "Starting" << "\n";
  auto start = std::chrono::high_resolution_clock::now();
  
  std::vector<std::vector<double>> population = EA::GA().initialize(10000, 100);
  for (int i = 0; i < 10000; i++) {
    population = EA::GA().iterate(population, selectionCriteria, percentageElite, selectionHeuristic, crossoverHeuristic, mutationHeuristic, benchmark);
    fitness = EA::GA().evaluate(population, benchmark);
    std::cout << "Top Fitness: " << fitness[0].second << " Top Index: " << fitness[0].first << "\n";
    std::cout << "Top Individual: " << population[0][0] << population[0][1] << population[0][2] << "\n";
  }
  
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  
  std::cout << "Finished!" << "\n";
  std::cout << "Top Fitness: " << fitness[0].second << " Top Index: " << fitness[0].first << "\n";
  std::cout << "Top Individual: " << population[0][0] << population[0][1] << population[0][2] << "\n";
  std::cout << "Execution time: " << elapsed.count() << " seconds\n";
  
  return 0;
}
