//
//  Formula.cpp
//  KOP
//
//  Created by Erich Winkler on 28.12.2022.
//

#include <stdio.h>
#include "Formula.h"


void Formula::CalcMaxWeight(){
    MaxWeight = 0;
    for(auto i : VariableWeights){
        MaxWeight+= i;
    }
}
