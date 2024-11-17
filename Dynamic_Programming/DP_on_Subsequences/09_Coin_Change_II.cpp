// Coin Change 2

// We are given an array Arr with N distinct coins and a target. We have an infinite supply of each coin denomination. 
// We need to find the number of ways we sum up the coin values to give us the target.
// Each coin can be used any number of times.

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
    int n = coins.size();  // Number of different coin denominations
    vector<int> dp(amount + 1, 0);  // DP array to store the number of ways to make each amount

    // Initialize the DP array for the first coin denomination
    // If the amount T is divisible by the first coin, there's one way to make that amount
    for(int T = 0; T <= amount; T++) 
        dp[T] = (T % coins[0] == 0);

    // Iterate through the remaining coin denominations
    for(int idx = 1; idx < n; idx++) {
        vector<int> currentRow(amount + 1, 0);  // Temporary array to store the current row's results
        for(int target = 0; target <= amount; target++) {
            int currentNotTaken = dp[target];  // Case where the current coin is not used
            int currentTaken = 0;  // Case where the current coin is used
            if(coins[idx] <= target)
                currentTaken = currentRow[target - coins[idx]];  // If the coin can be taken, add the ways to form the remaining amount

            currentRow[target] = currentTaken + currentNotTaken;  // Combine both cases
        }
        dp = currentRow;  // Update the DP array with the current row's results
    }

    return dp[amount];  // Return the number of ways to make the target amount
}

int main() {
    vector<int> coins = {1, 2, 5};  // Example coin denominations
    int amount = 5;  // Example target amount

    int result = change(amount, coins);  // Call the function
    cout << "Number of ways to make the amount: " << result << endl;  // Output the result

    return 0;
}
