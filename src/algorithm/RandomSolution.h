#pragma once

#include "AbstractSolver.h"

class RandomSolution : public AbstractSolver
{
public:
	bool solve() override;
};
