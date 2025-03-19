#include <vector> 
#include <random>
#include <limits>
#include "particle.hpp"

namespace SwarmOptimizer {
  Particle::Particle() {}
  Particle::Particle(int numDimensions) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-5.12, 5.12);
    position.reserve(numDimensions);
    velocity.reserve(numDimensions);
    PersonalBestPosition.resize(numDimensions);
    for (int i = 0; i < numDimensions; i++) {
      position.push_back(dist(gen));
      velocity.push_back(dist(gen));
    }
    fitness = std::numeric_limits<double>::infinity();
    PersonalBestFitness = fitness;
  }

  void Particle::update(double inertia, double cognitive, double social, const std::vector<double>& GlobalBestPosition) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (int i = 0; i < position.size(); i++) {
      double r1 = dist(gen);
      double r2 = dist(gen);
      velocity[i] = inertia * velocity[i] +
        cognitive * r1 * (PersonalBestPosition[i] - position[i]) +
        social * r2 * (GlobalBestPosition[i] - position[i]);
      position[i] += velocity[i];
    }
  }
}