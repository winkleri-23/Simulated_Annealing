//
//  state.h
//  KOP
//
//  Created by Erich Winkler on 25.12.2022.
//

#ifndef state_h
#define state_h

#include <stdio.h>
#include "3SAT.h"
#include <random>
#include <map>
using namespace std;

class state{
public:
    state(){}
    state (state &_originalState){
        this->problem = SAT(_originalState.problem);
        this->Configuration = _originalState.Configuration;
        this->StateCost = _originalState.StateCost;
    }
    state(SAT & _problem) {
        problem = SAT(_problem);
        DefaultSolution();
        StateCost = calculateCost();
    }
    void RandomSolution();
    void DefaultSolution();
    void AllOneConfig();
    void Neighbour();
    void MultipleNeighbour();
    
    void printState();
    int calculateWeight();
    int calculateCost();
    bool isStateValid();
    void TranslateConfiguration();
    void BestNeighbour();
    bool isClausuleSatisfied(Clausule Clau);
    int CountSatisfiedClau();
    
    SAT getproblem() {return problem;}
    vector<Var> getConfiguration(){return FileConfig;}
    
public:
    SAT problem;
    vector<int> Configuration;
    vector<bool> BoolConfiguration;
    vector<Var> FileConfig;
    int StateWeight;
    int StateCost;
    int SatisfiedClauses;
    
};
#endif /* state_hpp */
