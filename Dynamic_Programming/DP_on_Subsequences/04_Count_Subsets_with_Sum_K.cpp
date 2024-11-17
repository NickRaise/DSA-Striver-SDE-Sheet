// Count Subsets with Sum K

// We are given an array ‘ARR’ with N positive integers and an integer K. 
// We need to find the number of subsets whose sum is equal to K.

// Input: 
// n = 6, arr = [5, 2, 3, 10, 6, 8], sum = 10
// Output: 
// 3
// Explanation: 
// {5, 2, 3}, {2, 8}, {10} are possible subsets.


#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

// Function to find the number of ways to reach the sum K using elements of the array
int findWays(vector<int>& arr, int K)
{
    int n = arr.size();
    // Initialize a DP array to store the number of ways to achieve each possible sum
    vector<int> dp(K + 1, 0);
    dp[0] = 1; // There's always 1 way to achieve a sum of 0 (by picking no elements)

    // If the first element is less than or equal to K, mark it in the DP array
    if(arr[0] <= K)
        dp[arr[0]] = 1;

    // Special case: if the first element is 0, it can be either picked or not, doubling the ways to get sum 0
    if(arr[0] == 0) 
        dp[0] = 2;

    // Iterate through the array starting from the second element
    for(int idx = 1; idx < n; idx++) {
        vector<int> currentRow(K + 1, 0); // Temporary DP row for the current element
        // Calculate the number of ways to achieve each target sum from 0 to K
        for(int target = 0; target <= K; target++) {
            // Not picking the current element
            int notPicked = dp[target];
            // Picking the current element
            int picked = 0;
            if(arr[idx] <= target)
                picked = dp[target - arr[idx]];
            
            // Total ways to achieve the target sum with or without the current element
            currentRow[target] = (picked + notPicked) % MOD;
        }
        dp = currentRow; // Update the DP array to reflect the current row
    }

    return dp[K]; // Return the number of ways to achieve the sum K
}

int main() {
    vector<int> arr = {1, 2, 3, 3}; // Predefined array of integers
    int K = 6; // Target sum to find the number of ways to achieve

    // Call the function and print the result
    int result = findWays(arr, K);
    cout << "Number of ways to reach sum " << K << ": " << result << endl;

    return 0;
}
