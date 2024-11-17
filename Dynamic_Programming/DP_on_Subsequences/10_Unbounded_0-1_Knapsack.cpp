// Unbounded Knapsack

// You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.
// You need to fill the knapsack with the items in such a way that you get the maximum profit. 
// You are allowed to take one item multiple times.




#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<int> dp(w+1, 0);  // DP array to store the maximum profit for each weight limit

    // Initialize the DP array for the first item
    for(int W = 0; W <= w; W++) {
        dp[W] = (W / weight[0]) * profit[0];  // For weight W, the maximum profit is obtained by taking as many of the first item as possible
    }

    // Iterate over the remaining items
    for(int idx = 1; idx < n; idx++) {
        vector<int> currentRow(w+1, 0);  // Temporary array to store the current row's results
        for(int target = 0; target <= w; target++) {
            int currentNotTaken = dp[target];  // Case where the current item is not included
            int currentTaken = 0;  // Case where the current item is included
            if(weight[idx] <= target)
                currentTaken = profit[idx] + currentRow[target - weight[idx]];  // If the item can be taken, add its profit to the profit of the remaining weight
            
            currentRow[target] = max(currentTaken, currentNotTaken);  // Take the maximum of both cases
        }
        dp = currentRow;  // Update the DP array with the current row's results
    }

    return dp[w];  // Return the maximum profit that can be achieved with the given weight limit
}

int main() {
    vector<int> profit = {10, 30, 20};  // Example profits
    vector<int> weight = {5, 10, 15};  // Example weights
    int n = profit.size();  // Number of items
    int w = 100;  // Maximum weight capacity

    int result = unboundedKnapsack(n, w, profit, weight);  // Call the function
    cout << "Maximum profit: " << result << endl;  // Output the result

    return 0;
}
