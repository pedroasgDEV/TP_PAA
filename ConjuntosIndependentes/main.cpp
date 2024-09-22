#include <iostream>
#include <chrono>
#include <algorithm>
#include <set>
#include <vector>

#include "conjuntosIndependentes.h"

using namespace std;

void branchAndBound(ConjuntosIndependentes& complementar, int depth, const set<int>& candidates) {
    //Se chegou ao fim
    if (candidates.empty()) {
        //Atualiza o clique máximo se o clique atual for maior
        if (complementar.currClique.size() > complementar.maxClique.size()) 
            complementar.maxClique = complementar.currClique;
        return;
    }

    //Condição de poda: se o tamanho do clique atual mais os candidatos restantes não for melhor do que o melhor clique encontrado
    if (complementar.currClique.size() + candidates.size() <= complementar.maxClique.size()) 
        return;

    vector<vector<int>> arestas = complementar.getArestas();

    //Tentar expandir o clique atual
    for (int v : candidates) {
        complementar.currClique.push_back(v);
        set<int> newCandidates;

        //Novos candidatos são os vértices adjacentes ao vértice atual
        for (int u : candidates) {
            if (arestas[v][u]) {
                newCandidates.insert(u);
            }
        }

        //Chamar recursivamente para tentar expandir o clique
        branchAndBound(complementar, depth + 1, newCandidates);

        complementar.currClique.pop_back();
    }
}

int main() {
    //Inicia o problema e armazena a entrada do problema
    ConjuntosIndependentes complementar; cin >> complementar;

    auto inicio = chrono::high_resolution_clock::now();

    //Conjunto inicial de todos os vértices
    set<int> candidates;
    for (int i = 0; i < complementar.getNumVertices(); ++i) {
        candidates.insert(i);
    }

    branchAndBound(complementar, 0, candidates);
    cout << "Conjunto Independente Maximo: " << complementar;

    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;

    cout << "Tempo de execução: " << duracao.count() << " segundos\n";

    return 0;
}