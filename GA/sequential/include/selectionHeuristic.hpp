#pragma once

namespace Heuristcs {
  class SelectionHeuristic {
    public:
      virtual std::vector<std::vector<double>> select(std::vector<std::vector<double>>&, double retention, double elite);
  };

  class Tournament : public SelectionHeuristic {
    public:
      std::vector<std::vector<double>> select(std::vector<std::vector<double>>&, double retention, double elite) override;
  };
}