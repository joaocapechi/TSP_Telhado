#include "Solver.h"

#include <stdexcept>

#include "input/Parameters.h"

#include "RandomSolution.h"
#include "NearestNeighbor.h"
#include "Grasp.h"
#include "VariableNeighborhoodDescent.h"
#include "IteratedLocalSearch.h"

using namespace std;

bool Solver::solve()
{
	AbstractSolver* solver = nullptr;
	switch (params.solverType)
	{
	case Parameters::RandomSolution: solver = new RandomSolution(); break;
	case Parameters::NearestNeighbor: solver = new NearestNeighbor(); break;
	case Parameters::GRASP: solver = new GRASP(); break;
	case Parameters::VariableNeighborhoodDecentSolver: solver = new VariableNeighborhoodDescent(); break;
    case Parameters::IteratedLocalSearchSolver: solver = new IteratedLocalSearch(); break;
	// case Parameters::RandomNearestNeighborSolver: solver = new RandomNearestNeighborSolver(); break;
	default: throw runtime_error("Unknown solver type");
	}

	const bool ret = solver->solve();
	if (ret) solution = solver->solution;
	delete solver;

	return ret;
}
