#pragma once

#include "AbstractSolver.h"
#include <vector>

using namespace std;

class RandomNearestNeighborSolver : public AbstractSolver
{
public:

	bool solve() override;

    bool hasLowerCost(int last, int newCost, vector<int>& neighbors);
};
