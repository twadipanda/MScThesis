#include <vector>
#include <random>
#include "mutationHeuristic.hpp"

namespace Heuristcs {
  std::vector<double> Gausian::mutate(std::vector<double>& offspring) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist(0, 0.5);
    for (int i = 0; i < offspring.size(); i++) {
      offspring[i] += dist(gen);
    }
    return std::move(offspring);
  }
}