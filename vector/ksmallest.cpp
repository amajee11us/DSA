#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findKSmallest(vector<int> a, int K){
    int len = a.size();

    int L = 0, R = len - 1, pos = 0;
    K = K - 1; // to match index

    while(L <= R && K > 0){
        pos = R;        
        int i = L;
        while(i < pos){
            if(a[i] > a[pos]){
                int temp = a[i];
                a.erase(a.begin() + i);
                a.insert(a.begin() + pos, temp); // erase reduced count by 1
                pos--;
            }
            else
                i++;
        }

        if(K == pos)
            return a[pos];
        else if(K > pos){
            L = pos + 1;
        }
        else{
            R = pos - 1;
        }
    }
    return -999;
}

int main(){
    vector<int> arr{ 12, 3, 5, 7, 4, 19, 26 }; //{2, 1, 4, 5, 3};
    int K = 3;

    int element = findKSmallest(arr, K);
    cout << element << endl;

    return 0;
}