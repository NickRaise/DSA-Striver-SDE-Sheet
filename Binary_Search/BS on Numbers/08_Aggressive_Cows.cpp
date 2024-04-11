// Aggressive Cows

// Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
// You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

// Input Format:
//  N = 6, k = 4, arr[] = {0,3,4,7,10,9}
// Result:
//  3
// Explanation:
//  The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. 
//  We cannot make the minimum distance greater than 3 in any ways.


#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to place 'k' cows with a minimum distance 'distance'
bool isPossible(vector<int> &arr, int k, int distance) {
    int cow_cnt = 1, n = arr.size();
    int cow_placed = arr[0]; // Initially place a cow at the first stall
    for(int i = 1; i < n; i++) {
        // If the distance between the current stall and the previously placed cow
        // is greater than or equal to 'distance', place a cow at the current stall
        if(arr[i] - cow_placed >= distance) {
            cow_cnt++; // Increase the count of placed cows
            cow_placed = arr[i]; // Update the position of the last placed cow
        }
        // If the number of placed cows is equal to 'k', return true
        if(cow_cnt >= k) return true;
    }
    // If the number of placed cows is less than 'k', return false
    return false;
}

// Function to find the maximum minimum distance such that 'k' cows can be placed
int aggressiveCows(vector<int> &arr, int k)
{
    // Sorting the stalls' positions in ascending order
    sort(arr.begin(), arr.end());
    int left = 1, right = arr[arr.size() - 1], mid; // Initialize the search space
    int ans; // Variable to store the result
    while(left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle distance
        // If it is possible to place 'k' cows with a minimum distance 'mid'
        if(isPossible(arr, k, mid)) {
            ans = mid; // Update the answer to the current minimum distance
            left = mid + 1; // Move to the right half of the search space
        }
        else {
            right = mid - 1; // Otherwise, move to the left half of the search space
        }
    }
    return ans; // Return the maximum minimum distance
}

int main() {
    // Example usage
    vector<int> stalls = {1, 2, 4, 8, 9}; // Stalls' positions
    int k = 3; // Number of cows

    // Find the maximum minimum distance such that 'k' cows can be placed
    cout << "Maximum minimum distance: " << aggressiveCows(stalls, k) << endl;

    return 0;
}
