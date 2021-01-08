#include "../include/myMathHeader.h"
#include <iostream>

using namespace myName;
using namespace std;

int Mathlib::do_sum(int a, int b){
    return a + b;
};

int Mathlib::do_subtract(int a, int b){
    return a - b;
};

int Mathlib::do_multiply(int a, int b){
    return a * b; 
};

int Mathlib::do_divide(int a, int b){
    int div = 0;

    try{
        div = a / b;
    }
    catch(const char* msg){
        cerr << "Exception caught : " << msg << endl;
    }
    return div;
};

int Mathlib::power(int input, int p){
    if(p == 1){
        return input;
    }
    else{
        return input * power(input, p-1);
    }
};

int Mathlib::get_input(){
    int val;
    cout << "Enter a number : ";
    cin >> val;
    cout << endl;

    return val;
};
