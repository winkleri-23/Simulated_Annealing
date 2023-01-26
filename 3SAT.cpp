//
//  3SAT.cpp
//  KOP
//
//  Created by Erich Winkler on 25.12.2022.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>

#include "3SAT.h"




bool SAT::readFormulas(){
    ifstream input;
    string line, config_type;
    int VarNum = 0;
    int ClausNum = 0;
    int wVar = 0;
    vector <int> WeightsOfVar;
    
    istringstream line_char;
    
    input.open(srcFile);
    
    
    if(!input.is_open()){
        cout << "Could not open given input file" << endl;
    }
    
    while(getline (input, line)){
        //cout << line << endl;
        istringstream ParseLine(line);
        char c;
        ParseLine >> c;
        if(c == 'p'){
            ParseLine >> config_type >> VarNum >> ClausNum;
        }else if(c == 'w') {
            for (int i = 0; i < VarNum; i++){
                ParseLine >> wVar;
                WeightsOfVar.push_back(wVar);
            }
            break;
        }
    }
    
    weights = WeightsOfVar;
    NumberOfVariables = VarNum;
    NumberofClausule = ClausNum;
    
    // Header of a config file has been read
    
    int index1, index2, index3, endNull;
    vector<Clausule> tmpListClaus;
    
    while(getline (input, line)){
        //cout << line << endl;
        /* ignore all comments */
        if(line[0] == 'c'){
            continue;
        }
        /* ignore all comments */
        istringstream Parse(line);
        Parse >> index1 >> index2 >> index3 >> endNull;
        
        if(endNull != 0){
            cout << "Something went wrong while reading the file" << endl;
            return false;
        }
        Clausule tmpClau(index1, index2, index3);
        tmpListClaus.push_back(tmpClau);
        InstanceName_csv = ExtractName();
        for(auto i : WeightsOfVar){
            MaxWeight+= i;
        }
    }
    
    
    formula3SAT = Formula(tmpListClaus, WeightsOfVar, NumberOfVariables,NumberofClausule );

    return true;
}


string SAT::ExtractName(){
    string InstanceName = "";
    vector<string> result;
    stringstream ss (srcFile);
    string item;
    
    while (getline (ss, item, '/')) {
            result.push_back (item);
        }
    
    stringstream ss2 (result[result.size() -1]);
    result.clear();
    while (getline (ss2, item, '.')) {
            result.push_back (item);
        }
    InstanceName_csv = result[0];
    return result[0];
    
}
