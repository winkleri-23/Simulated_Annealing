//
//  Annealing.h
//  KOP
//
//  Created by Erich Winkler on 25.12.2022.
//

#include "state.h"
#include <fstream>
#include <random>

#ifndef Annealing_h
#define Annealing_h


class Annealing{
    
public:
    bool frozen();
    bool accept();
    state GenerateRandomState();
    state GenerateNeighbour();
    void simulation(SAT & _satProblem);
    void cool();
    void isItBest();
    void WriteSolutionIntoFile();
    double initTemp(SAT _satProblem, int maxDiffer);
    
    Annealing(int _equilibrium, double _initT, double _CoolFactor, string _FileDst, string _package): equilibrium(_equilibrium) ,initT(_initT), coolFactor(_CoolFactor), solutionDST(_FileDst), package(_package) {
        //currentState.RandomSolution();
        minT = 0.01;
        reset = 3;
    }
    
    
    
    int innerStepsCount;
    double currT;
    double initT;
    double coolFactor;
    double minT;
    int equilibrium;
    int reset;
    int visitedStatesCount;
    vector<pair<int, int>> Steps_Value;
    
    void CreateCSV();
    void CSVTime(uint32_t time);
    
    state bestState;
    state currentState;
    state newState;
    state FirstState;
    state bestValidState;
    string solutionDST;
    string package;
};


#endif /* Annealing_h */
