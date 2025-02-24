#include <vector>
#include <cmath>
#include "benchmark.hpp"

namespace Bench {
  double Sphere::fitness(std::vector<double>& individual) {
    double result = 0;
    for (double phenotype : individual) {
      result += std::pow(individual, 2);
    }
  }
}
