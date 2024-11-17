// Frog jump II


// The frog was allowed to jump either one or two steps at a time. 
// In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index.

// Input: k = 3, arr[]= [10, 30, 40, 50, 20]
// Output: 30
// Explanation: Frog will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum


#include <bits/stdc++.h>
using namespace std;


// Function to calculate the minimum cost for the frog to reach the nth stone
int minimizeCost(int n, int k, vector<int> &height) {
    // Initialize a vector dp with size n and all elements set to -1
    vector<int> dp(n, -1);
    dp[0] = 0; // The cost to reach the first stone is 0

    // Loop through each stone starting from the second stone (index 1)
    for(int idx = 1; idx < n; idx++) {
        int minValue = INT_MAX; // Initialize minValue to a large value

        // Loop through the possible jumps from 1 to k
        for(int j = 1; j <= k; j++) {
            // Check if the jump is valid (within bounds)
            if(idx - j >= 0) {
                // Calculate the cost to jump from the stone at idx - j to the current stone
                int jumpCost = dp[idx - j] + abs(height[idx] - height[idx - j]);
                // Update minValue with the minimum cost found
                minValue = min(minValue, jumpCost);
            }
        }
        // Store the minimum cost to reach the current stone in dp
        dp[idx] = minValue;
    }

    // Return the minimum cost to reach the nth stone
    return dp[n-1];
}

int main() {
    int n = 5; // Predefined number of stones
    int k = 3; // Maximum jump length
    vector<int> height = {10, 30, 40, 50, 20}; // Predefined heights of the stones

    // Call the function and print the result
    int result = minimizeCost(n, k, height);
    cout << "Minimum cost for the frog to reach the " << n << "th stone: " << result << endl;

    return 0;
}
