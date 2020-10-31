#include "common.h"

using namespace Minisat;

bool lab1(int states[], int n, int button[][2], int m, bool answer[])
{
    Solver solver;
    Var variables[1000];
    int i, j;
    for(i = 0; i<m; ++i)
        variables[i] = solver.newVar();



    //TODO : your solution here.
    /* assert(0); */
    for (int i = 0; i < m; i++) {
        if (button[i][1] <= 0 || button[i][1] >= n ) {
            if (states[button[i][0] - 1] == 1) solver.addClause(~mkLit(variables[button[i][0] - 1]));
            else solver.addClause(~mkLit(variables[button[i][0] - 1]));
            continue;
        }

        /* if (button[i][1] != 0 && button[i][0] == 0) {
            if (states[button[i][1] - 1] == 1) solver.addClause(mkLit(variables[button[i][1] - 1]));
            else solver.addClause(~mkLit(variables[button[i][1] - 1]));
            continue;
        } */
        if (states[button[i][0] - 1] == 1 && states[button[i][1] - 1] == 1) {
            solver.addClause(~mkLit(variables[button[i][0] - 1]), ~mkLit(variables[button[i][1] - 1]));
            continue;
        }
        if (states[button[i][0] - 1] == 0 && states[button[i][1] - 1] == 0) {
            solver.addClause(mkLit(variables[button[i][0] - 1]), mkLit(variables[button[i][1] - 1]));
            continue;
        }
        if (states[button[i][0] - 1] == 0 && states[button[i][1] - 1] == 1) {
            solver.addClause(mkLit(variables[button[i][0] - 1]), ~mkLit(variables[button[i][1] - 1]));
            continue;
        }
        if (states[button[i][0] - 1] == 1 && states[button[i][1] - 1] == 0) {
            solver.addClause(~mkLit(variables[button[i][0] - 1]), mkLit(variables[button[i][1] - 1]));
            continue;
        }
    }


    //solve SAT problem
    auto sat = solver.solve();
    if(sat)
    {
        for(i = 0; i < m; ++i)
            answer[i] = (solver.modelValue(variables[i]) == l_True);
        return true;
    }
    return false;
}




