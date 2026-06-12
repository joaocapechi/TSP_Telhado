#include "Relocate.h"

#include <iostream>
#include <algorithm>

#include "input/Data.h"
#include "output/Solution.h"

#include "util/Random.h"

using namespace std;

bool Relocate::evaluate(const Solution &solution, Args &args) const
{
    const int prev1 = solution.nodes[args.pos1 - 1];
    const int curr1 = solution.nodes[args.pos1];
    const int next1 = solution.nodes[args.pos1 + 1];
    const int curr2 = solution.nodes[args.pos2];
    const int next2 = solution.nodes[args.pos2 + 1];

    args.profit = data.costs[prev1][curr1] + data.costs[curr1][next1] + data.costs[curr2][next2] -
                  data.costs[prev1][next1] - data.costs[curr2][curr1] - data.costs[curr1][next2];

    return true;
}

void Relocate::move(Solution &solution, const Args &args)
{
    solution.nodes.insert(solution.nodes.begin() + args.pos2 + 1, solution.nodes[args.pos1]);
    if (args.pos1 < args.pos2)
        solution.nodes.erase(solution.nodes.begin() + args.pos1);
    else
        solution.nodes.erase(solution.nodes.begin() + args.pos1 + 1);

    solution.evaluate();
}

bool Relocate::localSearch(Solution &solution)
{
    bool any = false;
    bool found = true;
    while (found)
    {
        found = false;
        for (int pos1 = 1; pos1 < data.dimension - 1; pos1++)
            for (int pos2 = 0; pos2 < data.dimension - 1; pos2++)
            {
                if (pos1 >= pos2 - 1 && pos1 <= pos2 + 2)
                    continue;

                Args args(pos1, pos2);
                evaluate(solution, args);
                if (args.profit > 0)
                {
                    move(solution, args);
                    found = any = true;
                    // cout << "[RE] " << solution << endl;
                }
            }
    }
    return any;
}

bool Relocate::randomMove(Solution &solution)
{
    int pos1 = Random::randomInt(1, data.dimension - 2);
    int pos2 = Random::randomInt(0, data.dimension - 2);

    if (pos1 >= pos2 - 1 && pos1 <= pos2 + 2)
        return false;

    Args args(pos1, pos2);
    if (!evaluate(solution, args))
        return false;
    move(solution, args);
    return true;
}
