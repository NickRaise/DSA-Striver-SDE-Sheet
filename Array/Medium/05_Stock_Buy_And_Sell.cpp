// Stock Buy And Sell
// Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. 
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and 
// sell on day 5 (price = 6), profit = 6-1 = 5.
// Note: That buying on day 2 and selling on day 1 
// is not allowed because you must buy before 
// you sell.

// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are 
// done and the max profit = 0.



#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int bestTimeToBuyAndSellStock(vector<int>& prices) {
    int min_price = INT_MAX; // Initialize the minimum price to a very large value
    int max_profit = 0; // Initialize the maximum profit to 0
    int n = prices.size(); // Get the number of days (size of the prices vector)
    int profit;

    for (int i = 0; i < n; i++) {
        min_price = min(min_price, prices[i]); // Update the minimum price if a lower price is encountered
        profit = prices[i] - min_price; // Calculate the profit if we sell at the current price
        max_profit = max(profit, max_profit); // Update the maximum profit if the current profit is higher
    }

    return max_profit; // Return the maximum profit achievable
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input: daily stock prices
    int result = bestTimeToBuyAndSellStock(prices); // Calculate the maximum profit
    cout << "Maximum Profit: " << result << endl; // Output the maximum profit
    return 0;
}
