// Count the number of subarrays with given xor K
// Problem Statement: Given an array of integers A and an integer B. 
// Find the total number of subarrays having bitwise XOR of all elements equal to k.

// Example 1:
// Input Format: A = [4, 2, 2, 6, 4] , k = 6
// Result: 4
// Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]


#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int b) {
    unordered_map<int, int> mp; // Create a map to store the cumulative XOR results.
    int n = a.size();
    int cal = 0; // Initialize the cumulative XOR to 0.
    int count = 0; // Initialize the count of subarrays with sum 'b' to 0.
    mp[cal]++; // Initialize the map with 0.

    for (int i = 0; i < n; i++) {
        cal = cal ^ a[i]; // Calculate the cumulative XOR up to the current element.

        int rem = cal ^ b; // Calculate the required remainder to achieve the sum 'b'.

        count = count + mp[rem]; // Add the count of subarrays that can form 'b' using the current remainder.

        mp[cal]++; // Update the map with the current cumulative XOR.
    }

    return count; // Return the total count of subarrays with sum 'b'.
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    int b = 7;
    
    int result = subarraysWithSumK(a, b);
    
    cout << "Number of subarrays with sum " << b << ": " << result << endl;
    
    return 0;
}
