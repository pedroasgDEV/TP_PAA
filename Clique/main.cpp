#include <iostream>
#include <chrono>
#include <algorithm>
#include <set>
#include <vector>

#include "clique.h"

using namespace std;

void branchAndBound(Clique& clique, int depth, const set<int>& candidates) {
    //Se chegou ao fim
    if (candidates.empty()) {
        //Atualiza o clique máximo se o clique atual for maior
        if (clique.currClique.size() > clique.maxClique.size()) 
            clique.maxClique = clique.currClique;
        return;
    }

    //Condição de poda: se o tamanho do clique atual mais os candidatos restantes não for melhor do que o melhor clique encontrado
    if (clique.currClique.size() + candidates.size() <= clique.maxClique.size()) 
        return;

    vector<vector<int>> arestas = clique.getArestas();

    //Tentar expandir o clique atual
    for (int v : candidates) {
        clique.currClique.push_back(v);
        set<int> newCandidates;

        //Novos candidatos são os vértices adjacentes ao vértice atual
        for (int u : candidates) {
            if (arestas[v][u]) {
                newCandidates.insert(u);
            }
        }

        //Chamar recursivamente para tentar expandir o clique
        branchAndBound(clique, depth + 1, newCandidates);

        clique.currClique.pop_back();
    }
}

int main() {
    //Inicia o problema e armazena a entrada do problema
    Clique clique; cin >> clique;

    auto inicio = chrono::high_resolution_clock::now();

    //Conjunto inicial de todos os vértices
    set<int> candidates;
    for (int i = 0; i < clique.getNumVertices(); ++i) {
        candidates.insert(i);
    }

    branchAndBound(clique, 0, candidates);
    cout << "Clique Maximo: " << clique;

    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;

    cout << "Tempo de execução: " << duracao.count() << " segundos\n";

    return 0;
}