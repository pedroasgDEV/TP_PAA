#include <iostream>
#include <vector>
#include <chrono>

#include "sat.h"

using namespace std;

bool backtracking(SAT& sat, vector<bool>::iterator varPosition){
    //Verifica se a formula foi satisfeita
    if(varPosition == sat.vars.end())
        return sat.checkVars();

    //Atribui falso a variavel atual
    sat.vars.insert(varPosition, false);
    if(backtracking(sat, ++varPosition))
        return true;
    
    //Atribui verdadeiro a variavel atual
    sat.vars.insert(varPosition, true);
    if(backtracking(sat, ++varPosition))
        return true;

    //Nenhuma atribuição levou a solução
    return false;
}

int main(){
    //Inicia o problema e armazena a entrada do problema
    SAT sat; cin >> sat;

    auto inicio = chrono::high_resolution_clock::now();

    if(backtracking(sat, sat.vars.begin())){
        cout << "A fórmula é satisfeita.\n";
        cout << "[ ";
        for(bool var : sat.vars)
            cout << var ? "True ":"False ";
        cout << "]\n";  
    }
    else{
        cout << "A fórmula não pode ser satisfeita.\n";
    }

    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;

    cout << "Tempo de execução: " << duracao.count() << " segundos\n";

    return 0;
}
