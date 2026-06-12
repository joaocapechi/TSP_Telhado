#include "RandomSolution.h"

#include <iostream>

#include "input/Data.h"
#include "util/Random.h"

using namespace std;

bool RandomSolution::solve()
{
    for (int i = 0; i < data.dimension; i++)
		solution.nodes.push_back(i);
	solution.nodes.push_back(0);

	solution.evaluate();
	cout << "RandomSolution: " << solution << endl;

	Solution current = solution;
	for (int k = 0; k < 10'000'000; k++)
	{
		Random::shuffle(current.nodes.begin() + 1, current.nodes.end() - 1);
		current.evaluate();

		if (current.cost < solution.cost)
		{
			solution = current;
			cout << "Improved: " << solution << endl;
		}
	}

    return true;
}
