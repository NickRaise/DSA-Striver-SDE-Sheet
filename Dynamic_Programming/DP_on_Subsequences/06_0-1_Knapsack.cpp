// 0 1 Knapsack

// Input: W = 4, val[] = {1,2,3}, wt[] = {4,5,1}
// Output: 3
// Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 

#include <bits/stdc++.h>
using namespace std;

// Function to solve the 0/1 Knapsack problem
// weight: vector containing the weights of the items
// value: vector containing the values of the items
// n: number of items
// maxWeight: maximum weight capacity of the knapsack
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // Initialize a DP array to store the maximum value for each possible weight
    vector<int> dp(maxWeight + 1, 0);
    
    // Base case: For the first item, fill the dp array for weights from weight[0] to maxWeight
    for(int j = weight[0]; j <= maxWeight; j++) {
        dp[j] = value[0]; // If we include the first item, we can get its value for these weights
    }
    
    // Iterate through the rest of the items
    for(int idx = 1; idx < n; idx++) {
        // Iterate in reverse to avoid overwriting dp[j-weight[idx]] before it's used
        for(int j = maxWeight; j >= weight[idx]; j--) {
            // Calculate the value if we pick the current item
            int currentPicked = value[idx] + dp[j - weight[idx]];
            // Update dp[j] with the maximum of picking or not picking the current item
            dp[j] = max(dp[j], currentPicked);
        }
    }

    // The maximum value that can be achieved with the given weight capacity
    return dp[maxWeight];
}

int main() {
    vector<int> weight = {1, 3, 4, 5}; // Weights of the items
    vector<int> value = {1, 4, 5, 7};  // Values of the items
    int n = weight.size();              // Number of items
    int maxWeight = 7;                  // Maximum weight capacity of the knapsack

    // Call the knapsack function and print the result
    int result = knapsack(weight, value, n, maxWeight);
    cout << "The maximum value that can be achieved is: " << result << endl;

    return 0;
}
