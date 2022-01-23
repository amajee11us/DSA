#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string inputString = "GeeksforGeeks";
    string searchToken = "for";

    // find using complete library function
    int pos = 0;
    int index = inputString.find(searchToken, pos);
    if(index != string::npos){
        cout << "Found at index" << index + 1 << endl;
    }

    // find using only sub string function
    int len_search_token = searchToken.length();

    for(int i = 0 ; i < (inputString.length() - len_search_token); i++){
        string temp = inputString.substr(i, len_search_token);
        if (temp == searchToken){
            cout << "Found at index" << i + 1 << endl;
            break;
        }
    }  
    // find without any library function
    for(int i = 0 ; i < (inputString.length() - len_search_token); i++){
        string temp = "";
        for(int j = i; j < (i + len_search_token); j++){
            temp += inputString[j];
        }
        if(temp == searchToken){
            cout << "Found at index" << i + 1 << endl;
            break;
        }
    }
    return 0;
}