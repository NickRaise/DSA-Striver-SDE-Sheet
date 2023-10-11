// Count Subarray sum Equals K
// Problem Statement: Given an array of integers and an integer k, 
// return the total number of subarrays whose sum equals k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input Format: N = 4, array[] = {3, 1, 2, 4}, k = 6
// Result: 2
// Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].



#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    // Create an unordered map to store the cumulative sum and its frequency
    unordered_map<int, int> mp;

    int sum = 0;  // Initialize the cumulative sum to 0
    int count = 0;  // Initialize the count of subarrays with sum equal to k

    mp[0] = 1;  // Initialize the map with a sum of 0 (needed for subarrays that start at index 0)

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];  // Update the cumulative sum

        // Calculate the remainder, which is the difference between the current sum and k
        int rem = sum - k;

        // If the remainder (rem) exists in the map, it means we have seen a subarray
        // with a sum of k within the current range. Increment the count by the frequency
        // of the remainder in the map.
        count += mp[rem];

        // Update the map by incrementing the frequency of the current sum.
        mp[sum]++;

        // The map stores the frequency of cumulative sums encountered so far.
        // This allows us to keep track of how many subarrays have a sum equal to k.
    }

    return count;  // Return the total count of subarrays with sum equal to k
}

int main() {
    // Input vector of integers
    vector<int> nums = {1, 2, 3, 4, 2, -2, 1};
    
    int k = 5;  // The target sum k
    
    // Call the subarraySum function to find the count of subarrays with sum equal to k
    int result = subarraySum(nums, k);
    
    // Output the result
    cout << "Count of subarrays with sum " << k << " is: " << result << endl;
    
    return 0;
}
