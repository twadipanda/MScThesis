#pragma once


class CrossoverHeuristic {
  public:
    virtual std::vector<std::vector<double>> crossover(const std::vector<double>&, const std::vector<double>&, const std::vector<double>&) const = 0;
    virtual ~CrossoverHeuristic() = default;
};

class SimulatedBinary : public CrossoverHeuristic {
  public:
    std::vector<std::vector<double>> crossover(const std::vector<double>&, const std::vector<double>&, const std::vector<double>&) const override;
};