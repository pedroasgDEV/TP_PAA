#include "sat.h"

//GETERS
int SAT::getVarsNum(){ return varsNum; }
vector<Clause> SAT::getClauses(){ return clauses; }

//SETERS
void SAT::setVarsNum(int varsNum){ this->varsNum = varsNum; }
void SAT::setClauses(vector<Clause> clauses){ this->clauses = clauses; }

//METHODS
bool SAT::checkVars(){
    bool result_and = true; //A and True = A
    bool result_or;

    //result_and = clauses[0] & clauses[2] & ... & clauses[n]
    for (auto clause : clauses){
        result_or = false; //A or False = A

        //result_or = clause[0] | clause[1] | ... | clause[n]
        for(int i = 0; i < varsNum; i++){
            if (clause[i] == -1) continue; //Se a variavel não tiver presente na clausura
            if (clause[i] == 1) result_or |= vars[i]; //Se a variavel estiver presente na clausura 
            if (clause[i] == 0) result_or |= !vars[i]; //Se a variavel estiver na clausura mas for invertida
        }

        //result_and = (clauses[0][0] | ... | clauses[0][n]) & (clauses[1][0] | ... | clauses[1][n]) & ...
        result_and &= result_or;
    }

    return result_and;
}

//OPERATORS OVERLOAD
istream& operator>>(istream& in, SAT& a){

    //Pega o numero de variaveis
    in >> a.varsNum;

    //Se assume inicialmente todas as variaveis como falsas
    for (int i = 0; i < a.varsNum; i++) a.vars.push_back(false);

    //Armazena todas as as clausuras enquanto houver entrada
    while (in){
        Clause temp;

        //Armazena todas as variaveis presentes nas clausuras
        for(int i = 0; i < a.varsNum; i++) in >> temp[i];
        
        a.clauses.push_back(temp);
    }
    
    return in;
}