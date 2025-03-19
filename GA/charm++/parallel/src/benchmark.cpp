#include <vector>
#include <cmath>
#include "benchmark.hpp"

namespace Bench {
  double Sphere::fitness(const std::vector<double>& individual) const {
    double result = 0;
    for (double gene : individual) {
      result += std::pow(gene, 2);
    }
    return result;
  }
}
