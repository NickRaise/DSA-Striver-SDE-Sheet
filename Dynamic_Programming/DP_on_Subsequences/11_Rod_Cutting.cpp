// Rod Cutting

// Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. 
// Determine the maximum value obtainable by cutting up the rod and selling the pieces.
// Note: Consider 1-based indexing.

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by 
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.

#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n+1, -1);  // DP array to store the maximum profit for each rod length

    // Initialize the DP array for the first piece (length 1)
    for(int roadlen = 0; roadlen <= n; roadlen++) 
        dp[roadlen] = roadlen * price[0];  // For a rod of length roadlen, the maximum profit is roadlen times the price of a 1-unit rod

    // Iterate over the remaining pieces
    for(int idx = 1; idx < n; idx++) {
        vector<int> currentRow(n+1, -1);  // Temporary array to store the current row's results
        for(int target = 0; target <= n; target++) {
            int currentNotTaken = dp[target];  // Case where the current piece is not taken
            int currentTaken = 0;  // Case where the current piece is taken
            if(idx + 1 <= target)  // If the current piece can fit into the rod
                currentTaken = price[idx] + currentRow[target - (idx + 1)];  // Add the current piece's price and solve for the remaining rod length
            
            currentRow[target] = max(currentTaken, currentNotTaken);  // Take the maximum of both cases
        }
        dp = currentRow;  // Update the DP array with the current row's results
    }

    return dp[n];  // Return the maximum profit for the full rod length
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};  // Example prices for lengths 1 to 8
    int n = 8;  // Example rod length

    int result = cutRod(price, n);  // Call the function
    cout << "Maximum profit: " << result << endl;  // Output the result

    return 0;
}
