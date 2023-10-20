// Longest Subarray with sum K | [Postives and Negatives]
// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

// Example 1:
// Input Format: N = 3, k = 5, array[] = {2,3,5}
// Result: 2
// Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Example 2:
// Input Format: N = 3, k = 1, array[] = {-1, 1, 1}
// Result: 3
// Explanation: The longest subarray with sum 1 is {-1, 1, 1}. And its length is 3.




#include <iostream>
#include <vector>
#include <map>

using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    map<long long, int> sumPivot; // To store the sum and its corresponding pivot index
    long long sum = 0; // Initialize the current sum
    int maxi = 0; // Initialize the maximum length to 0

    for (int i = 0; i < a.size(); i++) {
        sum += a[i]; // Add the current element to the sum

        if (sum == k)
            maxi = i + 1; // If the current sum is equal to k, update maxi with the current index + 1 (the length of the subarray)

        long long rem = sum - k; // Calculate the remainder needed to reach k

        if (sumPivot.find(rem) != sumPivot.end()) {
            int len = i - sumPivot[rem]; // Calculate the length of subarray with sum equal to k
            maxi = max(maxi, len); // Update maxi if the current subarray is longer
        }

        if (sumPivot.find(sum) == sumPivot.end()) {
            sumPivot[sum] = i; // Store the pivot index for the current sum if not already present
        }
    }
    return maxi; // Return the maximum length of subarray with sum equal to k
}

int main() {
    vector<int> a = {10, 5, 2, 7, 1, 9};
    long long k = 15;

    int maxLength = longestSubarrayWithSumK(a, k);

    cout << "Maximum length of subarray with sum " << k << " is: " << maxLength << endl;

    return 0;
}
