#ifndef SAT_H
#define SAT_H

#include <vector>
#include <iostream>

using namespace std;

class SAT{
    private:
        int varsNum;
        vector<vector<int>> clauses;

    public:
        vector<bool> vars;

        //GETERS
        int getVarsNum();
        vector<vector<int>> getClauses();

        //SETERS
        void setVarsNum(int varsNum);
        void setClauses(vector<vector<int>> clauses);

        //METHODS
        bool checkVars();

        //OPERATORS OVERLOAD
        friend istream& operator>>(istream& in, SAT& c);
        friend ostream& operator<<(ostream& out, SAT& c);
};

#endif