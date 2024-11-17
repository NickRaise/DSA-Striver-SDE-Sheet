// Array partition with minimum difference

// Given an array arr of size n containing non-negative integers, 
// the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference.

// Input: N = 4, arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11  


#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum difference between the sums of two subsets
int minSubsetSumDifference(vector<int>& arr, int n)
{
    // Calculate the total sum of the array elements
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    // Create a DP array initialized to false, with size of totalSum + 1
    vector<bool> dp(totalSum + 1, false);

    // Base case: There's always a subset with sum 0 (the empty subset)
    dp[0] = true;

    // If the first element is less than or equal to totalSum, mark it in the DP array
    if(arr[0] <= totalSum)
        dp[arr[0]] = true;

    // Iterate through the elements of the array
    for(int i = 1; i < n; i++) {
        // Create a new row for the current element in the DP table
        vector<bool> currentRow(totalSum + 1, false);
        currentRow[0] = true; // There's always a subset with sum 0

        // Iterate through possible subset sums
        for(int target = 1; target <= totalSum; target++) {
            // If current element is taken
            bool currTaken = false;
            if(arr[i] <= target)
                currTaken = dp[target - arr[i]];

            // If current element is not taken
            bool currNotTaken = dp[target];

            // Update current DP row
            currentRow[target] = currTaken || currNotTaken;
        }
        // Update the DP array to the current row
        dp = currentRow;
    }

    // Find the minimum difference between the sums of two subsets
    int minDiff = INT_MAX;
    for(int target = 1; target <= totalSum; target++) {
        if(dp[target] == true) {
            int sum1 = target;
            int sum2 = totalSum - target;
            int currentDiff = abs(sum1 - sum2);
            minDiff = min(minDiff, currentDiff);
        }
    }

    return minDiff;
}

int main() {
    vector<int> arr = {1, 6, 11, 5}; // Predefined array of integers
    int n = arr.size(); // Size of the array

    // Call the function and print the result
    int result = minSubsetSumDifference(arr, n);
    cout << "The minimum difference between the sums of two subsets is: " << result << endl;

    return 0;
}
