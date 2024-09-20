#include "sat.h"

//GETERS
int SAT::getVarsNum(){ return varsNum; }
vector<bool> SAT::getVars(){ return vars; }
vector<Clause> SAT::getClauses(){ return clauses; }

//SETERS
void SAT::setVarsNum(int varsNum){ this->varsNum = varsNum; }
void SAT::setVars(vector<bool> vars){ this->vars = vars; }
void SAT::setClauses(vector<Clause> clauses){ this->clauses = clauses; }

//METHODS
bool SAT::checkVars(){
    bool result_and = true;
    bool result_or;

    for (auto clause : clauses){
        result_or = false;

        for(int i = 0; i < varsNum; i++){
            if (clause[i] == -1) continue;
            if (clause[i] == 1) result_or |= vars[i];
            if (clause[i] == 0) result_or |= !vars[i];
        }

        result_and &= result_or;
    }

    return result_and;
}

//OPERATORS OVERLOAD
istream& operator>>(istream& in, SAT& a){

    in >> a.varsNum;

    for (int i = 0; i < a.varsNum; i++) a.vars.push_back(false);

    while (in){
        Clause temp;

        for(int i = 0; i < a.varsNum; i++) 
            in >> temp[i];
        
        a.clauses.push_back(temp);
    }
    
    return in;
}