#ifndef SAT_H
#define SAT_H

#include <vector>
#include <iostream>

using namespace std;

using Clause = vector<int>;

class SAT{
    private:
        int varsNum;
        vector<Clause> clauses;

    public:
        vector<bool> vars;

        //GETERS
        int getVarsNum();
        vector<Clause> getClauses();

        //SETERS
        void setVarsNum(int varsNum);
        void setClauses(vector<Clause> clauses);

        //METHODS
        bool checkVars();

        //OPERATORS OVERLOAD
        friend istream& operator>>(istream& in, SAT& c);
        friend ostream& operator<<(ostream& out, SAT& c);
};

#endif