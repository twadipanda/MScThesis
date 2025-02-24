#pragma once
#include <vector>

namespace Heuristcs {
	class MutationHeuristic {
		public:
    	virtual std::vector<double> mutate(std::vector<double>&) const = 0;
			virtual ~MutationHeuristic() = default;
	};

	class Gausian : public MutationHeuristic {
		public:
			std::vector<double> mutate(std::vector<double>&) const override;
	};
}