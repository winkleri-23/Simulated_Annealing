//
//  Var.h
//  KOP
//
//  Created by Erich Winkler on 27.12.2022.
//
#include<math.h>

#ifndef Var_h
#define Var_h
class Var{
public:
    bool value;
    int index;
    
    Var(){} 
    
    Var(int _index){
        if(_index < 0){
            value = false;
        }else{
            value = true;
        }
        index = abs(_index);
    }
    
    
    bool returnValue(int a){
        if(a == 1 && !value){
            return false;
        }else if (a == 0 && !value){
            return true;
        }else if(a == 1){
            return true;
        }else {
            return false;
        }
    }
};

#endif /* Var_h */
