#include "tictoc.hpp"
#include <iostream>

using namespace std;

long int fact[100];
int count = 1;

int fact_dpp(int n){
    if(n < count){
        cout << count << endl;
        return fact[n];
    }
    else{        
        for(int i = count; i <= n ; i++){
            fact[i] = i * fact[i-1];
            count++;
        }
        cout << count << endl;
        return fact[n];
    }
}

int fact_rec(int n){
    if(n==1){
        return 1;
    }
    else{
        return n * fact_rec(n-1);
    }
}

int main(){
    int val;
    tictoc x;
    fact[0] = 1;

    for (int i = 0; i < 5; i++){
        cout << "Enter a number between 1 and 100 : ";
        cin >> val;

        x.tic();
        long int fac_dpp = fact_dpp(val);        
        double t_end_dpp = x.toc();

        //x.tic();
        //long int fac_rec = fact_rec(val);        
        //double t_end_rec = x.toc();

        cout << "Result  DPP: " << fac_dpp << " Time : " << t_end_dpp << endl;
        //cout << "Result  REC: " << fac_rec << " Time : " << t_end_rec << endl;
    }   
    
    return 0;
}