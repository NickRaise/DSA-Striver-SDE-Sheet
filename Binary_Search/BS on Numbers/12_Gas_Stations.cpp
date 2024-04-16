// Minimise Maximum Distance between Gas Stations

// Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. 
// You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them anywhere on the non-negative side of the X-axis, 
// even on non-integer positions. Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
// Find the minimum value of ‘dist’.

// Note: Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer is 0.65421678124, it is okay to return 0.654216. 
// Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.

// Input Format:
//  N = 5, arr[] = {1,2,3,4,5}, k = 4
// Result:
//  0.5
// Explanation:
//  One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum difference between adjacent gas stations is 0.5. 
//  Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this. 




#include <bits/stdc++.h> // includes most standard libraries
using namespace std;

// Function to check if it is possible to achieve the given number of gas stations with a maximum distance between them
bool isPossible(vector<int> &stations, int K, double mid) {
    int gasStationCnt = 0;
    int n = stations.size();
    for (int i = 0; i < n - 1; i++) {
        int numOfGasStationInBetween = 0;
        int diff = stations[i + 1] - stations[i];
        
        // Calculate the number of gas stations that can be placed between the current pair of stations with a given maximum distance
        numOfGasStationInBetween = diff / mid; 
        
        // Adjust the number of gas stations if the exact distance allows an additional station
        if (stations[i+1] - stations[i] == numOfGasStationInBetween * mid)
            numOfGasStationInBetween--;
        
        // Increment the total count of gas stations
        gasStationCnt += numOfGasStationInBetween;
    }
    
    // Check if the total number of gas stations is less than or equal to the required number
    return gasStationCnt <= K;
}

// Function to minimize the maximum distance between gas stations
double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    double maxDifference = 0;
    
    // Calculate the maximum difference between consecutive gas stations
    for (int i = 0; i < n - 1; i++) {
        maxDifference = max(maxDifference, (double)arr[i + 1] - arr[i]);
    }
    
    // If no additional gas stations are allowed, return the maximum difference
    if (k == 0) return maxDifference;
    
    double left = 0, right = maxDifference, mid, ans = maxDifference;
    
    double diff = 1e-6; // tolerance for the binary search
    
    // Binary search to find the minimum maximum distance that satisfies the given condition
    while (right - left > diff) {
        mid = left + (right - left) / 2;
        
        if (isPossible(arr, k, mid)) {
            ans = mid;
            right = mid;
        } else {
            left = mid;
        }
    }
    
    return ans;
}

// Main function
int main() {
    // Example usage
    vector<int> stations = {1, 3, 6, 7, 9};
    int k = 3;
    cout << "Minimum maximum distance: " << minimiseMaxDistance(stations, k) << endl;
    return 0;
}
