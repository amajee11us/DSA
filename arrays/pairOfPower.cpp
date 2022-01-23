#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

/*
For a given set of 2 arrays “X” and “Y” consisting of positive integers, 
write a code to find the total no. of pairs to satisfy the condition x^y>y^x, 
where “x” is an element of array “X” and “y” is an element of array “Y.” 
*/

// complexity: O(n * m)
int countPairsNaive(int X[], int Y[], int m, int n){
    int count = 0;

    for(int i = 0; i < m; i++){
        int x = X[i];
        for(int j = 0 ; j < n; j++){
            int y = Y[j];
            if(pow(x,y) > pow(y,x)){
                //cout << "(" << x << ", " << y << ")" << endl; 
                count++;
            }
        }
    }
    return count;
}

// complexity: O(m)
int countPairsBest(int X[], int Y[], int m, int n){
	vector<int> suffix(1005);
	long long total_pairs = 0;
	for (int i = 0; i < n; i++)
		suffix[Y[i]]++;

	// Compute suffix sums till i = 3
	for (int i = 1e3; i >= 3; i--)
		suffix[i] += suffix[i + 1];

	for (int i = 0; i < m; i++) {

		// Base Case: x = 0
		if (X[i] == 0)

			// No valid pairs
			continue;

		// Base Case: x = 1
		else if (X[i] == 1) {

			// Store the count of 0's
			total_pairs += suffix[0];
			continue;
		}

		// Base Case: x = 2
		else if (X[i] == 2)

			// Store suffix sum upto 5
			total_pairs += suffix[5];

		// Base Case: x = 3
		else if (X[i] == 3)

			// Store count of 2 and
			// suffix sum upto 4
			total_pairs += suffix[2]
						+ suffix[4];

		// For all other values of x
		else
			total_pairs += suffix[X[i] + 1];

		// For all x >=2, every y = 0
		// and every y = 1 makes a valid pair
		total_pairs += suffix[0] + suffix[1];
	}
	// Return the count of pairs
	return total_pairs;
}

int main()
{
	int X[] = { 10, 19, 18 };
	int Y[] = { 11, 15, 9 };

	int m = sizeof(X) / sizeof(X[0]);
	int n = sizeof(Y) / sizeof(Y[0]);

	cout << countPairsNaive(X, Y, m, n) << endl;
    cout << countPairsBest(X, Y, m, n) << endl;

	return 0;
}
