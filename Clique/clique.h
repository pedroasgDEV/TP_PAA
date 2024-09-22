#ifndef SAT_H
#define SAT_H

#include <vector>
#include <iostream>

using namespace std;


class Clique{
    private:
        int numVertices;
        vector<vector<int>> arestas;

    public:
        vector<int> maxClique;

        //GETERS
        int getNumVertices();
        vector<vector<int>> getArestas();

        //SETERS
        void setNumVertices(int numVertices);
        void setArestas(vector<vector<int>> arestas);

        //METHODS
        bool isClique(const vector<int> clique);

        //OPERATORS OVERLOAD
        friend istream& operator>>(istream& in, Clique& c);
        friend ostream& operator<<(ostream& out, Clique& c);
};

#endif