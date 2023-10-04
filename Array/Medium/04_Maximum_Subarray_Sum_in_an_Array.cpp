// Kadane’s Algorithm : Maximum Subarray Sum in an Array
// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.

// Example 1:
// Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 
// Output: 6 
// Explanation: [4,-1,2,1] has the largest sum = 6. 

// Examples 2: 
// Input: arr = [1] 
// Output: 1 
// Explanation: Array has only one element and which is giving positive sum of 1. 



#include <iostream>
#include <vector>
#include <climits> // Required for INT_MIN
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;         // Variable to store the current sum
    int max_sum = INT_MIN;  // Variable to store the maximum sum found

    for (int i = 0; i < n; i++) {
        sum += nums[i]; // Add the current element to the running sum

        max_sum = max(max_sum, sum); // Update max_sum if the running sum is greater

        if (sum < 0) {
            sum = 0; // Reset the running sum to 0 if it becomes negative
        }
    }

    return max_sum; // Return the maximum subarray sum
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = maxSubArray(nums);
    
    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}
