#pragma once

#include "AbstractSolver.h"

class GRASP : public AbstractSolver
{
public:

	bool solve() override;

	[[nodiscard]] Solution solveOne(bool deterministic = false) const;
};
