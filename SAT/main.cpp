#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "sat.h"

using namespace std;

bool backtracking(SAT& sat, int position){
    //Verifica se a formula foi satisfeita
    if(position == sat.getVarsNum()) //Se declarou todas as variaveis
        return true;

    //Atribui falso a variavel atual
    sat.vars.push_back(false);

    //Testa as variaveis já atribuidas
    if(sat.checkVars())
        if(backtracking(sat, position + 1)) return true;
    
    sat.vars.pop_back(); //remove o valor que foi atribuido

    //Atribui verdadeiro a variavel atual
    sat.vars.push_back(true);

    //Testa as variaveis já atribuidas
    if(sat.checkVars())
        if(backtracking(sat, position + 1)) return true;
    
    sat.vars.pop_back(); //remove o valor que foi atribuido

    //Nenhuma atribuição levou a solução
    return false;
}

int main(){
    //Inicia o problema e armazena a entrada do problema
    SAT sat; cin >> sat;

    auto inicio = chrono::high_resolution_clock::now();

    if(backtracking(sat, 0)){
        cout << "A fórmula é satisfeita.\n";
        cout << sat;
    }
    else{
        cout << "A fórmula não pode ser satisfeita.\n";
    }

    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;

    cout << "Tempo de execução: " << duracao.count() << " segundos\n";

    return 0;
}
