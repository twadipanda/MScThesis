#pragma once

#include <vector>
#include "benchmark.hpp"
#include "particle.hpp"

namespace SwarmOptimizer {
  // The Particle Swarm Optimization algorithm.
  class PSO {
    public:
      // Constructor.
      // Parameters:
      //   benchmark: The benchmark function to optimize.
      //   numParticles: The number of particles in the swarm.
      //   numDimensions: The number of dimensions in the search space.
      //   maxIterations: The maximum number of iterations to run the algorithm.
      //   inertia: The inertia weight.
      //   cognitive: The cognitive weight.
      //   social: The social weight.
      PSO(const Bench::BenchMark& benchmark, int numParticles, int numDimensions, int maxIterations, double inertia, double cognitive, double social);

      void iterate();
      void initialize();
      void evaluate();
      void update();
      double getGlobalBestFitness();

    private:
      const Bench::BenchMark& benchmark;
      int numParticles;
      int numDimensions;
      int maxIterations;
      double inertia;
      double cognitive;
      double social;
      std::vector<Particle> particles;
      Particle GlobalBestParticle;
  };
}