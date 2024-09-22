#ifndef SAT_H
#define SAT_H

#include <vector>
#include <iostream>

using namespace std;


class Clique{
    private:
        int vertices;
        vector<vector<int>> arestas;

    public:
        vector<bool> vars;

        //GETERS
        int getVertices();
        vector<vector<int>> getArestas();

        //SETERS
        void setVertices(int varsNum);
        void setArestas(vector<Clause> clauses);

        //METHODS
        bool checkVars();

        //OPERATORS OVERLOAD
        friend istream& operator>>(istream& in, SAT& c);
        friend ostream& operator<<(ostream& out, SAT& c);
};

#endif