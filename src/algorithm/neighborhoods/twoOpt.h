#pragma once

#include "Neighborhood.h"

class Solution;

class TwoOpt : public Neighborhood
{
public:
	bool localSearch(Solution& solution) override;

	bool randomMove(Solution& solution) override;

private:
	struct Args
	{
		int start;
		int end;
		int profit;
	};

	bool evaluate(const Solution& solution, Args& args) const;
	static void move(Solution& solution, const Args& args);
};
