#include <iostream>

using namespace std;

/*
For a given array “X” of size N-1 consisting of numbers 
from 1 to N with one number missing, write a code to find the 
missing number in the array. 
*/

int main(){
    int arr[] = {1, 2, 4, 5};
    int N = sizeof(arr) / sizeof(arr[0]);

    int total_sum = N * (N + 1) / 2;
    int sum_of_target_array = 0;

    for(int i = 0; i < (N - 1); i++)
        sum_of_target_array += arr[i];
    
    int missing_number = total_sum - sum_of_target_array;
    cout << "Missing Number : " << missing_number << endl;
    
    return 0;
}