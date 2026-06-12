#include "IteratedLocalSearch.h"

#include <iostream>
#include <format>

#include "VariableNeighborhoodDescent.h"

#include "util/Random.h"

using namespace std;

bool IteratedLocalSearch::solve()
{
    VariableNeighborhoodDescent vnd;
    vnd.solve();

    solution = vnd.solution;
    Solution current = solution;

    cout << "Initial solution: " << solution << endl;

    double initProb = 0.2;
    double finalProb = 0.001;
    int iterations = 1000;

    double initTemp = (initProb * solution.cost) / -log(initProb);
    double finalTemp = (finalProb * solution.cost) / -log(finalProb);
    double alpha = pow(finalTemp / initTemp, 1.0 / iterations);

    int iter = 0;
    double temp = initTemp;
    while (temp > finalTemp)
    {
        Solution candidate = current;

        vnd.perturb(candidate);
        vnd.solve(candidate);

        cout << format("[{} - {:.3f}] {} - {} - {}", ++iter, temp, candidate.cost, current.cost, solution.cost) << endl;

        int profit = current.cost - candidate.cost;
        double perc = exp(profit / temp);
        double dice = Random::randomDouble();

        if (profit > 0 || dice < perc)
        {
            current = candidate;

            if (current.cost < solution.cost)
                solution = current;
        }

        temp *= alpha;
    }

    cout << "Final solution: " << solution << endl;

    return true;
}