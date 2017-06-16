//
//  Input.cpp
//  Numbers
//
//  Created by Leonardo on 4/7/14.
//  Copyright (c) 2014 Leonardo. All rights reserved.
//

#include "Input.h"

void Input::input(string inputString) {
    //Initialize shit
    
    NthRoot R; //sqrt::x nthrt::x
    Exponentiation E; //x^y
    //Logarithms L; //log_b::x
    Operations O; // * / + -
    
    //Add outside parenthesis
    inputString.insert(0, "(");
    inputString.insert(inputString.size(), ")");
    //cout << inputString << endl;
    //Delete blank spaces
    for (int i = 0; i < inputString.size(); i++) {
        if (inputString.at(i) == ' ') {
            inputString.erase(i,1);
        }
    }
    
    //inputString has no blank spaces
    
    //count  "(" ")"
    int parentCountLeft = 0;
    int parentCountRight = 0;

    for (int i = 0; i < inputString.size(); i++) {
        if (inputString.at(i) == '(' ){
            parentCountLeft++;
        }
        if( inputString.at(i) == ')'){
            parentCountRight++;
        }
    }
    //Check is () match
    if (parentCountLeft != parentCountRight) {
        cout << "Parenthsis do not match, re enter expression" << endl;
    }
    
    //Add inner most ( ) to vector to outter most
    string result;
    int indexOfOrder = 0;
    vector<string> order;
    for (int i = 0; i < inputString.size(); i++) {
        if (inputString.at(i) == '(') {
            for (int j = i+1; j < inputString.size(); j++){
                if (inputString.at(j) == '(') {
                    break;
                }
                if (inputString.at(j) == ')') {
                    stringstream ss;
                    int start = i;
                    for (int k = i+1; k < j; k++) {
                        ss << inputString.at(k);
                        result = ss.str();
                    }
                    order.push_back(ss.str());
                    stringstream s;
                    s << "order.at[" << indexOfOrder << "]";
                    string str = s.str();
                    indexOfOrder++;
                    inputString.replace(start,ss.str().size()+2,str);
                    //cout << inputString << endl;
                    i = -1;
                    j = -1;
                    break;
                }

            }
        }
    }
    
    // Print order
    
    for (int i  = 0; i < order.size(); i++) {
        cout << order.at(i) << endl;
    }
    cout << endl;
    /* 
          Order
     
        order.at[x]
        sqrt::x
        nthrt::x
        sqrt::x
        log_b::x
        x^y
        * /
        + -
     */
    
    
    
    
    
    
    
    for (int i = 0; i < order.size(); i++) {
        int runsDivision = 0;
        string runStringDivision ="";
        int runsMult = 0;
        string runStringMult ="";
        int runsAdd = 0;
        string runStringAdd ="";
        int runsSub = 0;
        string runStringSub ="";
        //String of current stage
        
        //sqrt::
        for (int k = 0; k < order.at(i).size();k++){
                string str = order.at(i);

                if (order.at(i).at(k) == 's' &&
                order.at(i).at(k+1) == 'q' &&
                order.at(i).at(k+2) == 'r' &&
                order.at(i).at(k+3) == 't' &&
                order.at(i).at(k+4) == ':' &&
                order.at(i).at(k+5) == ':') {
                    stringstream num;
                    for (int j = k+6; j < str.size();j++){
                        if (str.at(j) == '0' ||
                            str.at(j) == '1' ||
                            str.at(j) == '2' ||
                            str.at(j) == '3' ||
                            str.at(j) == '4' ||
                            str.at(j) == '5' ||
                            str.at(j) == '6' ||
                            str.at(j) == '7' ||
                            str.at(j) == '8' ||
                            str.at(j) == '9')
                            {
                        
                                num << str.at(j);
                                if (j == str.size()-1 || (
                                    str.at(j+1) != '0' &&
                                    str.at(j+1) != '1' &&
                                    str.at(j+1) != '2' &&
                                    str.at(j+1) != '3' &&
                                    str.at(j+1) != '4' &&
                                    str.at(j+1) != '5' &&
                                    str.at(j+1) != '6' &&
                                    str.at(j+1) != '7' &&
                                    str.at(j+1) != '8' &&
                                    str.at(j+1) != '9')){
                                    string number = num.str();
                                    order.at(i).replace(k, 6+num.str().size(), R.nthRoot(number, 2));
                                    k=-1;
                                    j=-1;
                                    break;
                                }

                            }
                        
                        
                    }
                
                
                   }
            }
        
        //nrt::x
        
        //String of current stage
        string str = order.at(i);
        for (int f = 0; f < str.size();f++) {
            float power;
            if (str.at(f) == ':' && str.at(f+1) == ':' && str.at(f-1) == 't' && str.at(f-2) == 'r') {
                stringstream pow;
                pow << str.at(f-3);
                power = atof(pow.str().c_str());
                stringstream num;
                for (int j = f+2; j < str.size();j++){
                    if (str.at(j) == '0' ||
                        str.at(j) == '1' ||
                        str.at(j) == '2' ||
                        str.at(j) == '3' ||
                        str.at(j) == '4' ||
                        str.at(j) == '5' ||
                        str.at(j) == '6' ||
                        str.at(j) == '7' ||
                        str.at(j) == '8' ||
                        str.at(j) == '9')
                    {
                        
                        num << str.at(j);
                        if (j == str.size()-1 || (
                                                  str.at(j+1) != '0' &&
                                                  str.at(j+1) != '1' &&
                                                  str.at(j+1) != '2' &&
                                                  str.at(j+1) != '3' &&
                                                  str.at(j+1) != '4' &&
                                                  str.at(j+1) != '5' &&
                                                  str.at(j+1) != '6' &&
                                                  str.at(j+1) != '7' &&
                                                  str.at(j+1) != '8' &&
                                                  str.at(j+1) != '9')){
                            
                            order.at(i).replace(f-3, 5+num.str().size(), R.nthRoot(num.str(), power));

                            
                            break;
                        }
                        
                    }
                    
                    else {
                        
                        break;
                        
                    }
                }
                
            }
        }
        
        //x^y
        
        //String of current stage
        str = order.at(i);
        float power = 0;
        float number = 0;
        int countLeft= 0;
        int countRight = 0;
        for (int f = 0; f < str.size();f++) {
            if (str.at(f) == '^'){
                stringstream pow;
                stringstream num;

                for (int j = f+1; j < str.size();j++){
                    if (str.at(j) == '0' ||
                        str.at(j) == '1' ||
                        str.at(j) == '2' ||
                        str.at(j) == '3' ||
                        str.at(j) == '4' ||
                        str.at(j) == '5' ||
                        str.at(j) == '6' ||
                        str.at(j) == '7' ||
                        str.at(j) == '8' ||
                        str.at(j) == '9' ||
                        str.at(j) == '.'){
                        pow << str.at(j);
                        countRight++;
                        if(j == str.size()-1){
                            power = atof(pow.str().c_str());
                            break;
                        }

                    }
                    else {
                        power = atof(pow.str().c_str());
                        break;
                    }
                }
                for (int j = f -1; j >= 0;j--){
                    if (str.at(j) == '0' ||
                        str.at(j) == '1' ||
                        str.at(j) == '2' ||
                        str.at(j) == '3' ||
                        str.at(j) == '4' ||
                        str.at(j) == '5' ||
                        str.at(j) == '6' ||
                        str.at(j) == '7' ||
                        str.at(j) == '8' ||
                        str.at(j) == '9' ||
                        str.at(j) == '.'){
                        num << str.at(j);
                        countLeft++;
                        if(j == 0) {
                            number = atof(num.str().c_str());
                            break;
                        }
                    }
                    else {
                        number = atof(num.str().c_str());
                        break;
                    }
                }
                
                order.at(i).replace(f-countLeft,countLeft + 1 + countRight,E.exp(number,power));
            }
        }
        
        string sq = "√";
        
        //x or /
        //String of current stage
        str = order.at(i);
        
        //for (int w = 0; w < sq.size();w++){
         //   cout << sq.at(w) << endl;
        //}
        
        int indexOfOp = 0;
        int leftindex = 0;
        int rightIndex = 0;
        bool negAfterNum = false;
        for (int f = 0; f < str.size();f++) {
            
            indexOfOp = f;
            str = order.at(i);
            //*
            if (str.at(f) == '*' || str.at(f) == '/'){
                if (str.at(f) == '*'){
                    //int runs = 0;
                    string runString ="";
                    indexOfOp = f;
                for (int j = indexOfOp - 1; j >= 0; j--){
                    if ((str.at(j) == '0' ||
                        str.at(j) == '1' ||
                        str.at(j) == '2' ||
                        str.at(j) == '3' ||
                        str.at(j) == '4' ||
                        str.at(j) == '5' ||
                        str.at(j) == '6' ||
                        str.at(j) == '7' ||
                        str.at(j) == '8' ||
                        str.at(j) == '9' ||
                         str.at(j) == '.' ||
                         str.at(j) == '-' )&&
                        (str.at(j) !=  '\232' ||
                         str.at(j) != ':')){
                        
                        leftindex=j;
                            
                        
                    }
                    else if (str.at(j) ==  '\232' ||
                             str.at(j) == '\342' ||
                             str.at(j) == ':'||
                             str.at(j) == 't' ||
                             str.at(j) == 's' ||
                             str.at(j) == 'n' ||
                             str.at(j) == 'r') {
                        leftindex= indexOfOp;
                        break;
                    }
                    else {
                        break;
                    }
                }
                
                for (int j = f + 1; j < str.size(); j++){
                    if ((str.at(j) == '0' ||
                         str.at(j) == '1' ||
                         str.at(j) == '2' ||
                         str.at(j) == '3' ||
                         str.at(j) == '4' ||
                         str.at(j) == '5' ||
                         str.at(j) == '6' ||
                         str.at(j) == '7' ||
                         str.at(j) == '8' ||
                         str.at(j) == '9' ||
                         str.at(j) == '.' ||
                         str.at(j) == '-')&&
                        (str.at(j) !=  sq.at(0) ||
                         str.at(j) != ':') &&
                        negAfterNum == false){
                        if ((str.at(j-1) == '0' ||
                             str.at(j-1) == '1' ||
                             str.at(j-1) == '2' ||
                             str.at(j-1) == '3' ||
                             str.at(j-1) == '4' ||
                             str.at(j-1) == '5' ||
                             str.at(j-1) == '6' ||
                             str.at(j-1) == '7' ||
                             str.at(j-1) == '8' ||
                             str.at(j-1) == '9' ||
                             str.at(j-1) == '.' ||
                             str.at(j-1) == '-')&& str.at(j) == '-') {
                            negAfterNum = true;
                            break;
                        }
                        
                        rightIndex = j;
                    }
                    else if (str.at(j) ==  '\232' ||
                             str.at(j) == '\342' ||
                             str.at(j) == ':'||
                             str.at(j) == 't' ||
                             str.at(j) == 's' ||
                             str.at(j) == 'n' ||
                             str.at(j) == 'r') {
                        rightIndex= indexOfOp;
                        break;
                    }
                    else {
                        break;
                    }
                }

                string multi= str.substr(leftindex,rightIndex - leftindex+1);
                    if (runsMult == 0){
                        runStringMult = multi;
                    }
                    if (runStringMult == multi){
                        runsMult++;
                    }
                    if (leftindex != indexOfOp && rightIndex != indexOfOp) {
                     order.at(i).replace(leftindex, rightIndex - leftindex+1, O.multiplication(multi));
                        str = order.at(i);
                        f = -1;

                    }
                    if (indexOfOp >= order.at(i).size() || runsMult > 50){
                        break;
                    }
                //cout << order.at(i) << endl;
                
            }
            }
            // /
            if (indexOfOp >= order.at(i).size()){
                break;
            }
            if (str.at(indexOfOp) == '*' || str.at(indexOfOp) == '/'){
                
                if (str.at(indexOfOp) == '/'){
                    
                    for (int j = indexOfOp - 1; j >= 0; j--){
                        if ((str.at(j) == '0' ||
                             str.at(j) == '1' ||
                             str.at(j) == '2' ||
                             str.at(j) == '3' ||
                             str.at(j) == '4' ||
                             str.at(j) == '5' ||
                             str.at(j) == '6' ||
                             str.at(j) == '7' ||
                             str.at(j) == '8' ||
                             str.at(j) == '9' ||
                             str.at(j) == '.' ||
                             str.at(j) == '-')&&
                            (str.at(j) !=  '\232' ||
                             str.at(j) != ':')){
                                
                                leftindex=j;
                                
                                
                            }
                        else if (str.at(j) ==  '\232' ||
                                 str.at(j) == '\342' ||
                                 str.at(j) == ':'||
                                 str.at(j) == 't' ||
                                 str.at(j) == 's' ||
                                 str.at(j) == 'n' ||
                                 str.at(j) == 'r') {
                            leftindex= indexOfOp;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    
                    for (int j = indexOfOp + 1; j < str.size(); j++){
                        if ((str.at(j) == '0' ||
                             str.at(j) == '1' ||
                             str.at(j) == '2' ||
                             str.at(j) == '3' ||
                             str.at(j) == '4' ||
                             str.at(j) == '5' ||
                             str.at(j) == '6' ||
                             str.at(j) == '7' ||
                             str.at(j) == '8' ||
                             str.at(j) == '9' ||
                             str.at(j) == '.' ||
                             str.at(j) == '-')&&
                            (str.at(j) !=  sq.at(0) ||
                             str.at(j) != ':') &&
                            negAfterNum == false){
                            if ((str.at(j-1) == '0' ||
                                 str.at(j-1) == '1' ||
                                 str.at(j-1) == '2' ||
                                 str.at(j-1) == '3' ||
                                 str.at(j-1) == '4' ||
                                 str.at(j-1) == '5' ||
                                 str.at(j-1) == '6' ||
                                 str.at(j-1) == '7' ||
                                 str.at(j-1) == '8' ||
                                 str.at(j-1) == '9' ||
                                 str.at(j-1) == '.' ||
                                 str.at(j-1) == '-')&& str.at(j) == '-') {
                                negAfterNum = true;
                                break;
                            }
                                rightIndex = j;
                            }
                        else if (str.at(j) ==  '\232' ||
                                 str.at(j) == '\342' ||
                                 str.at(j) == ':'||
                                 str.at(j) == 't' ||
                                 str.at(j) == 's' ||
                                 str.at(j) == 'n' ||
                                 str.at(j) == 'r') {
                            rightIndex= indexOfOp;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    
                    string multi= str.substr(leftindex,rightIndex - leftindex+1);
                    if (runsDivision == 0 || runsDivision == 1){
                        runStringDivision = multi;
                    }
                    if (runStringDivision == multi){
                        runsDivision++;
                    }
                    
                    if (leftindex != indexOfOp && rightIndex != indexOfOp) {
                        order.at(i).replace(leftindex, rightIndex - leftindex+1, O.simplifyRational(multi));
                        str = order.at(i);
                        f = -1;

                    }
                    if (indexOfOp >= order.at(i).size() || runsDivision > 50){
                        break;
                    }
                    //cout << order.at(i) << endl;
                    
                }
            }
        }
        
        
    
        
        
        
        
        
        // + or -
        
        
        
        str = order.at(i);
        
        //for (int w = 0; w < str.size();w++){
        //    cout << str.at(w) << endl;
        //}
        leftindex = 0;
        rightIndex = 0;
        for (int f = 0; f < str.size();f++) {
            negAfterNum = false;
            indexOfOp = f;
            //+
            if (str.at(indexOfOp) == '+' || str.at(indexOfOp) == '-'){
                if (str.at(indexOfOp) == '+'){
                    //int runs = 0;
                    string runString ="";
                    for (int j = indexOfOp - 1; j >= 0; j--){
                        if ((str.at(j) == '0' ||
                             str.at(j) == '1' ||
                             str.at(j) == '2' ||
                             str.at(j) == '3' ||
                             str.at(j) == '4' ||
                             str.at(j) == '5' ||
                             str.at(j) == '6' ||
                             str.at(j) == '7' ||
                             str.at(j) == '8' ||
                             str.at(j) == '9' ||
                             str.at(j) == '.' ||
                             str.at(j) == '-' )&&
                            (str.at(j) !=  '\232' ||
                             str.at(j) != ':')){
                                
                                leftindex=j;
                                
                                
                            }
                        else if (str.at(j) ==  '\232' ||
                                 str.at(j) == '\342' ||
                                 str.at(j) == ':'||
                                 str.at(j) == 't' ||
                                 str.at(j) == 's' ||
                                 str.at(j) == 'n' ||
                                 str.at(j) == 'r'||
                                 str.at(j) == 'e') {
                            leftindex= indexOfOp;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    
                    for (int j = indexOfOp + 1; j < str.size(); j++){
                        if ((str.at(j) == '0' ||
                             str.at(j) == '1' ||
                             str.at(j) == '2' ||
                             str.at(j) == '3' ||
                             str.at(j) == '4' ||
                             str.at(j) == '5' ||
                             str.at(j) == '6' ||
                             str.at(j) == '7' ||
                             str.at(j) == '8' ||
                             str.at(j) == '9' ||
                             str.at(j) == '.' ||
                             str.at(j) == '-')&&
                            (str.at(j) !=  sq.at(0) ||
                             str.at(j) != ':') &&
                            negAfterNum == false){
                            if ((str.at(j-1) == '0' ||
                                 str.at(j-1) == '1' ||
                                 str.at(j-1) == '2' ||
                                 str.at(j-1) == '3' ||
                                 str.at(j-1) == '4' ||
                                 str.at(j-1) == '5' ||
                                 str.at(j-1) == '6' ||
                                 str.at(j-1) == '7' ||
                                 str.at(j-1) == '8' ||
                                 str.at(j-1) == '9' ||
                                 str.at(j-1) == '.' ||
                                 str.at(j-1) == '-')&& str.at(j) == '-') {
                                negAfterNum = true;
                                break;
                            }
                                rightIndex = j;
                            }
                        else if (str.at(j) ==  '\232' ||
                                 str.at(j) == '\342' ||
                                 str.at(j) == ':'||
                                 str.at(j) == 't' ||
                                 str.at(j) == 's' ||
                                 str.at(j) == 'n' ||
                                 str.at(j) == 'r') {
                            rightIndex= indexOfOp;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    
                    string multi= str.substr(leftindex,rightIndex - leftindex+1);
                    if (runsAdd == 0){
                        runStringAdd = multi;
                    }
                    if (runStringAdd == multi){
                        runsAdd++;
                    }
                    
                    if (leftindex != indexOfOp && rightIndex != indexOfOp) {
                        order.at(i).replace(leftindex, rightIndex - leftindex+1, O.addition(str.substr(leftindex,indexOfOp-leftindex), str.substr(indexOfOp+1, rightIndex-indexOfOp+1)));
                        str = order.at(i);
                        f = -1;
                        
                    }
                    if (indexOfOp >= order.at(i).size() || runsAdd > 50){
                        break;
                    }
                }
            }
            // -
            if (indexOfOp >= order.at(i).size()){
                break;
            }
            if (str.at(indexOfOp) == '+' || str.at(indexOfOp) == '-'){
                if (str.at(indexOfOp) == '-'){
                    //int runs = 0;
                    string runString ="";
                    for (int j = indexOfOp - 1; j >= 0; j--){
                        if ((str.at(j) == '0' ||
                             str.at(j) == '1' ||
                             str.at(j) == '2' ||
                             str.at(j) == '3' ||
                             str.at(j) == '4' ||
                             str.at(j) == '5' ||
                             str.at(j) == '6' ||
                             str.at(j) == '7' ||
                             str.at(j) == '8' ||
                             str.at(j) == '9' ||
                             str.at(j) == '.' ||
                             str.at(j) == '-')&&
                            (str.at(j) !=  '\232' ||
                             str.at(j) != ':')){
                                
                                leftindex=j;
                                
                                
                            }
                        else if (str.at(j) ==  '\232' ||
                                 str.at(j) == '\342' ||
                                 str.at(j) == ':'||
                                 str.at(j) == 'r') {
                            leftindex= indexOfOp;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    
                    for (int j = indexOfOp + 1; j < str.size(); j++){
                        if ((str.at(j) == '0' ||
                             str.at(j) == '1' ||
                             str.at(j) == '2' ||
                             str.at(j) == '3' ||
                             str.at(j) == '4' ||
                             str.at(j) == '5' ||
                             str.at(j) == '6' ||
                             str.at(j) == '7' ||
                             str.at(j) == '8' ||
                             str.at(j) == '9' ||
                             str.at(j) == '.' ||
                             str.at(j) == '-')&&
                            (str.at(j) !=  sq.at(0) ||
                             str.at(j) != ':') &&
                            negAfterNum == false){
                            if ((str.at(j-1) == '0' ||
                                 str.at(j-1) == '1' ||
                                 str.at(j-1) == '2' ||
                                 str.at(j-1) == '3' ||
                                 str.at(j-1) == '4' ||
                                 str.at(j-1) == '5' ||
                                 str.at(j-1) == '6' ||
                                 str.at(j-1) == '7' ||
                                 str.at(j-1) == '8' ||
                                 str.at(j-1) == '9' ||
                                 str.at(j-1) == '.' ||
                                 str.at(j-1) == '-')&& str.at(j) == '-') {
                                negAfterNum = true;
                                break;
                            }
                                rightIndex = j;
                            }
                        else if (str.at(j) ==  '\232' ||
                                 str.at(j) == '\342' ||
                                 str.at(j) == ':' ||
                                 str.at(j) == 'r') {
                            rightIndex= indexOfOp;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    
                    string multi= str.substr(leftindex,rightIndex - leftindex+1);
                    if (runsSub == 0){
                        runStringSub = multi;
                    }
                    if (runStringSub == multi){
                        runsSub++;
                    }
                    
                    if (leftindex != indexOfOp && rightIndex != indexOfOp) {
                        order.at(i).replace(leftindex, rightIndex - leftindex+1, O.subtraction(str.substr(leftindex,indexOfOp-leftindex), str.substr(indexOfOp+1, rightIndex-indexOfOp+1)));
                        str = order.at(i);
                        f = -1;
                    }
                    if (indexOfOp >= order.at(i).size() || runsSub > 50){
                        break;
                    }
                    //cout << order.at(i) << endl;
                    
                }
            }
        }
        
        
        
        
    
        //end of first stage
        
        
    }
    
    

    
    
    
    
    
    
    //Print Order
    
    for (int i  = 0; i < order.size(); i++) {
        cout << order.at(i) << endl;
    }
    cout << endl;
     
    

}