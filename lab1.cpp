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
    for (int i = 0; i < n; i++) {
        if (button[i][1] == 0) 
            if (states[button[i][0]] == 1) solver.addClause(variables[button[i][0] - 1]);
            else slover.addClause(~variables[button[i][0] - 1]);
        else if (button[1] == 1)
            if (states[button[i][0]] == 1 && states[button[i][1]] == 1) slover.addClause(variables[button[i][0] - 1], variables[button[i][1] - 1]);
            else if (states[button[i][0]] == 0 && states[button[i][1]] == 0) slover.addClause(~variables[button[i][0] - 1], ~variables[button[i][1] - 1]);
                else if (states[button[i][0]] == 0 && states[button[i][1]] == 1) slover.addClause(~variables[button[i][0] - 1], variables[button[i][1] - 1]);
                    else if (states[button[i][0]] == 1 && states[button[i][1]] == 0) slover.addClause(variables[button[i][0] - 1], ~variables[button[i][1] - 1]);
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




