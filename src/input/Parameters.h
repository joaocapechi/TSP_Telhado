#pragma once

#include <string>

#include "util/Singleton.h"

class Parameters : public Singleton<Parameters>
{
    friend class Singleton;
public:
    bool load(int argc, const char* argv[]);

    enum SolverType
    {
        RandomSolution,
        NearestNeighbor,
        GRASP,
        VariableNeighborhoodDecentSolver,
        // RandomNearestNeighborSolver,
        IteratedLocalSearchSolver,
    };
    
    std::string inputFile = "data/eil101.tsp";
    SolverType solverType = IteratedLocalSearchSolver;
    int randomNeighbors = 3;

private:
    static bool help(const std::string& msg = "");
};
