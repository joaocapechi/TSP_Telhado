cmake_minimum_required(VERSION 4.2)
project(tsp)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(tsp
        src/algorithm/AbstractSolver.cpp
        src/algorithm/AbstractSolver.h
        src/input/Data.h
        src/algorithm/GRASP.cpp
        src/algorithm/GRASP.h
        src/algorithm/IteratedLocalSearch.cpp
        src/algorithm/IteratedLocalSearch.h
        src/input/Loader.cpp
        src/input/Loader.h
        src/Main.cpp
        src/algorithm/NearestNeighbor.cpp
        src/algorithm/NearestNeighbor.h
        src/algorithm/neighborhoods/Neighborhood.cpp
        src/algorithm/neighborhoods/Neighborhood.h
        src/util/Point.h
        src/util/Random.cpp
        src/util/Random.h
        src/algorithm/RandomSolution.cpp
        src/algorithm/RandomSolution.h
        src/algorithm/neighborhoods/Relocate.cpp
        src/algorithm/neighborhoods/Relocate.h
        src/algorithm/neighborhoods/Shift.cpp
        src/algorithm/neighborhoods/Shift.h
        src/util/Singleton.h
        src/output/Solution.cpp
        src/output/Solution.h
        src/algorithm/Solver.cpp
        src/algorithm/Solver.h
        src/algorithm/neighborhoods/Swap.cpp
        src/algorithm/neighborhoods/Swap.h
        src/util/Timer.cpp
        src/util/Timer.h
        src/algorithm/neighborhoods/TwoOpt.cpp
        src/algorithm/neighborhoods/TwoOpt.h
        src/algorithm/VariableNeighborhoodDescent.cpp
        src/algorithm/VariableNeighborhoodDescent.h
        src/input/Parameters.cpp
        src/input/Parameters.h)