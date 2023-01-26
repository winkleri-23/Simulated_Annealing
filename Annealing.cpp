//
//  Annealing.cpp
//  KOP
//
//  Created by Erich Winkler on 25.12.2022.
//

#include <stdio.h>
#include "Annealing.h"

bool Annealing::frozen(){
    return currT > (double)1 ;
}

bool Annealing::accept(){
       const double range_from  = 0.0;
       const double range_to    = 1.0;
       std::random_device                  rand_dev;
       std::mt19937                        generator(rand_dev());
    std::uniform_real_distribution<double>  distr(range_from, range_to);
    double randomValue = distr(generator);
    return ((randomValue) <  exp((newState.calculateCost() - currentState.calculateCost()) / currT));
    
}

void Annealing::cool(){
    currT = currT * coolFactor;
}

void Annealing::isItBest(){
    if(currentState.calculateCost() > bestState.calculateCost()){
        bestState = currentState;
    }
    if(bestState.isStateValid()){
        bestValidState = bestState;
    }
}

void Annealing::simulation(SAT & _satProblem){
    //cout << "halo" << endl;
    
    currentState = state(_satProblem);
    FirstState = currentState;
    
    currT = initT;
    int innerstepsCNT = 0;
    currentState.printState();
    int cntReset = 0;
    int visitedStates= 0;
    int acceptCNT= 0;
    bestState = currentState;
    do{
    //std::ofstream myfile;
    //myfile.open("statsnewEQ.dat", std::fstream::in | std::fstream::out | std::fstream::app);
        while(frozen()){
            //cout << "here" << endl;
            for(int i = 0; i < equilibrium; i++){
                int oldCost = currentState.calculateCost();
                
                state _newState(currentState);
                newState = _newState;
                newState.Neighbour();
                //cout << "Satisfied " << currentState.SatisfiedClauses << endl;
                int diff = newState.calculateCost() - currentState.calculateCost();
                if(diff > 0 ){
                    currentState = newState;
                    //Steps_Value.push_back(make_pair(innerstepsCNT, currentState.calculateWeight()));
                    visitedStates++;
                }else if (accept()){
                    acceptCNT++;
                    //cout << "Accept function" << endl;
                    currentState = newState;
                    //Steps_Value.push_back(make_pair(innerstepsCNT, currentState.calculateWeight()));
                    visitedStates++;
                }else{
                    //cout << "Not accepted" << endl;
                }
                isItBest();
                Steps_Value.push_back(make_pair(innerstepsCNT, currentState.calculateWeight()));
                innerstepsCNT++;
            }
            cool();
        }
        //myfile << "ENnd " << endl;
        currT = initT;
        currentState.RandomSolution();
        cntReset++;
    }while(cntReset < reset);
    //cout <<"ACCEPT: " << acceptCNT << endl;
    innerStepsCount = innerstepsCNT;
    visitedStatesCount = visitedStates;
    bestState.printState();
    
    
}


void Annealing::WriteSolutionIntoFile(){
    string InstanceName = bestState.getproblem().ExtractName();
    bestState.TranslateConfiguration();
    std::fstream myfile;
    myfile.open(solutionDST + package + to_string(FirstState.getproblem().getNumVar())+ ""+ to_string(coolFactor) +"FullPower.dat", std::fstream::in | std::fstream::out | std::fstream::app);
    vector<int> res;
    for (auto i : bestState.getConfiguration()){
        if(i.value){
            res.push_back(i.index + 1);
        }else{
            res.push_back(-(i.index + 1) );
        }
    }
    if(myfile.is_open()){
        myfile << InstanceName << " " << bestState.calculateWeight() << " ";
        for(auto i : res){
            myfile << i << " ";
        }
        
    }
    myfile << "\n";
    myfile.close();
}


void Annealing::CreateCSV(){
    std::ofstream myfile;
    //myfile.open ("../Measurements/" + bestState.getproblem().getInstanceName() + ".csv");
    string path ="../Measurements-final/Steps/" + FirstState.getproblem().getInstanceName() + "_steps_weight" + to_string(coolFactor) +"low.csv";
    //cout << path << endl;
    
    myfile.open(path);
    if(!myfile.is_open()){
        cout << "CSV issue" << endl;
    }
    myfile << "Steps,Weight\n";
    for(auto i : Steps_Value){
        myfile << i.first << "," << i.second <<"\n";
    }
    myfile.close();
    
}

void Annealing::CSVTime(uint32_t time){
    std::ofstream myfile;
    //myfile.open ("../Measurements/" + bestState.getproblem().getInstanceName() + ".csv");
    string path ="../Measurements-final/" + package + "/" + package + to_string(FirstState.getproblem().getNumVar())+ to_string(coolFactor) + "FullPower.csv";
    //cout << path << endl;
    
    myfile.open(path, std::fstream::in | std::fstream::out | std::fstream::app);
    if(!myfile.is_open()){
        cout << "CSV issue" << endl;
    }
    //myfile << "instance,Equilibrium,InitT,coolFactor,steps,time\n";
    myfile <<"\n"<<FirstState.getproblem().getInstanceName() << "," <<equilibrium<<","<<initT<<","<<coolFactor<<","<< innerStepsCount<< ","<<time << "," << bestState.isStateValid();
    myfile.close();
    
}
