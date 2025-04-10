#include <vector>
#include <random>
#include <cmath>
#include "mutationHeuristic.hpp"

/**
 * @brief Namespace for heuristic operators in the Genetic Algorithm.
 */
namespace Heuristcs {
  /**
   * @brief Applies Gaussian mutation to an offspring individual.
   *
   * Mutates genes with a 20% probability, adding Gaussian noise (mean 0, stddev 0.1),
   * ensuring values stay within [0, 0.5].
   *
   * @param offspring The individual to mutate.
   * @return std::vector<double> The mutated individual.
   */
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
}