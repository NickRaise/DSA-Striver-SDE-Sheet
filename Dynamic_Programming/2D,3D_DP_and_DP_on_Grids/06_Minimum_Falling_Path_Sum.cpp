#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;

    int m = matrix[0].size();
    if (m == 0) return 0;

    vector<int> dp(m, INT_MAX); 

    // Initialize dp for the last row (base case)
    for(int j = 0; j < m; j++) {
        dp[j] = matrix[n-1][j];
    }

    // Iterate from the second-to-last row up to the first row
    for(int i = n - 2; i >= 0; i--) {
        vector<int> currentRow(m, INT_MAX);
        
        for(int j = 0; j < m; j++) {
            // Possible directions to move: down, down-left, down-right
            int goDown = dp[j];  // Directly below
            int goDiagonalLeft = (j > 0) ? dp[j - 1] : INT_MAX;  // Diagonally left
            int goDiagonalRight = (j < m - 1) ? dp[j + 1] : INT_MAX;  // Diagonally right
            
            // Calculate the minimum path sum for the current cell
            int minSum = min(goDown, min(goDiagonalLeft, goDiagonalRight));
            currentRow[j] = matrix[i][j] + minSum;
        }

        // Update dp to reflect the current row's results
        dp = currentRow;
    }

    // Find the minimum value in the dp array, which represents the minimum falling path sum
    int minAns = *min_element(dp.begin(), dp.end());

    return minAns;  
}

int main() {
    // Example input matrix
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    
    // Calculate the minimum falling path sum
    int result = minFallingPathSum(matrix);
    
    // Output the result
    cout << "Minimum Falling Path Sum: " << result << endl;
    
    return 0;
}
