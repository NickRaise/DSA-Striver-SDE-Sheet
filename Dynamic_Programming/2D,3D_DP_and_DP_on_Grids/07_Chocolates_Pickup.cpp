// Chocolates Pickup

// You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

// You have two robots that can collect chocolates for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of chocolates collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the chocolates.

// Input:
// n = 4, m = 3
// grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output:
// 24
// Explanation:
// Path of robot #1 and #2 are described in color green and blue respectively. Chocolates taken by Robot #1, (3 + 2 + 5 + 2) = 12. Chocolates taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of Chocolates: 12 + 12 = 24.


#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int n, int m, vector<vector<int>>& grid) {
    // dp[j1][j2] will store the maximum chocolates collected when the first robot
    // is at column j1 and the second robot is at column j2 in the current row.

    vector<vector<int>> dp(m, vector<int>(m, -1));

    // Initialize dp for the last row (base case)
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) dp[j1][j2] = grid[n - 1][j1]; // If both robots are on the same cell, count chocolates once
            else dp[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2]; // Else, count chocolates from both cells
        }
    }

    // Iterate from the second-to-last row to the top row
    for (int i = n - 2; i >= 0; i--) {
        vector<vector<int>> currentRow(m, vector<int>(m, INT_MIN)); // Temporary storage for the current row

        for (int j1 = 0; j1 < m; j1++) { // First robot's position
            for (int j2 = 0; j2 < m; j2++) { // Second robot's position
                int maxVal = INT_MIN; // Variable to track the maximum chocolates collected

                // Explore all possible moves for both robots (left, right, or stay)
                for (int A = -1; A <= 1; A++) {
                    for (int B = -1; B <= 1; B++) {
                        int newj1 = j1 + A; // New position for the first robot
                        int newj2 = j2 + B; // New position for the second robot
                        int currentValue = 0;

                        // Ensure both robots stay within the grid's boundaries
                        if (newj1 >= 0 && newj1 < m && newj2 >= 0 && newj2 < m) {
                            if (j1 == j2) 
                                currentValue = grid[i][j1]; // If both robots are on the same cell, count chocolates once
                            else 
                                currentValue = grid[i][j1] + grid[i][j2]; // Else, count chocolates from both cells

                            // Add the best possible chocolates collected from the next row
                            currentValue += dp[newj1][newj2];
                            maxVal = max(maxVal, currentValue); // Update maxVal with the maximum chocolates collected
                        }
                    }
                }
                currentRow[j1][j2] = maxVal; // Store the result in the current row's dp
            }
        }

        dp = currentRow; // Move to the next row, updating dp with currentRow values
    }

    // Return the maximum chocolates collected when starting from the top-left (0,0) and top-right (0,m-1) corners
    return dp[0][m - 1];
}

int main() {
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
        {8, 7, 4, 6}
    };
    int n = grid.size();
    int m = grid[0].size();

    int result = maximumChocolates(n, m, grid);
    cout << "The maximum chocolates that can be collected are: " << result << endl;

    return 0;
}







