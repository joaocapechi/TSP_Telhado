#include "GRASP.h"

#include <vector>
#include <iostream>
#include <algorithm>

#include "input/Data.h"

#include "util/Random.h"

using namespace std;
 
bool GRASP::solve()
{
	for (int k = 0; k < 30'000; k++)
	{
		Solution current = solveOne(k == 0);
		if (k == 0 || current.cost < solution.cost)
		{
			solution = current;
			cout << "Grasp: " << current << endl;
		}
	}

	return true;
}

Solution GRASP::solveOne(const bool deterministic) const
{
	Solution current;
	current.nodes.push_back(0);

	vector<bool> visited(data.dimension);
	visited[0] = true;

	for (int _ = 1; _ < data.dimension; _++)
	{
		const int last = current.nodes.back();
		vector<pair<double, int>> candidates;

		double total = 0.0;
		for (int j = 1; j < data.dimension; j++)
			if (!visited[j])
			{
				candidates.emplace_back(1.0 / data.costs[last][j], j);
				total += 1.0 / data.costs[last][j];
			}

		for (auto&[value, _] : candidates)
			value /= total;

		ranges::sort(candidates, greater());

		int next = candidates.front().second;
		if (!deterministic)
		{
			const double r = Random::randomDouble();
			double acc = 0.0;
			for (const auto&[value, id] : candidates)
			{
				acc += value;
				if (r <= acc)
				{
					next = id;
					break;
				}
			}
		}

		current.nodes.push_back(next);
		visited[next] = true;
	}
	current.nodes.push_back(0);
	current.evaluate();

	return current;
}
