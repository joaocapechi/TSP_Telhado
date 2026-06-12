#pragma once

#include "Solver.h"

class Neighborhood;

class VariableNeighborhoodDescent : public Solver
{
public:
	VariableNeighborhoodDescent();
	~VariableNeighborhoodDescent() override;
	
	bool solve() override;
	bool solve(Solution& solution);

    void perturb(Solution& solution);

private:
	std::vector<Neighborhood*> neighborhoods;
    std::vector<Neighborhood*> perturbations;
};
