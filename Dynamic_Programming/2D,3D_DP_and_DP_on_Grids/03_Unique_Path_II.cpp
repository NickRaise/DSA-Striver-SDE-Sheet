// Unique Path II

// Follow up of Unique path:
// An obstacle and space are marked as 1 or 0 respectively in grid. 
// A path that the robot takes cannot include any square that is an obstacle.

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right


#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.size() == 0) return 0; // If the grid is empty, return 0

    int n = obstacleGrid.size();    // Number of rows
    int m = obstacleGrid[0].size(); // Number of columns

    // dp[j] represents the number of unique paths to reach each cell in the current row
    vector<int> dp(m, -1);

    for (int i = 0; i < n; i++) {
        // currentRow vector to store the number of unique paths for the current row
        vector<int> currentRow(m, -1);
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[i][j] == 1) {
                // If there's an obstacle in the cell, set paths to 0
                currentRow[j] = 0;
            } else if (i == 0 && j == 0) {
                // Starting point: there's only one way to be at the start if it's not an obstacle
                currentRow[0] = 1;
            } else {
                // Initialize paths coming from left and above
                int goUp = 0, goLeft = 0;
                if (i > 0)
                    goUp = dp[j]; // Path from the cell above
                if (j > 0)
                    goLeft = currentRow[j - 1]; // Path from the left cell
                // Sum of paths coming from left and above
                currentRow[j] = goUp + goLeft;
            }
        }
        // Update dp with currentRow for the next row calculations
        dp = currentRow;
    }

    // The bottom-right corner will have the total number of unique paths
    return dp[m - 1];
}

int main() {
    // Example grid with obstacles
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    // Call the function and print the result
    int result = uniquePathsWithObstacles(obstacleGrid);
    cout << "Number of unique paths from top-left to bottom-right: " << result << endl;

    return 0;
}
