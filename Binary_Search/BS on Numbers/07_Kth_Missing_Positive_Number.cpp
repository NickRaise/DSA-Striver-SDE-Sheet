// Kth Missing Positive Number

// Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. 
// Find the 'kth' positive integer missing from 'vec'.

// Example 1:
// Input Format:
//  vec[]={4,7,9,10}, k = 1
// Result:
//  1
// Explanation:
//  The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.
// Example 2:
// Input Format:
//  vec[]={4,7,9,10}, k = 4
// Result:
//  5
// Explanation:
//  The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 4, the fourth missing element is 5.


#include <bits/stdc++.h>
using namespace std;

// Function to find the kth missing element in a sorted array
int missingK(vector<int> vec, int n, int k) {
    int low = 0, high = n - 1, mid;

    // Perform binary search
    while (low <= high) {
        mid = low + (high - low) / 2;
        int missing = vec[mid] - mid - 1;

        // If the number of missing elements before the current element is less than k
        if (missing < k)
            low = mid + 1; // Move to the right half
        else
            high = mid - 1; // Otherwise, move to the left half
    }

    // high and low will be pointing to the two elements between which our number will lie
    // high will be at the lower element and low will point to the higher element
    // kth missing element = vec[high] + more
    // where more = k - missing_till_current_element
    // missing = vec[high] - high - 1 
    // So, kth missing element = vec[high] + more => high + k + 1
    return high + k + 1;
}

int main() {
    // Example usage
    vector<int> arr = {2, 4, 7, 10, 12}; // Sorted array
    int n = arr.size(); // Size of the array
    int k = 5; // Find the 5th missing element

    // Call the function and print the result
    cout << "The " << k << "th missing element is: " << missingK(arr, n, k) << endl;

    return 0;
}
