#include "Parameters.h"

#include <iostream>

#include <map>

using namespace std;

bool Parameters::load(const int argc, const char* argv[])
{
    if (argc < 3) return help("Not enough arguments");

    map<string, SolverType> solvers {
        {"random", Random},
        {"nearest", NearestNeighbor},
        {"grasp", GRASP},
        {"variable", VariableNeighborhoodDecent},
        {"randomNearest", RandomNearestNeighbor}
    };

    inputFile = string(argv[1]);

    auto it = solvers.find(string(argv[2]));

    if (it == solvers.end()) return help("Wrong solver");

    solverType = it->second;
    randomNeighbors = (argc > 2) ? strtol(argv[3], NULL, 10) : 3;


    return true;
}

bool Parameters::help(const string& msg)
{
    if (!msg.empty()) cout << "Error: " << msg << endl;
    cout << "Usage: tsp <input_file> [options]" << endl;
    cout << "Options:" << endl;
    cout << "  input_file: TSP instance file to solve." << endl;
    cout << "  type_solver: Type of solver." << endl;
    cout << "    random\n    nearest\n    grasp\n    variable\n    randomNearest" << endl;
    cout << "  extra_from_solver: Parameters of the solver." << endl;

    return false;
}