// Number of Unique Paths

// Given a M X N matrix, you start from the top left, and you have to reach the bottom right.
// Find the number of ways in which you can reach the destination.

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    // dp[j] represents the number of unique paths to reach each cell in the current row
    vector<int> dp(n, 0);

    for (int i = 0; i < m; i++) {
        // temp vector to store the number of unique paths for the current row
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                // Starting point: there's only one way to be at the start
                temp[0] = 1;
            } else {
                // Initialize paths coming from left and above
                int goLeft = 0, goUp = 0;
                if (j > 0)
                    goLeft = temp[j - 1]; // Path from the left cell
                if (i > 0)
                    goUp = dp[j]; // Path from the cell above

                // Sum of paths coming from left and above
                temp[j] = goLeft + goUp;
            }
        }
        // Update dp with temp for the next row calculations
        dp = temp;
    }

    // The bottom-right corner will have the total number of unique paths
    return dp[n - 1];
}

int main() {
    int m = 3; // Number of rows
    int n = 3; // Number of columns

    // Call the function and print the result
    int result = uniquePaths(m, n);
    cout << "Number of unique paths from top-left to bottom-right: " << result << endl;

    return 0;
}
