#pragma once

#include <vector>

class SelectionHeuristic {
  public:
    virtual std::vector<std::vector<double>> select(std::vector<std::vector<double>>&, std::vector<std::pair<int, double>>&, std::vector<double>&) const = 0;
    virtual ~SelectionHeuristic() = default;
};

class Tournament : public SelectionHeuristic {
  public:
    std::vector<std::vector<double>> select(std::vector<std::vector<double>>&, std::vector<std::pair<int, double>>&, std::vector<double>&) const override;
};