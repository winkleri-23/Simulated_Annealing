//
//  state.cpp
//  KOP
//
//  Created by Erich Winkler on 25.12.2022.
//

#include "state.h"



void state::TranslateConfiguration(){
    BoolConfiguration.clear();
    FileConfig.clear();
    int cnt = 0;
    for(auto i : Configuration){
        if(i==0){
            FileConfig.push_back(Var(-cnt));
            BoolConfiguration.push_back(false);
        }else{
            FileConfig.push_back(Var(cnt));
            BoolConfiguration.push_back(true);
        }
        cnt++;
    }
    
}


void state::RandomSolution(){
    vector<int> TmpSol;
    for(int i = 0; i < problem.getNumVar(); i++){
        TmpSol.push_back(rand() % 2);
    }
    
    //for(auto i : TmpSol){
      //  cout << i << " ";
    //}
    //cout << endl;
    Configuration.clear();
    Configuration = TmpSol;
}

void state::DefaultSolution(){
    vector<int> TmpSol;
    for(int i = 0; i < problem.NumberOfVariables; i++){
        TmpSol.push_back(0);
    }
    Configuration = TmpSol;
}

void state::AllOneConfig(){
    vector<int> TmpSol;
    for(int i = 0; i < problem.getNumVar(); i++){
        TmpSol.push_back(1);
    }
    Configuration = TmpSol;
}

int state::calculateWeight(){
    int weight = 0;
    int cnt = 0;
    for(auto & i : problem.weights){
        //cout << "i" << i << endl;
        if(Configuration[cnt] == 1){
            weight += i;
        }
        
        cnt++;
    }
    StateWeight = weight;
    return weight;
}

int state::calculateCost(){
    StateCost =(calculateWeight() - ((problem.formula3SAT.ClausNumber - CountSatisfiedClau()) *  problem.getMaxWeight() )  );
    //StateCost = (calculateWeight() + ((problem.getMaxWeight() + 1) * CountSatisfiedClau()));
    return StateCost;
}

void state::Neighbour(){
    const double range_from  = 0;
    const double range_to    = problem.getNumVar() - 1;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<double>  distr(range_from, range_to);
    int index = distr(generator);
    //int index = rand() % problem.getNumVar();
    
    if(Configuration[index] == 0){
        Configuration[index] = 1;
    }else {
        Configuration[index] = 0;
    }
    //TranslateConfiguration();
}

void state::MultipleNeighbour(){
    int number = rand() % problem.getNumVar();
    for(int i = 0; i < number; i++){
        Neighbour();
    }
}

void state::BestNeighbour(){
        vector<int> varList;

        for(auto & Clau: problem.formula3SAT.Clausules)
        {

                if(Clau.index1.returnValue(Configuration[Clau.index1.index - 1]) == false){
                    varList.push_back(Clau.index1.index);
                }
                
                if(Clau.index2.returnValue(Configuration[Clau.index2.index - 1]) == false){
                    varList.push_back(Clau.index2.index);
                }
                
                if(Clau.index3.returnValue(Configuration[Clau.index3.index - 1]) == false){
                    varList.push_back(Clau.index3.index);
                }

        }
        if(varList.size() == 0){
            Neighbour();
            return;
        }
        std::map<int, int> counters;
        for(auto i: varList)
        {
        ++counters[i];
        }
        int max = 0;
        int ValueMax= 0;
        for(auto i : counters){
            if(i.second >= max){
                ValueMax = i.first;
            }
        }
    int indexMax=0;
    for(int i = 0; i < varList.size(); i++){
        if(varList[i] == ValueMax){
            indexMax = i;
            break;
        }
    }
        int randomPosition = rand() % varList.size();
        
        if(Configuration[varList[randomPosition] - 1] == 0){
            Configuration[varList[randomPosition] - 1] = 1;
        }else {
            Configuration[varList[randomPosition]- 1] = 0;
        }
        
}


bool state::isClausuleSatisfied(Clausule Clau){
    //cout << "func" << endl;
    //TranslateConfiguration();
    //cout << "After_translate " << BoolConfiguration.size() << endl;
    bool a,b,c;
    
    
    
    bool result =Clau.index1.returnValue(Configuration[Clau.index1.index - 1]) ||           Clau.index2.returnValue(Configuration[Clau.index2.index - 1]) ||
    Clau.index3.returnValue(Configuration[Clau.index3.index - 1]);
    return result;
}



void state::printState(){
    
    
    cout << "======state======" << endl;
    for(auto i : Configuration){
        cout << i << " ";
    }
    cout << endl;
    for(auto i : FileConfig){
        cout << i.index << "  " << i.value << endl;
        cout << i.index << "  " << i.value << endl;
        
    }
    cout << problem.getNumVar() << " " << problem.getNumClau() << " " << endl;
    cout << "Weight" << calculateWeight() << endl;
    cout << "======state======" << endl;
    
}


int state::CountSatisfiedClau(){
    //TranslateConfiguration();
    int cnt = 0;
    for(auto & i: problem.formula3SAT.Clausules){
        if(isClausuleSatisfied(i)){
            cnt++;
        }
    }
    SatisfiedClauses = cnt;
    return cnt;
}


bool state::isStateValid(){
    if(CountSatisfiedClau() == problem.getNumClau()){
        return true;
    }else {
        return false;
    }
}
