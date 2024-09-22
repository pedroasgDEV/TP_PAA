#include "clique.h"

//GETERS
int Clique::getNumVertices(){ return numVertices; }
vector<vector<int>> Clique::getArestas(){ return arestas; }

//SETERS
void Clique::setNumVertices(int numVertices){ this->numVertices = numVertices; }
void Clique::setArestas(vector<vector<int>> arestas){ this->arestas = arestas; }

//METHODS
bool Clique::isClique(const vector<int> clique){
    for (size_t i = 0; i < clique.size(); ++i)
        for (size_t j = i + 1; j < clique.size(); ++j)
            if (!arestas[clique[i]][clique[j]]) return false;
    return true;
}

//OPERATORS OVERLOAD
istream& operator>>(istream& in, Clique& c) {
    // Pega o número de vertices
    in >> c.numVertices;

    vector<int> temp;
    int vertice;
    
    // Armazena as arestas de todos os vercies
    for (int i = 0; i < c.numVertices; i++) {
        for (int j = 0; j < c.numVertices; j++) {
            if (!(in >> vertice)) return in;  // Se a leitura falhar, sai do loop
            temp.push_back(vertice);
        }    
        c.arestas.push_back(temp);
        temp.clear();
    }
    return in;
}

ostream& operator<<(ostream& out, Clique& c){
    out << "[ ";
    for(int vertice : c.maxClique) 
        out << vertice << " ";
    out << "]\n"; 
    return out;
}
