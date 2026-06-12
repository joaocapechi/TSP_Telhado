#include "Shift.h"

#include <iostream>

#include "input/Data.h"
#include "output/Solution.h"

#include "util/Random.h"

using namespace std;

bool Shift::evaluate(const Solution& solution, Args& args) const
{
    const int prev = solution.nodes[args.pos - 1];
    const int curr = solution.nodes[args.pos];
	const int next = solution.nodes[args.pos + 1];
	const int next2 = solution.nodes[args.pos + 2];

    args.profit = data.costs[prev][curr] + data.costs[next][next2] -
        data.costs[next][prev] - data.costs[curr][next2];

    return true;
}

void Shift::move(Solution& solution, const Args& args)
{
	swap(solution.nodes[args.pos], solution.nodes[args.pos + 1]);
    solution.evaluate();
}

bool Shift::localSearch(Solution& solution)
{
    bool any = false;
    bool found = true;
    while (found)
    {
        found = false;
        for (int pos = 1; pos < data.dimension - 1; pos++)
        {
            Args args(pos);
            evaluate(solution, args);
            if (args.profit > 0)
            {
                move(solution, args);
                found = any = true;
                // cout << "[SH] " << solution << endl;
            }
        }
    }
    return any;
}

bool Shift::randomMove(Solution& solution)
{
    int pos = Random::randomInt(1, data.dimension - 2);
    Args args(pos);
    if (!evaluate(solution, args)) return false;
    move(solution, args);
    return true;
}
