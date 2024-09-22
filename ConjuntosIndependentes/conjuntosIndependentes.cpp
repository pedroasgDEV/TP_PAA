#include "conjuntosIndependentes.h"

//GETERS
int ConjuntosIndependentes::getNumVertices(){ return numVertices; }
vector<vector<int>> ConjuntosIndependentes::getArestas(){ return arestas; }

//SETERS
void ConjuntosIndependentes::setNumVertices(int numVertices){ this->numVertices = numVertices; }
void ConjuntosIndependentes::setArestas(vector<vector<int>> arestas){ this->arestas = arestas; }

//METHODS
bool ConjuntosIndependentes::isClique(const vector<int> clique){
    for (size_t i = 0; i < clique.size(); ++i)
        for (size_t j = i + 1; j < clique.size(); ++j)
            if (!arestas[clique[i]][clique[j]]) return false;
    return true;
}

//OPERATORS OVERLOAD
istream& operator>>(istream& in, ConjuntosIndependentes& c) {
    // Pega o número de vertices
    in >> c.numVertices;

    vector<int> temp;
    int vertice;
    
    // Armazena as arestas complementares de todos os vercies
    for (int i = 0; i < c.numVertices; i++) {
        for (int j = 0; j < c.numVertices; j++) {
            if (!(in >> vertice)) return in;  // Se a leitura falhar, sai do loop
            if (i != j && vertice == 0) { //Verifica se a entrada 0 e se não está na diagonal
                temp.push_back(1); // Adiciona aresta complementar
            }
            else temp.push_back(0); //Remove uma aresta não complementar
        }    
        c.arestas.push_back(temp);
        temp.clear();
    }
    return in;
}

ostream& operator<<(ostream& out, ConjuntosIndependentes& c){
    out << "[ ";
    for(int vertice : c.maxClique) 
        out << vertice << " ";
    out << "]\n"; 
    return out;
}
