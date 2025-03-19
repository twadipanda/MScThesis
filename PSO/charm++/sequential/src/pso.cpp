#include <vector>
#include <iostream>
#include "pso.hpp"
#include "benchmark.hpp"
#include "particle.hpp"

namespace SwarmOptimizer {
  PSO::PSO(const Bench::BenchMark& benchmark, int numParticles, int numDimensions, int maxIterations,
    double inertia, double cognitive, double social)
    : benchmark(benchmark), numParticles(numParticles), numDimensions(numDimensions), maxIterations(maxIterations),
    inertia(inertia), cognitive(cognitive), social(social) {}
  
  void PSO::initialize() {
    particles.clear();
    particles.reserve(numParticles);
    for (int i = 0; i < numParticles; i++) {
      Particle particle(numDimensions);
      particles.push_back(particle);
    }
    GlobalBestParticle = particles[0];
  }
  
  void PSO::evaluate() {
    for (Particle& particle : particles) {
      particle.fitness = benchmark.fitness(particle.position);
      // std::cout << "Particle fitness: " << particle.fitness << "\n";
      if (particle.fitness < particle.PersonalBestFitness) {
        particle.PersonalBestFitness = particle.fitness;
        particle.PersonalBestPosition = particle.position;
      }
      if (particle.fitness < GlobalBestParticle.PersonalBestFitness) {
        GlobalBestParticle = particle;
      }
    }
  }

  void PSO::update() {
    for (Particle& particle : particles) {
      particle.update(inertia, cognitive, social, GlobalBestParticle.position);
    }
  }

  void PSO::iterate() {
    initialize();
    for (int i = 0; i < maxIterations; i++) {
      evaluate();
      std::cout << "Global best fitness: " << GlobalBestParticle.fitness << "\n";
      update();
    }
  }

  double PSO::getGlobalBestFitness() {
    return GlobalBestParticle.fitness;
  }
}