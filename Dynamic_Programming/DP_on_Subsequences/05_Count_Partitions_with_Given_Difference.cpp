// Count Partitions with Given Difference

// Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be S1 and S2. 
// Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference between S1 and S2 is equal to d.

// Input:
// n = 4
// d = 3
// arr[] =  { 5, 2, 6, 4}
// Output: 1
// Explanation:
// There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.


#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

// Function to count the number of ways to partition the array into two subsets
// such that the difference between their sums is equal to the given value d
int countPartitions(int n, int d, vector<int>& arr) {
    // Calculate the total sum of the array elements
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    // Check if it's possible to partition the array with the given difference
    if ((totalSum - d) < 0 || (totalSum - d) % 2 == 1) return 0;

    // Calculate the target range for one of the subsets
    int targetRange = (totalSum - d) / 2;

    // Initialize a DP array to store the number of ways to achieve each possible sum
    vector<int> dp(targetRange + 1, 0);

    // Base case: There's always 1 way to achieve a sum of 0 (by picking no elements)
    dp[0] = (arr[0] == 0) ? 2 : 1;

    // If the first element is not zero and within the target range, mark it in the DP array
    if (arr[0] != 0 && arr[0] <= targetRange)
        dp[arr[0]] = 1;

    // Iterate through the array starting from the second element
    for (int idx = 1; idx < n; idx++) {
        vector<int> currentRow(targetRange + 1, 0); // Temporary DP row for the current element
        // Calculate the number of ways to achieve each target sum from 0 to targetRange
        for (int target = 0; target <= targetRange; target++) {
            // Not picking the current element
            int notPicked = dp[target];
            // Picking the current element
            int picked = 0;
            if (arr[idx] <= target)
                picked = dp[target - arr[idx]];
            
            // Total ways to achieve the target sum with or without the current element
            currentRow[target] = (notPicked + picked) % MOD;
        }
        dp = currentRow; // Update the DP array to reflect the current row
    }

    return dp[targetRange]; // Return the number of ways to achieve the target range sum
}

int main() {
    vector<int> arr = {1, 1, 2, 3}; // Predefined array of integers
    int n = arr.size(); // Size of the array
    int d = 1; // Desired difference between the sums of the two subsets

    // Call the function and print the result
    int result = countPartitions(n, d, arr);
    cout << "Number of ways to partition the array into two subsets with difference " << d << ": " << result << endl;

    return 0;
}
