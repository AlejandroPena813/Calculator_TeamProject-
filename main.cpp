#include <iostream>
#include "NthRoot.h"
#include "Number.h"
#include "Exponentiation.h"
#include "Logarithms.h"
#include "Input.h"
#include "Operations.h"

using namespace std;

bool run = false; //become true if menu appeared more than once, to eliminate first emtpy line

void menu();//prints menu


int main() {
    //NthRoot R;
    //Numbers N; //Rationalize is root is bottom missing
    //Exponentiation E; //Fractions as power
    //Logarithms L; //Evaluate Change of base Log
    //Operations O;
    Input I;
    
    int selection = 0;
    menu();
    cin >> selection;
    if (selection == 1){ //Compute new expression
       
        //To enter an expression
    
        cout << "Enter expression: ";
        string expression;
        cin.ignore();
        getline(cin, expression);

        I.input(expression);
        //cout<< E.exp(-3, -2);
        main();
    }
    else if (selection == 2){//Help
        
        main();
    }
    else if (selection == 3){//Review previous expressions and answers
        
        main();
    }
    else if (selection == 4){//Quit
        cout << endl << "   Good Bye" << endl;
    }
    else {
        cout << endl << "   Enter a number between 1 - 4 next time" << endl;
    }

    return 0;
}

void menu() {
    //Menu with no extra first empty line
    if (run == false) {
        cout << "   Welcome" << endl;
        cout << "1. Compute new expression" << endl;
        cout << "2. Help" << endl;
        cout << "3. Review previous expressions and answers" << endl;
        cout << "4. Quit" << endl;
        cout << "   Enter choice: ";
    }
    //Menu with extra spacing empty line
    else {
        cout << endl << "   Welcome" << endl;
        cout << "1. Compute new expression" << endl;
        cout << "2. Help" << endl;
        cout << "3. Review previous espressions and answers" << endl;
        cout << "4. Quit" << endl;
        cout << "   Enter choice: ";
        
    }
    run = true;
}