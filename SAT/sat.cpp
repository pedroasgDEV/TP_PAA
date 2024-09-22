#include "sat.h"

//GETERS
int SAT::getVarsNum(){ return varsNum; }
vector<Clause> SAT::getClauses(){ return clauses; }

//SETERS
void SAT::setVarsNum(int varsNum){ this->varsNum = varsNum; }
void SAT::setClauses(vector<Clause> clauses){ this->clauses = clauses; }

//METHODS
bool SAT::checkVars(){
    bool result_or;
    bool has_all_vars;
    int var_id;

    for (auto clause = clauses.begin(); clause != clauses.end(); clause++){
        result_or = false; // A or False = A
        has_all_vars = true;

        //Verifica se a verificação só sera feita com base nas clausuras com o tamanho menor da quantidade das variaveis já definidas
        if(clause->size() > vars.size()) continue;

        //Verifica as variaveis da clausura
        for(auto var : *clause){
            //Se a variavel for negativa
            if(var < 0){
                var_id = (-var) - 1; //Pega o id da variavel
                //Se a variavel não tiver sido declarada ainda
                if(var_id >= (int) vars.size()){
                    has_all_vars = false; //A clausura possui uma variavel que não foi declarada ainda
                    break; //interrompe a verificação da clausura
                }
                result_or |= !(vars[var_id]); //adiciona a variavel na comparação
            }
            //Se a variavel for positiva
            else{
                 var_id = var - 1; //Pega o id da variavel
                //Se a variavel não tiver sido declarada ainda
                if(var_id >= (int) vars.size()){
                    has_all_vars = false; //A clausura possui uma variavel que não foi declarada ainda
                    break; //interrompe a verificação da clausura
                }
                result_or |= vars[var_id]; //adiciona a variavel na comparação
            } 
        }

        //Se não há nenhuma variavel não declarada ainda na clausura
        if(has_all_vars){
            //Se alguma clausura der false, logo o resultado da expressão é false
            if (!result_or) return false;
        }
    }

    return true;
}

//OPERATORS OVERLOAD
istream& operator>>(istream& in, SAT& a) {
    // Pega o número de variáveis
    in >> a.varsNum;

    // Armazena todas as cláusulas
    vector<int> temp;

    int var;
    
    while (in) {
        // Armazena as variáveis presentes nas cláusulas
        for (int i = 0; i < a.varsNum; i++) {
            if (!(in >> var)) return in;  // Se a leitura falhar, sai do loop
            if(var == -1) continue; //Se a variavel não estiver presente
            //Se a variavel for negativa
            else if(var == 0) temp.push_back(-(i + 1));
            //Se a variavel for positiva
            else temp.push_back(i + 1);
        }
        a.clauses.push_back(temp);
        temp.clear();
    }

    return in;
}

ostream& operator<<(ostream& out, SAT& c){
    out << "[ ";
    for(bool var : c.vars) 
        out << (var ? "True ":"False ");
    out << "]\n"; 
    
    return out;
}
