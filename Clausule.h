//
//  Clausule.h
//  KOP
//
//  Created by Erich Winkler on 23.12.2022.
//

#include "Var.h"

#ifndef Clausule_h
#define Clausule_h

using namespace std;
class Clausule{
public:
    
    
    Clausule(int _index1, int _index2, int _index3){
        index1 = Var(_index1);
        index2 = Var(_index2);
        index3 = Var(_index3);
    }
    
    void print(){cout << index1.index << "  " << index1.value << "  " << index2.index << " " << index2.value << " " << index3.index
        << " " << index3.value<< endl;
    }
    Var index1, index2, index3;
};

#endif /* Clausule_h */
