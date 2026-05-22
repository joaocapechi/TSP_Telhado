#include "twoOpt.h"

#include "input/Data.h"
#include "output/Solution.h"

#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;

// See if it is worthy doing the change
bool TwoOpt::evaluate(const Solution& solution, Args& args) const
{
    vector<int> new_solution(solution.nodes);
    
    auto it1 = new_solution.begin() + args.start - 1;
    auto it2 = new_solution.begin() + args.end - 1;
    reverse(it1, it2);

    int tmp = 0;
    for (int i = 0; i < new_solution.size() - 1; i++)
        tmp += data.costs[new_solution[i]][new_solution[i+1]];
    
    args.profit = solution.cost - tmp;

    return true;
}

void TwoOpt::move(Solution& solution, const Args& args) 
{
    auto it1 = solution.nodes.begin() + args.start - 1;
    auto it2 = solution.nodes.begin() + args.end - 1;
    reverse(it1, it2);

    solution.evaluate();
}

bool TwoOpt::localSearch(Solution& solution)
{
    bool any = false;
    bool found = true;
    while (found)
    {
        found = false;
        for (int pos1 = 1; pos1 < data.dimension - 1; pos1++)
        {
            for (int pos2 = pos1 + 1; pos2 < data.dimension - 1; pos2++)
            {
                Args args({pos1, pos2, 0});
                evaluate(solution, args);
                if (args.profit > 0)
                {
                    move(solution, args);
                    found = any = true;
                    cout << "[TO] " << solution << endl;
                }
            }
        }
    }
    return any;
}

bool TwoOpt::randomMove(Solution& solution)
{
    // To be implemented
    return false;
}