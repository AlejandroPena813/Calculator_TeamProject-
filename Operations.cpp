//
//  Operations.cpp
//  Numbers
//
//  Created by Leonardo on 4/7/14.
//  Copyright (c) 2014 Leonardo. All rights reserved.
//

#include "Operations.h"

#include <vector>
#include <sstream>
#include <string>

string Operations::addition(string left, string right) {
    string result;
    //checks if addition is possibile
    bool leftBool = true;
    for (int i = 0; i < left.size()-1; i++) {
        if (left.at(i) == '0' || left.at(i) == '1'|| left.at(i) == '2' ||left.at(i) == '3'|| left.at(i) == '4' ||left.at(i) == '5' ||left.at(i) == '6'|| left.at(i) == '7' ||left.at(i) == '8' ||left.at(i) == '9' ){
            
        }
        else {
            leftBool = false;
        }
    }
    bool rightBool = true;
    for (int i = 0; i < right.size()-1; i++) {
        if (right.at(i) == '0' || right.at(i) == '1' ||right.at(i) == '2' ||right.at(i) == '3'|| right.at(i) == '4'|| right.at(i) == '5'|| right.at(i) == '6' ||right.at(i) == '7' ||right.at(i) == '8'|| right.at(i) == '9' ){
            
        }
        else {
            rightBool = false;
            
        }
    }
    if (rightBool == true && leftBool == true){
        int leftInt = atoi(left.c_str());
        int rightInt = atoi(right.c_str());
        int resultInt = leftInt + rightInt;
        stringstream ss;
        ss << resultInt;
        result = ss.str();
    }
    else {
        stringstream ss;
        ss << left << "+" << right;
        result = ss.str();
    }
    return result;
}

string Operations::subtraction(string left, string right) {
    string result;
    //checks if addition is possibile
    bool leftBool = true;
    for (int i = 0; i < left.size()-1; i++) {
        if (left.at(i) == '0' || left.at(i) == '1'|| left.at(i) == '2' ||left.at(i) == '3'|| left.at(i) == '4' ||left.at(i) == '5' ||left.at(i) == '6'|| left.at(i) == '7' ||left.at(i) == '8' ||left.at(i) == '9' ){
            
        }
        else {
            leftBool = false;
        }
    }
    bool rightBool = true;
    for (int i = 0; i < right.size()-1; i++) {
        if (right.at(i) == '0' || right.at(i) == '1' ||right.at(i) == '2' ||right.at(i) == '3'|| right.at(i) == '4'|| right.at(i) == '5'|| right.at(i) == '6' ||right.at(i) == '7' ||right.at(i) == '8'|| right.at(i) == '9' ){
            
        }
        else {
            rightBool = false;
            
        }
    }
    if (rightBool == true && leftBool == true){
        int leftInt = atoi(left.c_str());
        int rightInt = atoi(right.c_str());
        int resultInt = leftInt - rightInt;
        stringstream ss;
        ss << resultInt;
        result = ss.str();
    }
    else {
        stringstream ss;
        ss << left << "-" << right;
        result = ss.str();
    }
    return result;
}
string Operations::multiplication(string expression) {
    //erase blank and other shits
    for (int i = 0; i < expression.size()-1; i++) {
        if (expression.at(i) == ' ' || expression.at(i) == '(' || expression.at(i) == ')'){
            expression.erase(i,1);
        }
        
    }
    
    
    
    int indexOfMult;
    stringstream topNumberString;
    stringstream bottomNumberString;
    
    
    // find index of *
    for (int i = 0; i < expression.size() ; i++) {
        if (expression.at(i) == '*'){
            indexOfMult = i;
            break;
        }
    }
    
    //find first number befroe slash
    for (int i = 0; i < indexOfMult; i++){
        topNumberString << expression.at(i);
    }
    string top = topNumberString.str();
    float topNumber = atof(top.c_str());
    
    
    //find second number after slash
    for (int i = indexOfMult+1; i < expression.size(); i++){
        bottomNumberString << expression.at(i);
    }
    string bottom = bottomNumberString.str();
    float bottomNumber = atof(bottom.c_str());
    
    float result = topNumber*bottomNumber;
    stringstream res;
    res << result;
    return res.str();

}


string Operations::simplifyRational(string expression) {
    //erase blank and other shits
    for (int i = 0; i < expression.size()-1; i++) {
        if (expression.at(i) == ' ' || expression.at(i) == '(' || expression.at(i) == ')'){
            expression.erase(i,1);
        }
       
    }

    
    
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
    if (bottomNumber == 0) {
        return "undefined";
    }
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
    float tempAns = (float)topNumber/bottomNumber;
    float decimale = tempAns - (long)tempAns;
    stringstream dec;
    dec << decimale;
    string deci = dec.str();
    if (deci.size() < 7){
        stringstream deciAns;
        deciAns << tempAns;
        return deciAns.str();
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





