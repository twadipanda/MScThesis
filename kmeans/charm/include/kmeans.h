#pragma once
#include "distanceMetrics.h"

class Kmeans : public CBase_Kmeans {

 public:
  std::vector<std::vector<double>> centerPoints;
  int counter_;
  int size;
  int ks;
  Kmeans() : counter_(0), size(0), ks(0) {}
  Kmeans(CkMigrateMessage *msg);

  static std::vector<std::vector<double>> getInitialCenters(const std::vector<std::vector<double>>&, const int&);
  void computeDistance(const std::vector<std::vector<double>>&,
    const std::vector<std::vector<double>>&);
  void computeDistancePar(const std::vector<std::vector<double>>&,
    const std::vector<double>&, int);
  void done();
  void received();
  void reduce(const std::vector<double>&);
  static int minIndex(const std::vector<double>&);
  static std::vector<std::vector<double>> computeNewCenters(const std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&, int);
  static std::vector<double> add(const std::vector<double>&, const std::vector<double>&);
  static std::vector<double> div(const std::vector<double>&, int);
};
