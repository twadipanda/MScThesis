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
  mainProxy = thisProxy;

  try {
    gaArray = CProxy_GA::ckNew(numElements);
    // std::cout << "GA array created successfully\n";
  } catch (const std::exception& e) {
    // CkPrintf("Error creating GA array: %s\n", e.what());
    CkExit();
  }
  iterations = 0;
  // std::cout << "Starting" << "\n";
  start = std::chrono::high_resolution_clock::now();
  try {
    population = GA::initialize(10000, 100);
  } catch (const std::exception& e) {
    std::cerr << "Error creating initialising: " << e.what() << std::endl;
    CkExit();
  }
  // std::cout << "Calling iterate on gaArray[0]" << std::endl;
  try {
    gaArray[0].iterate(population, selectionCriteria, percentageElite);
  } catch (const std::exception& e) {
    std::cerr << "Error ITERATEing: " << e.what() << std::endl;
    CkExit();
  }
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
    // std::cout << "Current Fitness: " << fitness[0].second << "\n";
    std::vector<std::vector<double>> tempPopulation = population;
    population.clear();
    gaArray[0].iterate(tempPopulation, selectionCriteria, percentageElite);
  }
}


// When called, the "done()" entry method will cause the program
//   to exit.
void Main::done(const std::vector<std::pair<int, double>>& fitness) {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    // std::cout << "Finished!" << "\n";
    std::cout << iterations << ",";
    std::cout << fitness[0].second << ",";
    std::cout << elapsed.count();
    CkExit();
}


#include "main.def.h"
