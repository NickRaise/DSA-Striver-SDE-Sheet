// Partition Equal Subset Sum

// We are given an array with n positive integers. We need to find if we can partition the array into two subsets such that the sum of elements of each subset is equal to the other.
// If we can partition, return true else return false.

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

#include <bits/stdc++.h>
using namespace std;

// Function to check if the given array can be partitioned into two subsets with equal sum
bool canEqualPartition(vector<int>& nums) {
    // Step 1: Calculate the total sum of the array
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    
    // Step 2: If the total sum is odd, it is impossible to partition it into two equal subsets
    if (totalSum % 2 != 0) return false;

    // Step 3: The target sum for each subset should be half of the total sum
    int targetSum = totalSum / 2;

    // Step 4: Initialize a DP array to track possible sums
    int n = nums.size();
    vector<bool> dp(targetSum + 1, false);
    
    // Base case: A subset with sum 0 is always possible (by taking no elements)
    dp[0] = true;

    // Step 5: If the first element is less than or equal to targetSum, mark it as achievable
    if(nums[0] <= targetSum)
        dp[nums[0]] = true;

    // Step 6: Iterate through the rest of the array and update the DP table
    for(int idx = 1; idx < n; idx++) {
        // Create a temporary DP array for the current iteration
        vector<bool> currentRow(targetSum + 1, false);
        
        for(int target = 1; target <= targetSum; target++) {
            // Check if the current element is taken
            bool currentTaken = false;
            if(nums[idx] <= target)
                currentTaken = dp[target - nums[idx]];

            // Check if the current element is not taken
            bool notTaken = dp[target];

            // If either case is true, the current sum target is achievable
            currentRow[target] = currentTaken || notTaken;
        }

        // Update the DP array for the next iteration
        dp = currentRow;
    }

    // Step 7: The result is whether the targetSum is achievable or not
    return dp[targetSum];
}

int main() {
    // Example array
    vector<int> nums = {1, 5, 11, 5};

    // Check if the array can be partitioned into two subsets with equal sum
    bool result = canEqualPartition(nums);

    // Print the result
    if(result)
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    else
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;

    return 0;
}
