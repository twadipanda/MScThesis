#include<vector>
#include<iostream>
#include <chrono>
#include "ga.hpp"
#include "benchmark.hpp"
#include "selectionHeuristic.hpp"
#include "crossoverHeuristic.hpp"
#include "mutationHeuristic.hpp"

int main() {
    Bench::Sphere benchmark;
    Heuristcs::Tournament selectionHeuristic;
    Heuristcs::SimulatedBinary crossoverHeuristic;
    Heuristcs::Gausian mutationHeuristic;
    double selectionCriteria = 10;
    double percentageElite = 0.3;
    std::cout << "Starting" << "\n";
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<double>> population = EA::GA().initialize(100, 10);
    population = EA::GA().iterate(population, selectionCriteria, percentageElite, selectionHeuristic, crossoverHeuristic, mutationHeuristic, benchmark);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Finished!" << "\n";
    // std::cout << "Took " << iterations << " iterations!\n";
    std::cout << "Execution time: " << elapsed.count() << " seconds\n";
};