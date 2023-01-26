//
//  3SAT.h
//  KOP
//
//  Created by Erich Winkler on 25.12.2022.
//

#include "Formula.h"
#include <string>


#ifndef _SAT_h
#define _SAT_h

class SAT{
public:
    bool readFormulas();
    
    SAT(){
        
        
    }
    SAT(string src): srcFile(src){}
    SAT(SAT & _oldSAT){
        this->formula3SAT = Formula(_oldSAT.formula3SAT);
        this->NumberOfVariables = _oldSAT.NumberOfVariables;
        this->NumberofClausule = _oldSAT.NumberofClausule;
        this->weights = _oldSAT.weights;
        this->srcFile = _oldSAT.srcFile;
        this->MaxWeight = _oldSAT.MaxWeight;
        InstanceName_csv = _oldSAT.InstanceName_csv;
    }
    
    
    const int getNumVar(){return NumberOfVariables;}
    const int getNumClau(){return NumberofClausule;}
    Formula getFormule(){return formula3SAT;}
    const void printSAT();
    const int getMaxWeight(){
        MaxWeight = 0;
        for(auto i : weights){
            MaxWeight+= i;
        }
        return MaxWeight;
        
    }
    //const vector<int> getWeight(){return weights;}
    const string getInstanceName(){return InstanceName_csv;}
    string ExtractName();
    
public:
    Formula formula3SAT;
    int NumberOfVariables;
    int NumberofClausule;
    int MaxWeight;
    vector<int> weights;
    string InstanceName_csv;
    
    
    
    string srcFile;
};

#endif /* _SAT_h */
