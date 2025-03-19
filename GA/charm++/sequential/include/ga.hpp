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
    static std::vector<std::pair<int, double>> evaluate(std::vector<std::vector<double>>&, const Bench::BenchMark&);
    // static std::vector<std::vector<double>> selection(std::vector<std::vector<double>>&, Heuristcs::SelectionHeuristic, double retention, double elite);
    // static std::vector<double> crossover(Heuristcs::CrossoverHeuristic, std::vector<double>&, std::vector<double>&);
    // static std::vector<double> mutation(Heuristcs::MutationHeuristic, std::vector<double>&, std::vector<double>&);
    static std::vector<std::vector<double>> iterate(std::vector<std::vector<double>>&, double retention, double elite, const Heuristcs::SelectionHeuristic&, const Heuristcs::CrossoverHeuristic&, const Heuristcs::MutationHeuristic&, const Bench::BenchMark&);
  };
}