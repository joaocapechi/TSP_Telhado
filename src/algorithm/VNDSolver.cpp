#include "VNDSolver.h"

#include <vector>

#include "neighborhoods/Neighborhood.h"
#include "neighborhoods/Shift.h"
#include "neighborhoods/Swap.h"
#include "neighborhoods/TwoOpt.h"

#include "NearestNeighborSolver.h"

using namespace std;

VNDSolver::VNDSolver()
{
	neighborhoods.push_back(new TwoOpt());
	neighborhoods.push_back(new Swap());
	neighborhoods.push_back(new Shift());
}

VNDSolver::~VNDSolver()
{
	for (const Neighborhood* neighborhood : neighborhoods)
		delete neighborhood;
}

bool VNDSolver::solve()
{
	NearestNeighborSolver nearest;
	nearest.solve();
	return solve(nearest.solution);
}

bool VNDSolver::solve(const Solution& initial)
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