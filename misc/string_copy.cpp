#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(){
    // create the array
    char a[10];
    
    //cout << "Enter a string: ";
    //cin.get(a, 10);

    vector<char> svec;

    char ip = '\0';
    while(ip != '\n'){
        ip = getchar();
        svec.push_back(ip);
    }

    /*
    int len = 0;
    while(svec[len] != '\0'){
        len++;
    }
    */
    cout << "Your vector size : " << svec.size()  << endl;

    char arr[svec.size()];
    for(int i=0; i < svec.size(); i++){
        cout << svec[i];
    }  
    cout << endl;
    
    /*
    string l;
    getline(cin, l);

    strcpy(a, l.c_str());
    */

    return 0;
}