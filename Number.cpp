//
//  Number.cpp
//  Numbers
//
//  Created by Leonardo on 3/20/14.
//  Copyright (c) 2014 Leonardo. All rights reserved.
//

#include "Number.h"
#include <sstream>
#include <string>

string Numbers::simplifyRational(string expression) {
    int indexOfSlash;
    stringstream topNumberString;
    stringstream bottomNumberString;
    int simplifiedTop = 0;
    int simplifiedBottom = 0;
    
    // find index of slash
    for (int i = 0; i < expression.size() ; i++) {
        if (expression.at(i) == '/'){
            indexOfSlash = i;
            break;
        }
    }
    
    //find first number befroe slash
    for (int i = 0; i < indexOfSlash; i++){
        topNumberString << expression.at(i);
    }
    string top = topNumberString.str();
    int topNumber = atoi(top.c_str());
    
    
    //find second number after slash
    for (int i = indexOfSlash+1; i < expression.size(); i++){
        bottomNumberString << expression.at(i);
    }
    string bottom = bottomNumberString.str();
    int bottomNumber = atoi(bottom.c_str());

    if (bottomNumber < 0) {
        for (int i = bottomNumber; i < 0; i++){
            float tempBottom = (float)bottomNumber/i;
            float decimalBottom = tempBottom - (long)tempBottom;
            float tempTop = (float)topNumber/i;
            float decimalTop = tempTop - (long)tempTop;
            if (decimalBottom == 0 && decimalTop == 0){
                simplifiedBottom = tempBottom;
                simplifiedTop = tempTop;
                break;
            }
        }
   
    }
    for (int i = bottomNumber; i > 0; i--){
        float tempBottom = (float)bottomNumber/i;
        float decimalBottom = tempBottom - (long)tempBottom;
        float tempTop = (float)topNumber/i;
        float decimalTop = tempTop - (long)tempTop;
        if (decimalBottom == 0 && decimalTop == 0){
            simplifiedBottom = tempBottom;
            simplifiedTop = tempTop;
            break;
        }
    }
    if (simplifiedBottom == 0 && simplifiedTop == 0) {
        return expression;
    }
    if (simplifiedBottom == 1) {
        stringstream r;
        r << simplifiedTop;
        return r.str();
    }
    stringstream result;
    result << simplifiedTop << "/" << simplifiedBottom;
    return result.str();
}




