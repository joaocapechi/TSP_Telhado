#include "Solver.h"

class Neighborhood;

class NBSolver : public Solver
{
public:
	NBSolver();
	~NBSolver() override;
	
	bool solve() override;
	bool solve(const Solution& initial);

private:
	std::vector<Neighborhood*> neighborhoods;
};
