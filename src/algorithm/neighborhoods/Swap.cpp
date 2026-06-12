#include "Swap.h"

#include <iostream>

#include "input/Data.h"
#include "output/Solution.h"

#include "util/Random.h"

using namespace std;

bool Swap::evaluate(const Solution& solution, Args& args) const
{
    const int prev1 = solution.nodes[args.pos1 - 1];
    const int curr1 = solution.nodes[args.pos1];
    const int next1 = solution.nodes[args.pos1 + 1];
    const int prev2 = solution.nodes[args.pos2 - 1];
    const int curr2 = solution.nodes[args.pos2];
    const int next2 = solution.nodes[args.pos2 + 1];

    args.profit = data.costs[prev1][curr1] + data.costs[curr1][next1] +
                  data.costs[prev2][curr2] + data.costs[curr2][next2] -
                  data.costs[prev1][curr2] - data.costs[curr2][next1] -
                  data.costs[prev2][curr1] - data.costs[curr1][next2];

    return true;
}

void Swap::move(Solution& solution, const Args& args)
{
    swap(solution.nodes[args.pos1], solution.nodes[args.pos2]);
    solution.evaluate();
}

bool Swap::localSearch(Solution& solution)
{
    bool any = false;
    bool found = true;
    while (found)
    {
        found = false;
        for (int pos1 = 1; pos1 < data.dimension - 2; pos1++)
            for (int pos2 = pos1 + 2; pos2 < data.dimension - 1; pos2++)
            {
                Args args(pos1, pos2);
                evaluate(solution, args);
                if (args.profit > 0)
                {
                    move(solution, args);
                    found = any = true;
                    // cout << "[SW] " << solution << endl;
                }
            }
    }
    return any;
}

bool Swap::randomMove(Solution& solution)
{
    int pos1 = Random::randomInt(1, data.dimension - 4);
    int pos2 = Random::randomInt(pos1 + 2, data.dimension - 2);
    Args args(pos1, pos2);
    if (!evaluate(solution, args)) return false;
    move(solution, args);
    return true;
}
