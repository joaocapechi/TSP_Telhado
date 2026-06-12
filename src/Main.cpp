#include <iostream>
#include <format>

#include "input/Parameters.h"
#include "input/Loader.h"
#include "input/Data.h"

#include "algorithm/Solver.h"

#include "util/Timer.h"

using namespace std;

int main(const int argc, const char * argv[])
{
	try
	{
		Parameters& params = Parameters::getInstance();
		if (!params.load(argc, argv)) return -1;

		Loader loader;
		if (!loader.load())
			throw runtime_error("Failed to load data");

		const Data& data = Data::getInstance();
		cout << "Data loaded: " << data.name << " (" << data.type << "), bks: " << data.bks << endl;

		Timer timer;

		Solver solver;
		solver.solve();

        cout << format("{},{},{},{},{:.3f},{:.6f}",
            data.name,
            (int)params.solverType,
            solver.solution.cost,
            data.bks,
            (solver.solution.cost - data.bks) / (double)data.bks * 100.0,
            timer.stop()
        ) << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}
