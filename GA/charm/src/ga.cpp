#include <vector>
#include <random>
#include <cmath>
#include <iostream>
#include "ga.decl.h"
#include "main.decl.h"
#include "ga.h"
#include "benchmark.hpp"
#include "selectionHeuristic.hpp"
#include "crossoverHeuristic.hpp"
#include "mutationHeuristic.hpp"

extern CProxy_Main mainProxy;
extern /* readonly */ int numElements;

// namespace EA {
  GA::GA() {}
  GA::GA(CkMigrateMessage *msg) {}

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

  std::vector<std::pair<int, double>> GA::evaluate(const std::vector<std::vector<double>>& population) {
    std::vector<std::pair<int, double>> fitness;
    Bench::Sphere benchmark;
    fitness.reserve(population.size());
    for (int i = 0; i < population.size(); i++) {
      fitness.push_back(std::make_pair(i, benchmark.fitness(population[i])));
    }
    return std::move(fitness);
  }

  void GA::iterate(const std::vector<std::vector<double>>& population, double retention, double elite) {
    try {
      Tournament selectionHeuristic;
      std::vector<std::pair<int, double>> fitness = evaluate(population);
      std::vector<double> params = {elite, retention};
      std::vector<double> distributionIndex = {2};
      std::vector<std::vector<double>> selectedPopulation = selectionHeuristic.select(population, fitness, params);
      int chareIndex = 1;
      std::vector<std::vector<double>> elites;
      for (int i = 0; i < std::floor(population.size()*elite); i++) {
        elites.push_back(selectedPopulation[i]);
      }
      mainProxy.recieve(elites);
      for (int i = std::floor(population.size()*elite); i < population.size() - 1; i+=2) {
        if (chareIndex == (numElements - 1)) {
          chareIndex = 1;
        }
        thisProxy[chareIndex].reproduce(selectedPopulation[i], selectedPopulation[i+1], distributionIndex);
        chareIndex++;
      }
    } catch (const std::exception& e) {
      std::cerr << "Error iterating: " << e.what() << std::endl;
      CkExit();
    }
      // mainProxy.finished();
  }

  void GA::reproduce(const std::vector<double>& par1, const std::vector<double>& par2, const std::vector<double>& distributionIndex) {
    SimulatedBinary crossoverHeuristic;
    Gausian mutationHeuristic;
    std::vector<std::vector<double>> offsprings = crossoverHeuristic.crossover(par1, par2, distributionIndex);
    offsprings[0] = mutationHeuristic.mutate(offsprings[0]);
    offsprings[1] = mutationHeuristic.mutate(offsprings[1]);
    mainProxy.recieve(offsprings);
  }
// }

#include "ga.def.h"