#include <vector>
#include <stdexcept>
#include <random>
#include <cmath>
#include <algorithm>
#include "crossoverHeuristic.hpp"

namespace Heuristcs {
  std::vector<std::vector<double>> SimulatedBinary::crossover(std::vector<double>& par1,
  std::vector<double>& par2, std::vector<double>& params) const {
    if (params.size() < 1) {
      throw std::invalid_argument("Hyperparameters not provided for SBX...");
    }
    std::vector<std::vector<double>> result;
    std::vector<double> offspring1;
    std::vector<double> offspring2;
    int size = par1.size();
    offspring1.reserve(size);
    offspring2.reserve(size);
    double distributionIndex = params[0];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double meu = dis(gen);
    double beta;
    if (meu <= 0.5) {
      beta = std::pow((2 * meu), 1 / (distributionIndex + 1));
    }
    else {
      beta = std::pow((1 / (2 * (1 - meu))), 1 / (distributionIndex + 1));
    }
    for (int i = 0; i < size; i++) {
      offspring1.push_back(std::max(0.0, std::min(1.0, ((1 + beta) * par1[i]) + ((1 - beta) * par2[i]))));
      offspring2.push_back(std::max(0.0, std::min(1.0, ((1 - beta) * par1[i]) + ((1 + beta) * par2[i]))));
    }
    result.push_back(offspring1);
    result.push_back(offspring2);
    return std::move(result);
  }
}