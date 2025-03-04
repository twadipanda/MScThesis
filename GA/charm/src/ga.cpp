#include <vector>
#include <random>
#include <cmath>
#include <iostream>
#include "ga.decl.h"
#include "ga.h"
#include "main.decl.h"
#include "benchmark.hpp"
#include "selectionHeuristic.hpp"
#include "crossoverHeuristic.hpp"
#include "mutationHeuristic.hpp"

extern CProxy_Main mainProxy;
extern /* readonly */ int numElements;

namespace EA {
  GA::GA(CkMigrateMessage *msg) {};

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

  std::vector<std::pair<int, double>> GA::evaluate(std::vector<std::vector<double>>& population, const Bench::BenchMark& benchmark) {
    std::vector<std::pair<int, double>> fitness;
    fitness.reserve(population.size());
    for (int i = 0; i < population.size(); i++) {
      fitness.push_back(std::make_pair(i, benchmark.fitness(population[i])));
    }
    return std::move(fitness);
  }

  void GA::iterate(std::vector<std::vector<double>>& population, double retention, double elite,
    const SelectionHeuristic& selectionHeuristic, const CrossoverHeuristic& crossoverHeuristic,
    const MutationHeuristic& mutationHeuristic, const Bench::BenchMark& benchmark) {
      std::vector<std::pair<int, double>> fitness = evaluate(population, benchmark);
      std::vector<double> params = {elite, retention};
      std::vector<double> distributionIndex = {2};
      std::vector<std::vector<double>> selectedPopulation = selectionHeuristic.select(population, fitness, params);
      int chareIndex = 1;
      std::vector<std::vector<double>> elites;
      for (int i = 0; i < std::floor(size*elite); i++) {
        elites.push_back(selectedPopulation[i]);
      }
      mainProxy.recieve(elites);
      for (int i = std::floor(population.size()*elite); i < population.size() - 1; i+=2) {
        if (chareIndex == (numElements - 1)) {
          chareIndex = 1;
        }
        thisProxy[chareIndex].reproduce(selectedPopulation[i], selectedPopulation[i+1], distributionIndex, crossoverHeuristic, mutationHeuristic);
        chareIndex++;
      }
      mainProxy.finished();
  }

  void GA::reproduce(std::vector<double>& par1, std::vector<double>& par2, std::vector<double>& distributionIndex,
    const CrossoverHeuristic& crossoverHeuristic, const MutationHeuristic& mutationHeuristic) {
    std::vector<std::vector<double>> offsprings = crossoverHeuristic.crossover(par1, par2, distributionIndex);
    offsprings[0] = mutationHeuristic.mutate(offsprings[0]);
    offsprings[1] = mutationHeuristic.mutate(offsprings[1]);
    mainProxy.recieve(offsprings);
  }
}

#include "ga.def.h"