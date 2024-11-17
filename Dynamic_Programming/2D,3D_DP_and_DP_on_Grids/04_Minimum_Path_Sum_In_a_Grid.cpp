// Minimum Path Sum In a Grid

// We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such that there is a minimum cost past that we select.

// At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix.

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();     // Number of rows
    int m = grid[0].size();  // Number of columns
    
    // dp[j] will store the minimum path sum to reach each cell in the current row
    vector<int> dp(m, -1);

    // Loop through each cell in the grid
    for (int i = 0; i < n; i++) {
        // Temporary vector to store the minimum path sum for the current row
        vector<int> currentRow(m, -1);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                // Starting point: the minimum sum is the value of the top-left corner itself
                currentRow[0] = grid[0][0];
            } else {
                // Initialize the minimum path sums from the left and above cells
                int goUp = INT_MAX, goLeft = INT_MAX;
                if (i > 0) goUp = dp[j];         // Path sum from the cell above
                if (j > 0) goLeft = currentRow[j-1]; // Path sum from the cell to the left
                
                // Calculate the minimum path sum to reach the current cell
                if (goUp == INT_MAX && goLeft == INT_MAX) 
                    currentRow[j] = INT_MAX;  // If both paths are blocked, set the current cell to INT_MAX
                else {
                    // Minimum sum to reach this cell is the value of the current cell plus the minimum of the two possible paths
                    currentRow[j] = grid[i][j] + min(goUp, goLeft);
                }
            }
        }
        // Update dp with the values from the current row
        dp = currentRow;
    }

    // The bottom-right corner will have the minimum path sum
    return dp[m-1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = minSumPath(grid);
    cout << "The minimum path sum from top-left to bottom-right is: " << result << endl;

    return 0;
}
