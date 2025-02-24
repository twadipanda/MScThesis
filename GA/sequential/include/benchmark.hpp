#pragma once

#include <vector>

namespace Bench {
  class BenchMark {
    public:
      virtual double fitness(std::vector<double>&);
  };

  class Sphere : public BenchMark {
    public:
      double fitness(std::vector<double>&) override;
  }
}