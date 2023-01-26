//
//  Formula.h
//  KOP
//
//  Created by Erich Winkler on 24.12.2022.
//

#include <vector>
#include <iostream>
#include <cmath> 
#include "Clausule.h"

#ifndef Formula_h
#define Formula_h

using namespace std;

class Formula {
public: 
    Formula(vector<Clausule> TmpClau, vector <int> Weights, int _NumberOfVariables,int _NumberofClausule){
        Clausules = TmpClau;
        VariableWeights = Weights;
        ClausNumber = (int)TmpClau.size();
        VarNumber = _NumberOfVariables;
        ClausNumber = _NumberofClausule;
        CalcMaxWeight();
    }
    
    Formula( Formula & oldFormula){
        this->Clausules = oldFormula.Clausules;
        this->VariableWeights = oldFormula.VariableWeights;
        this->MaxWeight = oldFormula.MaxWeight;
        this->VarNumber = oldFormula.VarNumber;
        this->ClausNumber = oldFormula.ClausNumber;
    }
    
    void PrintClau () {
        for (auto i : Clausules){
            std::cout << i.index1.index << "  " << i.index2.index << "  " << i.index3.index << endl;
        }
    }
    
    void CalcMaxWeight();
    
    bool isSolution(vector <int> Solution);
    
    int getMaxWeight(){return MaxWeight;}
    
    Formula (){}
    

public:
    vector <Clausule> Clausules;
    vector <int> VariableWeights;
    int MaxWeight;
    int VarNumber;
    int ClausNumber;
    
};


#endif /* Formula_h */
