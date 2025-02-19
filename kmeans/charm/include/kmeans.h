#pragma once
#include "distanceMetrics.h"

class Kmeans : public CBase_Kmeans {

 public:

  /// Constructors ///
  Kmeans();
  Kmeans(CkMigrateMessage *msg);

  void Kmeans::computeDistance(const std::vector<std::vector<double>>&,
    const std::vector<std::vector<double>>&);
  void Kmeans::computeDistancePar(const std::vector<std::vector<double>>&,
    const std::vector<double>&, int, int);
  int minIndex(const std::vector<double>&);
  std::vector<std::vector<double>> computeNewCenters(const std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&, int);
  std::vector<double> add(const std::vector<double>&, const std::vector<double>&);
  std::vector<double> div(const std::vector<double>&, int);
};
