#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
For a given array “X” of N positive integers, 
write a function to return the value “True” 
if a particular triplet (a,b,c) accurately 
satisfies the condition: a^2+b^2=c^2 - this is commonly called 
the Pythagorean Triplet problem.
*/

int findInList(vector<int> arr, double key){
    int result = -1;
    for(int i = 0; i < arr.size(); i++){
        if((double)arr[i] == key){
            result = i;
            break;
        }
    }
    return result;
}

// complexity O(n^2)
bool findTriplet(vector<int> arr){
    for(int it = 0; it < arr.size(); it++)
        arr[it] = (int)pow(arr[it], 2);
    
    for(int i = 0; i < arr.size(); i++){
        int a = arr[i];
        for(int j = i+1; j < arr.size(); j++){
            int key = a + arr[j];
            if(find(arr.begin() + i, arr.end(), key) != arr.end()){
                return true;
            }
        }
    }
    return false;
}
int main(){
    vector<int> arr{2, 3, 1, 4, 5, 6};

    if(findTriplet(arr))
        cout << "Possible Combination exists." << endl;
    else
        cout << "Possible Combination does not exist." << endl;
    return 0;
}