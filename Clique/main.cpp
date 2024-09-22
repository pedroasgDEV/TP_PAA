#include <iostream>

#include "clique.h"

using namespace std;

int main() {
    //Inicia o problema e armazena a entrada do problema
    Clique clique; cin >> clique;

    for(auto arestas : clique.getArestas()){
        for(auto aresta : arestas)
            cout << aresta << " ";
        cout << endl;
    }

/*     auto inicio = chrono::high_resolution_clock::now();

    if(backtracking(sat, 0)){
        cout << "A fórmula é satisfeita.\n";
        cout << sat;
    }
    else{
        cout << "A fórmula não pode ser satisfeita.\n";
    }

    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;

    cout << "Tempo de execução: " << duracao.count() << " segundos\n"; */

    return 0;
}