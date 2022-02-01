#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findMaxSum(vector<int> a){
    int maxSum = -1, sum = 0; 
    int n = a.size();

    vector<int> longest_subarray;
    vector<int> temp;

    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            sum = 0;
            temp.clear();
            continue; // skip the -ve numbers
        }       
        sum += a[i];
        temp.push_back(a[i]);
        maxSum = max(maxSum, sum);   
        if(maxSum == sum)
            longest_subarray = temp;     
    }
    for(int j = 0; j < longest_subarray.size(); j++)
        cout << longest_subarray[j] << " ";
    cout << endl;
    return maxSum;
}

int main(){
    vector<int> arr{-2, -3, 4, -1, -2, 1, 5, 6, -3};

    int max_sum = findMaxSum(arr);
    cout << max_sum << endl;

    return 0;
}