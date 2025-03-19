#pragma once

#include <vector>

namespace SwarmOptimizer {
	class Particle {
		public:
			std::vector<double> position;
			std::vector<double> velocity;
			std::vector<double> PersonalBestPosition;
			double fitness;
			double PersonalBestFitness;

			Particle();
			Particle(int numDimensions);
			void update(double inertia, double cognitive, double social, const std::vector<double>& GlobalBestPosition);
	};
}