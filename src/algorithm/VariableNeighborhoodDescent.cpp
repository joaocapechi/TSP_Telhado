#include "VariableNeighborhoodDescent.h"

#include <vector>

#include "neighborhoods/Neighborhood.h"
#include "neighborhoods/Shift.h"
#include "neighborhoods/Swap.h"
#include "neighborhoods/TwoOpt.h"
#include "neighborhoods/Relocate.h"

#include "NearestNeighbor.h"

#include "util/Random.h"

using namespace std;

VariableNeighborhoodDescent::VariableNeighborhoodDescent()
{
    neighborhoods.push_back(new Swap());
    neighborhoods.push_back(new Shift());
    neighborhoods.push_back(new TwoOpt());
    neighborhoods.push_back(new Relocate());

    perturbations = neighborhoods;
}

VariableNeighborhoodDescent::~VariableNeighborhoodDescent()
{
    for (const Neighborhood *neighborhood : neighborhoods)
        delete neighborhood;
}

bool VariableNeighborhoodDescent::solve()
{
    NearestNeighbor nearest;
    nearest.solve();
    return solve(nearest.solution);
}

bool VariableNeighborhoodDescent::solve(Solution &solution)
{
    bool found = true;
    while (found)
    {
        found = false;
        for (Neighborhood *neighborhood : neighborhoods)
            if (neighborhood->localSearch(solution))
                found = true;
    }

    this->solution = solution;

    return true;
}

void VariableNeighborhoodDescent::perturb(Solution &solution)
{
    int total = 0;
    while (total < 5)
    {
        Neighborhood *neighborhood = Random::randomElem(perturbations);
        if (neighborhood->randomMove(solution))
            total++;
    }
}
