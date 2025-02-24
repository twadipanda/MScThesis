#pragma once

#include <vector>
#include "benchmark.hpp"
#include "selectionHeuristic.hpp"
#include "crossoverHeuristic.hpp"
#include "mutationHeuristic.hpp"

namespace EA {
 class GA {
  public:
    static std::vector<std::vector<double>> initialize(int populationSize, int individualSize);
    static double evaluate(std::vector<double>&, BenchMark);
    static std::vector<std::vector<double>> selection(std::vector<std::vector<double>>&, SelectionHeuristic, double retention, double elite);
    static std::vector<double> crossover(CrossoverHeuristic, std::vector<double>&, std::vector<double>&);
    static std::vector<double> mutation(MutationHeuristic, std::vector<double>&, std::vector<double>&);
  }; 
}