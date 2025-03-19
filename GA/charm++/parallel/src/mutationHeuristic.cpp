#include <vector>
#include <random>
#include <cmath>
#include "mutationHeuristic.hpp"

// namespace Heuristcs {
  std::vector<double> Gausian::mutate(std::vector<double>& offspring) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist(0, 0.1);
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < offspring.size(); i++) {
      if (dis(gen) < 0.2) {
        offspring[i] += std::max(0.0, std::min(0.5, offspring[i] + dist(gen)));
      }
    }
    return std::move(offspring);
  }
// }