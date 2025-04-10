#include <vector>
#include <cmath>
#include "benchmark.hpp"

/**
 * @brief Namespace for benchmark functions used in optimization.
 */
namespace Bench {
  /**
   * @brief Computes the fitness of an individual using the Sphere function.
   *
   * The Sphere function sums the squares of an individual's genes, serving as a minimization benchmark.
   * The global minimum is 0 when all genes are 0.
   *
   * @param individual The individual's genes as a vector of doubles.
   * @return double The fitness value (sum of squared genes).
   */
  double Sphere::fitness(std::vector<double>& individual) const {
    double result = 0;
    for (double gene : individual) {
      result += std::pow(gene, 2);
    }
    return result;
  }
}