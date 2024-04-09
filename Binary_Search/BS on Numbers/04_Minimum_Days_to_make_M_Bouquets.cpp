// Minimum days to make M bouquets

// Problem Statement: You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
// You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

// Input Format:
//  N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
// Result:
//  12
// Explanation:
//  On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.



#include <iostream>
#include <vector>
#include <algorithm> // Required for max_element

using namespace std;

// Function to check if it's possible to make enough bouquets with given roses, bouquet size, and within given days
int isSol(vector<int> arr, int roses, int bouquet, int days) {
    int bouquet_made = 0; // Number of bouquets made
    int roses_cnt = 0; // Counter for roses in a bouquet

    // Iterate through each element in the array
    for(auto i : arr) {
        if(i <= days) { // If the rose can be used for making a bouquet within given days
            roses_cnt++; // Increment the rose count
            if(roses_cnt == roses) { // If enough roses are collected for a bouquet
                bouquet_made++; // Increment the bouquet count
                roses_cnt = 0; // Reset the rose count for the next bouquet
            }
        }
        else {
            roses_cnt = 0; // Reset the rose count if the current rose cannot be used
        }
    }
    return bouquet_made; // Return the number of bouquets made
}

// Function to find the minimum number of days required to make 'm' bouquets with 'k' roses each
int roseGarden(vector<int> arr, int k, int m) {
    int max_ele = *max_element(arr.begin(), arr.end()); // Find the maximum element in the array
    int left = 1, right = max_ele, mid; // Initialize left and right pointers for binary search
    int ans = -1; // Initialize the answer variable to -1

    // Binary search to find the minimum number of days
    while(left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle value

        if(isSol(arr, k, m, mid) >= m) { // If it's possible to make 'm' bouquets within 'mid' days
            ans = mid; // Update the answer
            right = mid - 1; // Move to the left half
        }
        else {
            left = mid + 1; // Move to the right half
        }
    }

    return ans; // Return the answer
}

int main() {
    // Example usage
    vector<int> roses = {2, 4, 5, 1, 6, 7, 8}; // Roses available each day
    int k = 2; // Number of roses required for each bouquet
    int m = 3; // Number of bouquets to be made

    int min_days = roseGarden(roses, k, m);
    cout << "Minimum number of days required to make " << m << " bouquets with " << k << " roses each: " << min_days << endl;

    return 0;
}
