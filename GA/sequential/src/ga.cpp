#include <vector>
#include <random>
#include <cmath>
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

  std::vector<std::pair<int, double>> GA::evaluate(std::vector<std::vector<double>>& population, const Bench::BenchMark& benchmark) {
    std::vector<std::pair<int, double>> fitness;
    fitness.reserve(population.size());
    for (int i = 0; i < population.size(); i++) {
      fitness.push_back(std::make_pair(i, benchmark.fitness(population[i])));
    }
    return std::move(fitness);
  }

  // std::vector<std::vector<double>> selection(std::vector<std::vector<double>>&,
  // SelectionHeuristic, double retention, double elite) {

  // }
  // std::vector<double> crossover(CrossoverHeuristic, std::vector<double>&, std::vector<double>&);
  // std::vector<double> mutation(MutationHeuristic, std::vector<double>&, std::vector<double>&);
  std::vector<std::vector<double>> GA::iterate(std::vector<std::vector<double>>& population, double retention, double elite,
    const Heuristcs::SelectionHeuristic& selectionHeuristic, const Heuristcs::CrossoverHeuristic& crossoverHeuristic, const Heuristcs::MutationHeuristic& mutationHeuristic, const Bench::BenchMark& benchmark) {
      std::vector<std::pair<int, double>> fitness = evaluate(population, benchmark);
      std::vector<double> params = {elite, retention};
      std::vector<double> distributionIndex = {5};
      std::vector<std::vector<double>> selectedPopulation = selectionHeuristic.select(population, fitness, params);
      std::vector<std::vector<double>> offsprings;
      for (int i = std::floor(population.size()*elite); i < population.size(); i+=2) {
        offsprings = crossoverHeuristic.crossover(selectedPopulation[i], selectedPopulation[i+1], distributionIndex);
        selectedPopulation[i] = mutationHeuristic.mutate(offsprings[0]);
        selectedPopulation[i+1] = mutationHeuristic.mutate(offsprings[1]);
      }
      return std::move(selectedPopulation);
  }
}