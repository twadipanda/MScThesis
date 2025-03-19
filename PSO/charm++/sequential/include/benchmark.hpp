#pragma once

#include <vector>

namespace Bench {
  class BenchMark {
    public:
      virtual double fitness(std::vector<double>&) const = 0;
      virtual ~BenchMark() = default;
  };

  class Sphere : public BenchMark {
    public:
      double fitness(std::vector<double>&) const override;
  };
}