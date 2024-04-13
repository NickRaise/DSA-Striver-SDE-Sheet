// Split Array - Largest Sum

// Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. 
// Your task is to return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

//  N = 5, a[] = {1,2,3,4,5}, k = 3
// Result:
//  6
// Explanation:
//  There are many ways to split the array a[] into k consecutive subarrays. The best way to do this is to split the array a[] into [1, 2, 3], [4], and [5], 
//  where the largest sum among the three subarrays is only 6.




#include<bits/stdc++.h>
using namespace std;

// Function to check if it's possible to divide the array into subarrays such that each subarray sum <= num
bool isPossible(vector<int> a, int k, int num) {
    int sum = 0;
    int cnt = 0;

    // Iterate through the array
    for(int i=0; i<a.size(); i++) {
        // If adding the current element exceeds num, start a new subarray
        if(sum + a[i] > num) {
            cnt++;
            sum = a[i];
        }
        else {
            // Otherwise, add the current element to the current subarray
            sum += a[i];
        }
    }
    // If there's still a remaining subarray, count it
    if(sum != 0) cnt++;

    // If the count of subarrays is less than or equal to k, it's possible
    if(cnt <= k) return true;
    return false;
}

// Function to find the largest subarray sum minimized
int largestSubarraySumMinimized(vector<int> a, int k) {
    // Initialize left as the maximum element in the array
    int left = *max_element(a.begin(), a.end()), 
    // Initialize right as the sum of all elements in the array
        right = accumulate(a.begin(), a.end(), 0), mid;
    int ans = -1;
    
    // Perform binary search to find the maximum sum that satisfies the condition
    while(left <= right) {
        mid = left + (right - left) / 2;

        // If it's possible to minimize the largest subarray sum to mid
        if(isPossible(a, k, mid)) {
            // Update ans and search in the left half
            ans = mid;
            right = mid - 1;
        }
        else    
            // Otherwise, search in the right half
            left = mid + 1;
    }
    return ans;
}

int main() {
    // Sample usage of the function
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    cout << largestSubarraySumMinimized(arr, k); // Output the result
    return 0;
}
