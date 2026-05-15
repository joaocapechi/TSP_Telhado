#include "RandomNearestNeighborSolver.h"

#include <vector>
#include <iostream>

#include "input/Data.h"
#include "input/Parameters.h"
#include "util/Random.h"

using namespace std;


bool RandomNearestNeighborSolver::hasLowerCost(int last, int j, vector<int>& neighbors) {
    bool hasChange = false;
    for (int _ = 0; _ < neighbors.size() && j != -1; _++) {
        if (neighbors[_] == -1 || data.costs[last][j] < data.costs[last][neighbors[_]]) {
            swap(neighbors[_], j);
            hasChange = true;
        }
    }
    return hasChange;
}


bool RandomNearestNeighborSolver::solve()
{
    solution.cost = (unsigned int) -1;
    for (int k = 0; k < 1'000; k++) {
        vector<bool> visited(data.dimension);
        vector<int> neighbors(params.randomNeighbors, -1);

        Solution candidate;
        candidate.nodes.push_back(0);
        visited[0] = true;

        for (int _ = 1; _ < data.dimension; _++)
        {
            const int last = candidate.nodes.back();
            int next = -1;

            fill(neighbors.begin(), neighbors.end(), -1);
            
            for (int j = 1; j < data.dimension; j++)
                if (!visited[j])
                    hasLowerCost(last, j, neighbors);
            
            next = Random::randomElem(neighbors);
            if (next == -1) next = neighbors[0];
            candidate.nodes.push_back(next);
            visited[next] = true;
        }
        candidate.nodes.push_back(0);
        candidate.evaluate();

        if (candidate.cost < solution.cost || k == 0) {
            solution = candidate;
            cout << "RandomNearestNeighborSolver: " << solution << endl;
        }
    }

    return true;
}
