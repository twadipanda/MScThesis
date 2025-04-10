#include <vector>
#include <random>
#include <cmath>
#include <iostream>
#include "ga.hpp"

/**
 * @brief Namespace for Evolutionary Algorithm (EA) implementations.
 */
namespace EA {
  /**
   * @brief Initializes a population for the GA.
   *
   * Creates a population of individuals with random genes in the range [-1, 1].
   *
   * @param populationSize Number of individuals in the population.
   * @param individualSize Number of genes per individual.
   * @return std::vector<std::vector<double>> The initialized population.
   */
  std::vector<std::vector<double>> GA::initialize(int populationSize, int individualSize) {
    std::vector<std::vector<double>> population;
    std::vector<double> individual;
    population.reserve(populationSize);
    individual.reserve(individualSize);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1, 1);
    for (int i = 0; i < populationSize; i++) {
      individual.clear();
      for (int j = 0; j < individualSize; j++) {
        individual.push_back(dis(gen));
      }
      population.push_back(individual);
    }
    return std::move(population);
  }

  /**
   * @brief Evaluates the fitness of a population using a benchmark function.
   *
   * Computes fitness for each individual and pairs it with its index.
   *
   * @param population The population to evaluate.
   * @param benchmark The benchmark function to apply.
   * @return std::vector<std::pair<int, double>> List of (index, fitness) pairs.
   */
  std::vector<std::pair<int, double>> GA::evaluate(std::vector<std::vector<double>>& population, const Bench::BenchMark& benchmark) {
    std::vector<std::pair<int, double>> fitness;
    fitness.reserve(population.size());
    for (int i = 0; i < population.size(); i++) {
      fitness.push_back(std::make_pair(i, benchmark.fitness(population[i])));
    }
    return std::move(fitness);
  }

  /**
   * @brief Performs one iteration of the GA.
   *
   * Evolves the population using selection, crossover, and mutation, preserving elites.
   *
   * @param population The current population.
   * @param retention Tournament selection size.
   * @param elite Percentage of population to preserve as elites.
   * @param selectionHeuristic Selection heuristic (e.g., tournament).
   * @param crossoverHeuristic Crossover heuristic (e.g., SBX).
   * @param mutationHeuristic Mutation heuristic (e.g., Gaussian).
   * @param benchmark Fitness benchmark function.
   * @return std::vector<std::vector<double>> The new population after iteration.
   */
  std::vector<std::vector<double>> GA::iterate(std::vector<std::vector<double>>& population, double retention, double elite,
    const Heuristcs::SelectionHeuristic& selectionHeuristic, const Heuristcs::CrossoverHeuristic& crossoverHeuristic, const Heuristcs::MutationHeuristic& mutationHeuristic, const Bench::BenchMark& benchmark) {
      std::vector<std::pair<int, double>> fitness = evaluate(population, benchmark);
      std::vector<double> params = {elite, retention};
      std::vector<double> distributionIndex = {2};
      std::vector<std::vector<double>> selectedPopulation = selectionHeuristic.select(population, fitness, params);
      std::vector<std::vector<double>> offsprings;
      for (int i = std::floor(population.size()*elite); i < population.size() - 1; i+=2) {
        offsprings = crossoverHeuristic.crossover(selectedPopulation[i], selectedPopulation[i+1], distributionIndex);
        selectedPopulation[i] = mutationHeuristic.mutate(offsprings[0]);
        selectedPopulation[i+1] = mutationHeuristic.mutate(offsprings[1]);
      }
      return std::move(selectedPopulation);
  }
}