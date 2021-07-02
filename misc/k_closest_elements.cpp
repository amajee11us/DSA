#include <vector>
#include <cmath>
/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end());
        int lower_bound = findBreakEvenPoint(arr, x, 0, arr.size() - 1);
        int upper_bound = lower_bound + 1;
        int count = 0;
        vector<int> closest;
                
        while(lower_bound >= 0 && upper_bound < arr.size()  && count < k)
        {
            if(abs(x - arr[lower_bound]) < abs(arr[upper_bound] - x) || ( abs(x - arr[lower_bound]) == abs(arr[upper_bound] - x)&& arr[lower_bound] == arr[upper_bound]))
            {
                closest.push_back(arr[lower_bound--]);
            }
            else
            {
                closest.push_back(arr[upper_bound++]);
            }
            count++;
        }
        
        while(count < k && lower_bound >= 0){
            closest.push_back(arr[lower_bound--]);
            count++;
        }
        while(count < k && upper_bound < arr.size()){
            closest.push_back(arr[upper_bound++]);
            count++;
        }
        sort(closest.begin(), closest.end());
        return closest;        
    }
    
    int findBreakEvenPoint(vector<int> arr, int key, int low, int high)
    {
        if(key >= arr[high])
        {
            return high;
        }
        else if(key <= arr[low])
        {
            return low;
        }
        else
        {
            int mid = (low + high)/2;
            if(key >= arr[mid] && arr[mid + 1] > key){
                return mid;
            }
            
            if(key > arr[mid]){
                return findBreakEvenPoint(arr, key, mid + 1, high);
            }
            return findBreakEvenPoint(arr, key, low, mid - 1);
        }
    }
    
};
