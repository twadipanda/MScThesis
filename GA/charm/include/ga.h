#pragma once

#include <vector>
#include "benchmark.hpp"
#include "selectionHeuristic.hpp"
#include "crossoverHeuristic.hpp"
#include "mutationHeuristic.hpp"

namespace EA {
 class GA : public CBase_GA {
  public:
  GA(CkMigrateMessage *msg);
  static std::vector<std::vector<double>> initialize(int populationSize, int individualSize);
  static std::vector<std::pair<int, double>> evaluate(std::vector<std::vector<double>>&, const Bench::BenchMark&);
  static void iterate(std::vector<std::vector<double>>&, double retention, double elite, const SelectionHeuristic&, const CrossoverHeuristic&, const MutationHeuristic&, const Bench::BenchMark&);
  static void reproduce(std::vector<double>&, std::vector<double>&, std::vector<double>&, const CrossoverHeuristic&, const MutationHeuristic&);
  };
}