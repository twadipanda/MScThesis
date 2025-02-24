#include <vector>
#include <random>
#include "ga.hpp"

namespace EA {
  std::vector<std::vector<double>> GA::initialize(int populationSize, int individualSize) {
    std::vector<std::vector<double>> population;
    std::vector<double> individual;
    population.reserve(populationSize);
    individual.reserve(individualSize);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < populationSize; i++) {
      individual.clear();
      for (int j = 0; j < individualSize; j++) {
        individual.push_back(dis(gen));
      }
      population.push_back(individual);
    }
    return std::move(population);
  }

  double evaluate(std::vector<double>& individual, BenchMark benchmark) {
    return benchmark.fitness(individual);
  }

  std::vector<std::vector<double>> selection(std::vector<std::vector<double>>&,
  SelectionHeuristic, double retention, double elite) {
    
  }
  std::vector<double> crossover(CrossoverHeuristic, std::vector<double>&, std::vector<double>&);
  std::vector<double> mutation(MutationHeuristic, std::vector<double>&, std::vector<double>&);
}