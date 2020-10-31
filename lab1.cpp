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
        int num = 0;
        int b1 = 0;
        int b2 = 0;
        for (int j = 0; j < m; j++) {
            if (button[j][0] == i + 1 || button[j][1] == i + 1) {
                num++;
                if (num == 1) b1 = j;
                if (num == 2) b2 = j;
            }
            if (j == m - 1 && num == 1) {
                if (states[i] == 1)
                    solver.addClause(~mkLit(variables[b1]));
                else solver.addClause(mkLit(variables[b1]));
            }
            if (j == m - 1 && num == 2) {
                if (states[i] == 1) {
                    solver.addClause(~mkLit(variables[b1]), mkLit(variables[b2]));
                    solver.addClause(mkLit(variables[b1]), ~mkLit(variables[b2]));
                }
                else {
                    solver.addClause(~mkLit(variables[b1]), ~mkLit(variables[b2]));
                    solver.addClause(mkLit(variables[b1]), mkLit(variables[b2]));
                }
            }
        }
        /* if (states[button[i][0] - 1] == 1 && states[button[i][1] - 1] == 1) {
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
        } */
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




