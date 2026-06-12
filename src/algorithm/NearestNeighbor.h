#pragma once

#include "AbstractSolver.h"

class NearestNeighbor : public AbstractSolver
{
public:

	bool solve() override;
};
