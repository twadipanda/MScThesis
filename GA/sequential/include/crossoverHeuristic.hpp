#pragma once

namespace Heuristcs {
  class CrossoverHeuristic {
    public:
      virtual std::vector<std::vector<double>> crossover(std::vector<double>&, std::vector<double>&, std::vector<double>& = {});
  };

  class SimulatedBinary : public CrossoverHeuristic {
    public:
      std::vector<std::vector<double>> crossover(std::vector<double>&, std::vector<double>&, std::vector<double>&) override;
  };
}