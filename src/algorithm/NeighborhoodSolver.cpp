#include "NeighborhoodSolver.h"

#include <vector>

#include "neighborhoods/Neighborhood.h"
#include "neighborhoods/Shift.h"
#include "neighborhoods/Swap.h"
#include "neighborhoods/TwoOpt.h"

#include "input/Parameters.h"

#include "RandomSolver.h"
#include "NearestNeighborSolver.h"
#include "GraspSolver.h"
#include "VNDSolver.h"
#include "RandomNearestNeighborSolver.h"

using namespace std;

NBSolver::NBSolver()
{
	neighborhoods.push_back(new TwoOpt());
	neighborhoods.push_back(new Swap());
	neighborhoods.push_back(new Shift());
}

NBSolver::~NBSolver()
{
	for (const Neighborhood* neighborhood : neighborhoods)
		delete neighborhood;
}

bool NBSolver::solve()
{
	AbstractSolver* solver = nullptr;

	switch (params.solverType)
	{
		case Parameters::Random: solver = new RandomSolver(); break;
		case Parameters::NearestNeighbor: solver = new NearestNeighborSolver(); break;
		case Parameters::GRASP: solver = new GraspSolver(); break;
		case Parameters::VariableNeighborhoodDecent: solver = new VNDSolver(); break;
		case Parameters::RandomNearestNeighbor: solver = new RandomNearestNeighborSolver(); break;
		default: throw runtime_error("Unknown solver type");
	}

	bool ret = solver->solve();

	if (ret) {
		solution = solver->solution;
		ret = solve(solution);
	}
	delete solver;
	return ret;
}

bool NBSolver::solve(const Solution& initial)
{
	solution = initial;

	bool found = true;
	while (found)
	{
		found = false;
		for (Neighborhood* neighborhood : neighborhoods)
			if (neighborhood->localSearch(solution))
				found = true;
	}

	return true;
}