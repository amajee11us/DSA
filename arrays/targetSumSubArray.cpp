#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
/*
For a given unsorted array “X,” consisting of non-negative integers, write a code to find the contiguous subarray that adds to the sum “S” of non-negative integers in the array.
Input : X = [3,2,4,5,7] , S = 12
Output: [3, 4, 5], [5, 7], [3, 2, 7]
*/
void findContiguousSubArray(int arr[], int len, int target);
void findContiguousSubArrayFaster(int arr[], int len, int target);

// this has time complexity O(n^2)
void findContiguousSubArray(int arr[], int len, int target){
    vector<int> subarray;
    cout << "Found an array of length : " << len << endl;
    for(int i = 0; i < len; i++){
        int moving_sum = arr[i];
        subarray.clear();
        subarray.push_back(arr[i]);
        for(int j = i + 1; j < len; j++){
            if(arr[j] > 0 && (moving_sum + arr[j]) <= target){
                subarray.push_back(arr[j]);
                moving_sum += arr[j];
                if(moving_sum == target){
                    for(int k = 0; k < subarray.size(); k++)
                        cout << subarray[k] << " "; 
                    cout << endl;                        
                }
            }
            else{
                // sum > target
                continue;
            }
        }
    }
}

// reduced time complexity O(n)
void findContiguousSubArrayFaster(int arr[], int len, int target){
    vector<int> tracked_sum;
    int moving_sum = 0;

    for(int i = 0; i < len; i++){
        if(arr[i] < 0)
            continue; // do not track any negative elements
            
        moving_sum += arr[i];
        if(moving_sum == target){
            // now start index is 0 --> easy soln
            for(int k = 0; k <= i; i++)
                cout << arr[k] << " ";
            cout << endl;
        }   

        // if subset exists within array
        auto expected_index = find(tracked_sum.begin(), tracked_sum.end(), (moving_sum - target));
        if(expected_index != tracked_sum.end()){
            int start_index = expected_index - tracked_sum.begin() + 1;
            
            for(int k = start_index; k <= i; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
        tracked_sum.push_back(moving_sum);
    }
}

int main(){
    // TODO: Replace this with input statements
    int arr[] = {3, 2, 4, 5, 7};
    int target = 12;

    int len = (int)(sizeof(arr)/sizeof(arr[0]));

    // inital brute force method
    findContiguousSubArray(arr, len, target);
    // faster time complexity
    findContiguousSubArrayFaster(arr, len, target);

    return 0;
}