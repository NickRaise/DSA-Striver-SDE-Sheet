// Climbing Stairs

// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step


#include <bits/stdc++.h>
using namespace std;

// Function to count the number of distinct ways to climb to the top of n stairs
int countDistinctWays(int nStairs) {
    // Base case: If there are 0 or 1 stairs, there is only 1 way to climb them
    if(nStairs <= 1) return 1;

    // Initialize the variables to store the number of ways to reach the previous two stairs
    int prev = 1, prev2 = 1;
    int mod = 1e9 + 7; // Modulo value to prevent overflow

    // Iterate from the 2nd stair to the nth stair
    for(int i = 2; i <= nStairs; i++) {
        // Calculate the number of ways to reach the current stair
        int curr = (prev + prev2) % mod;
        // Update the variables for the next iteration
        prev2 = prev;
        prev = curr;
    }

    // Return the number of ways to reach the nth stair
    return prev;
}

int main() {
    int nStairs;
    cout << "Enter the number of stairs: ";
    cin >> nStairs;

    // Call the function and print the result
    int result = countDistinctWays(nStairs);
    cout << "Number of distinct ways to climb to the top: " << result << endl;

    return 0;
}
