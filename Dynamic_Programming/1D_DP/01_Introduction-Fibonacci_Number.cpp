// Fibonacci number using DP


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7; // Modulo value to prevent overflow
    vector<long long> dp; // Vector to store the results of subproblems for memoization

    // Constructor to initialize the dp vector with -1 for memoization
    Solution() : dp(10001, -1) {}

    // Top-down dynamic programming (recursive) approach to calculate nth Fibonacci number
    long long int topDown(int n) {
        // Base cases: F(0) = 0, F(1) = 1
        if(n <= 1) return n;
        // If the result for this subproblem is already computed, return it
        if(dp[n] != -1) return dp[n];
        // Otherwise, compute the result recursively and store it in dp vector
        dp[n] = (topDown(n - 1) + topDown(n - 2)) % mod;
        return dp[n];
    }

    // Bottom-up dynamic programming (iterative) approach to calculate nth Fibonacci number
    long long int bottomUp(int n) {
        // Edge case: if n <= 0, return n (F(0) = 0)
        if(n <= 0) return n;
        // Initializing the first two Fibonacci numbers
        long long prev = 1, prev2 = 0;
        // Iteratively compute the Fibonacci numbers up to n
        for(int i = 2; i <= n; i++) {
            int curr = (prev + prev2) % mod; // Current Fibonacci number
            prev2 = prev; // Update prev2 to the previous Fibonacci number
            prev = curr; // Update prev to the current Fibonacci number
        }
        return prev; // Return the nth Fibonacci number
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Calculate the nth Fibonacci number using top-down approach
    long long int topDownResult = sol.topDown(n);
    cout << "Top-down approach result: " << topDownResult << endl;

    // Calculate the nth Fibonacci number using bottom-up approach
    long long int bottomUpResult = sol.bottomUp(n);
    cout << "Bottom-up approach result: " << bottomUpResult << endl;

    return 0;
}
