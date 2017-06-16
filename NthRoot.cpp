//
//  NthRoot.cpp
//  Numbers
//
//  Created by Leonardo on 3/20/14.
//  Copyright (c) 2014 Leonardo. All rights reserved.
//

#include "NthRoot.h"
#include <math.h>
#include <sstream>
#include <string>

string NthRoot::nthRoot(string number0, float power) {
    
    bool imaginary = false;
    
    if (number0.at(0) == '-'){
        number0.erase(0,1);
        imaginary = true;
    }
    
    float number = atoi( number0.c_str() );
    
    
    
    float temp;
    stringstream result;
    bool done = false;
    
    float resultFloat = pow( number, 1/power);
    float decimal = resultFloat - (long)resultFloat;
    //if perfect root return answer
    if (decimal == 0 && number0.at(0) == '-') {
        stringstream ss;
        ss << resultFloat << "i";
        return ss.str();
        done = true;
    }
    if (decimal == 0 && done == false) {
        stringstream ss;
        ss << resultFloat;
        return ss.str();
    }
    else {
        for (int i = 0; i < number; i++) {
            temp = number/i;
            float resultFloat = pow( temp, 1/power);
            float decimal = resultFloat - (long)resultFloat;
            if (imaginary == true) {
                if ( i == number - 1) {
                    if (power == 1) {
                        result << "i" << power << "st√" << number ;
                        
                    }
                    else if (power == 2) {
                        result << "i" << power << "nd√" << number ;
                        
                    }
                    else if( power == 3) {
                        result << "i" << power << "rd√" << number ;
                        
                    }
                    else {
                        result << "i" << power << "th√" << number ;
                        
                    }
                    break;
                    
                }
                if (decimal == 0){
                    if (power == 1) {
                        result << resultFloat << "i(" << power << "st√" << i << ") " ;
                        
                    }
                    else if (power == 2) {
                        result << resultFloat << "i√" << i ;
                        
                    }
                    else if( power == 3) {
                        result << resultFloat << "i(" << power << "rd√" << i << ") " ;
                        
                    }
                    else {
                        result << resultFloat << "i(" << power << "th√" << i << ") " ;
                        
                    }
                    
                    break;
                }
    
            }
            if ( i == number - 1) {
                if (power == 1) {
                    result << power << "st√" << number ;
                    
                }
                else if (power == 2) {
                    result <<  "√" << number ;
                    
                }
                else if( power == 3) {
                    result << power << "rd√" << number ;
                    
                }
                else {
                    result << power << "th√" << number ;
                    
                }
                break;

            }
            if (decimal == 0){
                if (power == 1) {
                    result << resultFloat << "(" << power << "st√" << i << ") " ;

                }
                else if (power == 2) {
                    result << resultFloat << "√" << i ;

                }
                else if( power == 3) {
                    result << resultFloat << "(" << power << "rd√" << i << ") " ;
    
                }
                else {
                    result << resultFloat << "(" << power << "th√" << i << ") " ;

                }
                
                break;
            }
          
        }
        return result.str();
    }
}