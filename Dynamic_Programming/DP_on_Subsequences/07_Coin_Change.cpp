// Coin Change

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// Example 1:
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1


#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();  // Number of different coins available
    int target = amount;   // The target amount we need to achieve
    vector<int> dp(target+1, 0);  // DP array to store the minimum number of coins required for each amount

    // Base case initialization
    // If the amount is a multiple of the first coin, set dp[i] to the number of coins required (i / coins[0])
    // Otherwise, set it to a large value (indicating it's not possible with just this coin)
    for(int i=0; i<=target; i++) {
        if(i % coins[0] == 0) dp[i] = i/coins[0];
        else dp[i] = 1e9;
    }  

    // Iterate through the remaining coins
    for(int idx=1; idx<n; idx++) {
        vector<int> currentRow(target+1, 0);  // Temporary array to store current row results
        for(int T=0; T<=target; T++) {
            int currentNotTaken = dp[T];  // Case where the current coin is not taken
            int currentTaken = INT_MAX;  // Case where the current coin is taken
            if(coins[idx] <= T)
                currentTaken = 1 + currentRow[T - coins[idx]];  // If the coin can be taken, update the number of coins
            currentRow[T] = min(currentTaken, currentNotTaken);  // Store the minimum of taking or not taking the coin
        }
        dp = currentRow;  // Update the dp array with the results of the current row
    }

    int ans = dp[target];  // The minimum number of coins needed for the target amount
    return ans >= 1e9 ? -1 : ans;  // If it's not possible to make the amount, return -1
}

int main() {
    vector<int> coins = {1, 2, 5};  // Example coins
    int amount = 11;  // Target amount

    int result = coinChange(coins, amount);  // Call the function
    cout << "Minimum coins required: " << result << endl;  // Print the result

    return 0;
}
