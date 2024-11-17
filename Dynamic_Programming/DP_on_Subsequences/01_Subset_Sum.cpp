#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> dp(k + 1, false);
    dp[0] = true;  // Base case: A sum of 0 is always possible (by choosing an empty subset)

    // Iterate over each element in the array
    for(int i = 0; i < n; i++) {
        // Create a temporary array to store the current row's results
        vector<bool> currentRow(k + 1, false);
        currentRow[0] = true;  // A sum of 0 is always possible
        
        // Iterate over all possible sums from 1 to k
        for(int j = 1; j <= k; j++) {
            // Case 1: Do not include the current element in the subset
            bool currentNotTaken = dp[j];
            
            // Case 2: Include the current element in the subset if it's less than or equal to the current sum
            bool currentTaken = false;
            if(j >= arr[i])
                currentTaken = dp[j - arr[i]];

            // Update the current row's result: the sum `j` can be achieved either by including or not including the current element
            currentRow[j] = currentTaken || currentNotTaken;
        }

        // Update dp to reflect the results for the current element
        dp = currentRow;
    }

    // Return whether it's possible to form the sum k using any subset of the array
    return dp[k];
}

int main() {
    // Example input
    int n = 6;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    
    // Check if there exists a subset with sum equal to `sum`
    bool result = subsetSumToK(n, sum, arr);
    
    // Output the result
    cout << (result ? "1" : "0") << endl;
    
    return 0;
}
