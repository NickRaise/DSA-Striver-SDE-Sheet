// Target Sum

// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
// Return the number of different expressions that you can build, which evaluates to target.

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3


#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the elements in nums
    int n = nums.size(); // Number of elements in nums

    // If the difference between totalSum and target is negative, it's impossible to split nums into two subsets
    if(totalSum - target < 0) return 0;
    
    // If the difference is odd, it's impossible to partition nums into two subsets
    if((totalSum - target) % 2 == 1) return 0;

    int sum2 = (totalSum - target) / 2; // The target sum for one of the subsets
    vector<int> dp(sum2 + 1, 0); // DP array to store the number of ways to reach a particular sum

    // Base case initialization
    // If the first element is 0, there are two ways to assign it (+0 or -0)
    if(nums[0] == 0) dp[0] = 2;
    else dp[0] = 1;

    // If the first element is not 0 and it is less than or equal to sum2, initialize dp[nums[0]] = 1
    if(nums[0] != 0 && nums[0] <= sum2) dp[nums[0]] = 1;

    // Iterate over the remaining elements in nums
    for(int idx = 1; idx < n; idx++) {
        vector<int> currentRow(sum2 + 1, 0); // Temporary array to store the current state
        for(int sum = 0; sum <= sum2; sum++) {
            int currentNotTaken = dp[sum]; // Case where the current element is not included
            int currentTaken = 0; // Case where the current element is included
            if(nums[idx] <= sum)
                currentTaken = dp[sum - nums[idx]]; // If the element can be included, add the ways to form the remaining sum

            currentRow[sum] = currentNotTaken + currentTaken; // Combine both cases
        }
        dp = currentRow; // Update the dp array with the current state
    }

    return dp[sum2]; // Return the number of ways to achieve the target sum
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1}; // Example input
    int target = 3; // Example target

    int result = findTargetSumWays(nums, target); // Call the function
    cout << "Number of ways to reach the target: " << result << endl; // Output the result

    return 0;
}
