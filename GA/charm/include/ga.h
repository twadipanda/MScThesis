#pragma once

#include <vector>
#include "benchmark.hpp"
#include "selectionHeuristic.hpp"
#include "crossoverHeuristic.hpp"
#include "mutationHeuristic.hpp"

// namespace EA {
class GA : public CBase_GA {
  public:
  GA();
  GA(CkMigrateMessage *msg);
  static std::vector<std::vector<double>> initialize(int populationSize, int individualSize);
  static std::vector<std::pair<int, double>> evaluate(const std::vector<std::vector<double>>&);
  void iterate(const std::vector<std::vector<double>>&, double retention, double elite);
  void reproduce(const std::vector<double>&, const std::vector<double>&, const std::vector<double>&);
  };
// }