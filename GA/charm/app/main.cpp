#include "main.decl.h"

#include "main.h"
#include "ga.decl.h"
#include "ga.h"
#include "benchmark.hpp"
#include "selectionHeuristic.hpp"
#include "crossoverHeuristic.hpp"
#include "mutationHeuristic.hpp"

#include<vector>
#include<iostream>
#include <chrono>
#include <algorithm>

/* readonly */ CProxy_Main mainProxy;
int numElements;
std::chrono::_V2::system_clock::time_point start;
std::vector<std::vector<double>> population;
int iterations;
CProxy_GA gaArray;

// Entry point of Charm++ application
Main::Main(CkArgMsg* msg) {
  // Bench::Sphere benchmark;
  // Tournament selectionHeuristic;
  // SimulatedBinary crossoverHeuristic;
  // Gausian mutationHeuristic;
  double selectionCriteria = 2;
  double percentageElite = 0.02;
  numElements = 100;
  gaArray = CProxy_GA::ckNew(numElements);
  mainProxy = thisProxy;
  iterations = 0;
  std::cout << "Starting" << "\n";
  start = std::chrono::high_resolution_clock::now();
  population = GA::initialize(10000, 100);
  gaArray[0].iterate(population, selectionCriteria, percentageElite);
  population.clear();
}


// Constructor needed for chare object migration (ignore for now)
// NOTE: This constructor does not need to appear in the ".ci" file
Main::Main(CkMigrateMessage* msg) { }

void Main::recieve(const std::vector<std::vector<double>>& offsprings) {
  for (std::vector<double> offspring : offsprings) {
    population.push_back(offspring);
  }
  if (population.size() == 10000) {
    finished();
  }
}

void Main::finished() {
  // Bench::Sphere benchmark;
  // Tournament selectionHeuristic;
  // SimulatedBinary crossoverHeuristic;
  // Gausian mutationHeuristic;
  double selectionCriteria = 2;
  double percentageElite = 0.02;
  iterations++;
  std::vector<std::pair<int, double>> fitness = GA::evaluate(population);
  std::sort(fitness.begin(), fitness.end(), [](const std::pair<int, double>& a, const std::pair<int, double>& b) {
    return a.second < b.second;
  });
  if (fitness[0].second <= 0.00005 || iterations == 10000) {
    done(fitness);
  }
  else {
    gaArray[0].iterate(population, selectionCriteria, percentageElite);
    population.clear();
  }
}


// When called, the "done()" entry method will cause the program
//   to exit.
void Main::done(const std::vector<std::pair<int, double>>& fitness) {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Finished!" << "\n";
    std::cout << "Took " << iterations << " iterations!\n";
    std::cout << "Top Fitness: " << fitness[0].second << " Top Index: " << fitness[0].first << "\n";
    std::cout << "Execution time: " << elapsed.count() << " seconds\n";
    CkExit();
}


#include "main.def.h"
