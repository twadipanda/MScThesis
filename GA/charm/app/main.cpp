#include "main.decl.h"

#include "main.h"

#include<vector>
#include<iostream>
#include <chrono>

/* readonly */ CProxy_Main mainProxy;
int numElements;
std::chrono::_V2::system_clock::time_point start;


// Entry point of Charm++ application
Main::Main(CkArgMsg* msg) {
  Bench::Sphere benchmark;
  Heuristcs::Tournament selectionHeuristic;
  Heuristcs::SimulatedBinary crossoverHeuristic;
  Heuristcs::Gausian mutationHeuristic;
  std::vector<std::pair<int, double>> fitness;
  double selectionCriteria = 2;
  double percentageElite = 0.02;
  std::cout << "Starting" << "\n";
  start = std::chrono::high_resolution_clock::now();
  std::vector<std::vector<double>> population = EA::GA().initialize(10000, 100);
  for (int i = 0; i < 10000; i++) {
    population = EA::GA().iterate(population, selectionCriteria, percentageElite, selectionHeuristic, crossoverHeuristic, mutationHeuristic, benchmark);
    fitness = EA::GA().evaluate(population, benchmark);
    std::cout << "Top Fitness: " << fitness[0].second << " Top Index: " << fitness[0].first << "\n";
    std::cout << "Top Individual: " << population[0][0] << population[0][1] << population[0][2] << "\n";
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
    numElements = 5000;
    kmeansArray = CProxy_Kmeans::ckNew(numElements);
    counter = 0;
    mainProxy = thisProxy;
    k = 16;
    timesCalled = 0;
    iterations = 1;
    KmeansParser::Reader reader("letter.txt");
    points = reader.readAndParse();
    centers = Kmeans::getInitialCenters(points, k);
    maxCompute = points.size() * centers.size();
    distances.resize(points.size());
    start = std::chrono::high_resolution_clock::now();
    kmeansArray[0].computeDistance(points, centers);
}


// Constructor needed for chare object migration (ignore for now)
// NOTE: This constructor does not need to appear in the ".ci" file
Main::Main(CkMigrateMessage* msg) { }

void Main::finished(const std::vector<double>& distance, int index) {
    distances[index] = distance;
    timesCalled++;
    if (timesCalled == points.size()) {
        timesCalled = 0;
        std::vector<std::vector<double>> new_centers = Kmeans::computeNewCenters(points, distances, k);
        if (centers != new_centers) {
            centers = new_centers;
            iterations++;
            distances.clear();
            distances.resize(points.size());
            kmeansArray[0].computeDistance(points, new_centers);
        }
        else {
            std::cout << centers[0][0] << "\n";
            std::cout << new_centers[0][0] << "\n";
            done();
        }
    }
}


// When called, the "done()" entry method will cause the program
//   to exit.
void Main::done() {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Finished!" << "\n";
    std::cout << "Took " << iterations << " iterations!\n";
    std::cout << "Execution time: " << elapsed.count() << " seconds\n";
    CkExit();
}


#include "main.def.h"
