// Length of the longest subarray with zero Sum
// Problem Statement: Given an array containing both positive and negative integers, 
// we have to find the length of the longest subarray with the sum of all elements equal to zero.


// Example 1:
// Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
// Result: 5
// Explanation: The following subarrays sum to zero:
// {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
// Since we require the length of the longest subarray, our answer is 5!




#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subarray with a zero sum
int getLongestZeroSumSubarrayLength(vector<int> &arr) {
    int maxLen = 0; // Initialize the maximum length to 0
    unordered_map<int, int> mp; // Create an unordered map to store cumulative sums and their positions
    int n = arr.size(); // Get the size of the input array
    int sum = 0; // Initialize the cumulative sum to 0

    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Update the cumulative sum by adding the current element

        // If the cumulative sum is zero, update maxLen to the current index + 1
        if (sum == 0) {
            maxLen = i + 1;
        }

        int rem = sum; // Calculate the current remainder (cumulative sum)

        // Check if the remainder (cumulative sum) exists in the map
        if (mp.find(rem) != mp.end()) {
            int len = i - mp[rem]; // Calculate the length of the subarray with a zero sum
            maxLen = max(maxLen, len); // Update maxLen if the current subarray is longer
        } else {
            mp[sum] = i; // If the remainder doesn't exist in the map, store it with its position
        }
    }
    return maxLen; // Return the length of the longest subarray with a zero sum
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23}; // Sample input array
    int result = getLongestZeroSumSubarrayLength(arr);
    cout << "Length of the longest subarray with a zero sum: " << result << endl;

    return 0;
}
