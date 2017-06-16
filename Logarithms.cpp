//
//  Logarithms.cpp
//  Numbers
//
//  Created by Leonardo on 3/20/14.
//  Copyright (c) 2014 Leonardo. All rights reserved.
//

#include "Logarithms.h"
#include <vector>
#include <sstream>

string Logarithms::logarithm(string number0, int base) {
    float number = atoi( number0.c_str() );
    vector<float> factors;

    for (int i = number - 1; i > 1;i--) {
        float resultFloat = number / i;
        float decimal = resultFloat - (long)resultFloat;
        if (decimal == 0) {
            number = number / resultFloat;
            factors.push_back(resultFloat);
            
        }
        
        if (number == 2) {
            factors.push_back(2);
            break;
        }
        bool stop = false;
        for (int i=2; i<100; i++) { //maybe change this in if bigger than 100
            for (int j=2; j<i; j++)
            {
                if (i % j == 0)
                    break;
                else if (i == j+1)
                    if (number == i) {
                        factors.push_back(i);
                        stop = true;
                        break;
                    }
                if (number > i) {
                    break;
                }
                
            }
            if (stop) {
                break;
            }
        }
        
        if (stop) {
            break;
        }
       /* if (number == 2) {
            factors.push_back(2);
            break;
        }
        if (number == 3) {
            factors.push_back(3);
            break;
        }
        */
        
            
        
        
       
        
    }
    
    
    stringstream ss;
    for ( int i = 0 ; i < factors.size(); i++) {
        if (i != factors.size() - 1){
            ss << "log_" << base << ":" << factors.at(i) << " + ";
        }
        if (i == factors.size() - 1) {
            ss << "log_" << base << ":" << factors.at(i);

        }
    }
    
    return ss.str();
}