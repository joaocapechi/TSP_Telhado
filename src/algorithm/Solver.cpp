#include "Solver.h"

#include <stdexcept>

// #include "input/Parameters.h"

// #include "RandomSolver.h"
// #include "NearestNeighborSolver.h"
// #include "GraspSolver.h"
// #include "VNDSolver.h"
// #include "RandomNearestNeighborSolver.h"

#include "NeighborhoodSolver.h"

using namespace std;

bool Solver::solve()
{
	NBSolver solver;
	return solver.solve();
	// AbstractSolver* solver = nullptr;
	// switch (params.solverType)
	// {
	// 	case Parameters::Random: solver = new RandomSolver(); break;
	// 	case Parameters::NearestNeighbor: solver = new NearestNeighborSolver(); break;
	// 	case Parameters::GRASP: solver = new GraspSolver(); break;
	// 	case Parameters::VariableNeighborhoodDecent: solver = new VNDSolver(); break;
	// 	case Parameters::RandomNearestNeighbor: solver = new RandomNearestNeighborSolver(); break;
	// 	default: throw runtime_error("Unknown solver type");
	// }

	// const bool ret = solver->solve();
	// if (ret) solution = solver->solution;
	// delete solver;

	// return ret;
}
