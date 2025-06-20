#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <random>
#include "selectionHeuristic.hpp"

/**
 * @brief Namespace for heuristic operators in the Genetic Algorithm.
 */
namespace Heuristcs {
  /**
   * @brief Performs tournament selection on a population.
   *
   * Selects individuals by holding tournaments of specified size, preserving elites first.
   *
   * @param population The current population.
   * @param fitness Fitness values paired with indices.
   * @param params Vector containing elite percentage (first) and tournament size (second).
   * @return std::vector<std::vector<double>> The selected population.
   * @throw std::invalid_argument If params lacks elite percentage or tournament size.
   */
  std::vector<std::vector<double>> Tournament::select(std::vector<std::vector<double>>& population, std::vector<std::pair<int, double>>& fitness, std::vector<double>& params) const {
    if (params.size() < 2) {
      throw std::invalid_argument("Eliteness and Selection Criteria not provided for tournament selection...");
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<std::vector<double>> newPopulation;
    int size = population.size();
    std::uniform_int_distribution<> dis(0, size - 1);
    int elites = std::floor(size*params[0]);
    int selectionCriteria = params[1];
    int randomInt = size;
    int temp = 0;
    newPopulation.reserve(size);
    std::sort(fitness.begin(), fitness.end(), [](const auto& a, const auto& b) {
      return a.second < b.second;
    });
    for (int i = 0; i < elites; i++) {
      newPopulation.push_back(population[fitness[i].first]);
    }
    for (int i = 0; i < size - elites; i++) {
      randomInt = dis(gen);
      for (int j = 0; j < selectionCriteria; j++) {
        temp = dis(gen);
        if (randomInt > temp) {
          randomInt = temp;
        }
      }
      newPopulation.push_back(population[fitness[randomInt].first]);
    }
    return std::move(newPopulation);
  }
}