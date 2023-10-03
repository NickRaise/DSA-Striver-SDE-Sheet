// Problem Statement: Given an array and a sum k, we need to print the length of 
// the longest subarray that sums to k.

// Example 1:
// Input Format: N = 3, k = 5, array[] = {2,3,5}
// Result: 2
// Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Example 2:
// Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
// Result: 3
// Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.





#include <iostream>
#include <vector>

using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0;  // Initialize two pointers at the start of the array
    int n = a.size();        // Get the size of the input array
    long long sum = a[0];    // Initialize the sum with the first element
    int maxi = 0;            // Initialize the maximum subarray length to 0

    while (right < n) {
        if (sum == k) {  // If the current sum equals the target sum k
            int len = right - left + 1;  // Calculate the length of the current subarray
            maxi = max(maxi, len);       // Update the maximum subarray length if needed
            right++;                      // Move the right pointer to the right
            if (right < n)
                sum += a[right];  // Add the new element to the sum
        } else if (sum < k) {  // If the current sum is less than k
            right++;             // Move the right pointer to the right
            if (right < n)
                sum += a[right];  // Add the new element to the sum
        } else {  // If the current sum is greater than k
            sum -= a[left];  // Remove the leftmost element from the sum
            left++;             // Move the left pointer to the right
        }
    }

    return maxi;  // Return the maximum subarray length with sum k
}

int main() {
    vector<int> a = {1, 2, 1, 0, 1, 2, 1};
    long long k = 3;
    
    int result = longestSubarrayWithSumK(a, k);
    
    cout << "Maximum subarray length with sum " << k << ": " << result << endl;

    return 0;
}
