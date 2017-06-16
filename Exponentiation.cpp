//
//  Exponentiation.cpp
//  Numbers
//
//  Created by Leonardo on 3/20/14.
//  Copyright (c) 2014 Leonardo. All rights reserved.
//

#include "Exponentiation.h"
#include <math.h>
#include <stdio.h>
#include <sstream>

using namespace std;

string Exponentiation::exp(float number, float power){
    
    float result = pow(number,power);
    float decimal = result - (long)result;
    
    if (decimal == 0) {
        stringstream resultString;
        resultString << result;
        return resultString.str();
    }
    else {
        stringstream resultString;
        resultString << number << "^(" << power << ")";
        return resultString.str();
    }
}