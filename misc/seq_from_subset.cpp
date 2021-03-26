#include <iostream>
#include <stdio.h>

using namespace std;

void getAllCombinations(int *min_steps, 
                        int target, int subset[], int len_subset, 
                        int partial[]={}, int floating_index=0, 
                        int tracked_sum=0){
    if(tracked_sum == target){
        for(int i = 0; i < floating_index; i++){
            cout << partial[i] << "\t";
        }
        cout << endl;
        //track min steps
        if(floating_index < *min_steps){
            *min_steps = floating_index;
        }
    }
    else if(tracked_sum >= target){
        return; // cant do anything more here
    }

    for(int i = 0; i < len_subset; i++){
        int n = subset[i];
        partial[floating_index] = n; 
        getAllCombinations(min_steps,
                           target, subset, len_subset, 
                           partial, floating_index + 1, 
                           tracked_sum + n);
    }
}

void getPrimeSubset(int num_primes, int *arr){
    int count = 0;
    int num = 2; // minimum positive prime
    
    while(count < num_primes){
        bool isPrime = true;
        for(int i=2; i <= num/2; i++){
            if(num%i == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime == true){
            *(arr + count) = num;
            count++;
        }
        num++;
    }
}

int getShortestSteps(int target, int scores){
    // get primes from scores
    int len_subset = scores;
    int subset[scores];
    getPrimeSubset(len_subset,subset);

    int partial[target] = {}; //initially empty
    int min_steps = target + 1; // this is the max possible

    getAllCombinations(&min_steps, target, subset, len_subset, partial);

    if(min_steps > target){
        cout << "No combination is possible." << endl;
        return -1;
    }
    else
        return min_steps;
}

int main(){
    cout << "Start of program ..." << endl;

    int target =11;
    int K = 3;

    int min_steps = getShortestSteps(target, K);

    cout << "Minimum number of steps : " << min_steps << endl;

    cout << "Ended." << endl;
    return 0;
}