// Minimum path sum in Triangular Grid

// We are given a Triangular matrix. We need to find the minimum path sum from the first row to the last row.
// At every cell we can move in only two directions: either to the bottom cell (↓) or to the bottom-right cell(↘).

// Test case 1:
// Here our triangle array is:
// 2
// 3 4
// 6 5 7 
// 4 1 8 3
// In this array, the minimum path will be 2->3->5->1, so the minimum sum path would be 2+3+5+1=11

#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>>& triangle, int n) {
    // dp[j] will store the minimum path sum to reach each element in the current row
    vector<int> dp(n, INT_MAX);
    
    // Initialize the first element since the path starts at the top of the triangle
    dp[0] = triangle[0][0];

    // Iterate through each row of the triangle
    for (int i = 0; i < n; i++) {
        // Temporary vector to store the minimum path sum for the current row
        vector<int> currentRow(i + 1, INT_MAX);
        
        for (int j = 0; j <= i; j++) {
            if (i == 0) {
                // For the first element, just assign the triangle's first value
                currentRow[j] = triangle[i][j];
            } else {
                // Initialize the possible paths from above
                int fromUp = INT_MAX, fromUpLeft = INT_MAX;
                
                // Check if the current position has a path from directly above
                if (j <= i) fromUp = dp[j];
                
                // Check if the current position has a path from the left diagonal
                if (j > 0) fromUpLeft = dp[j - 1];
                
                // Calculate the minimum path sum to reach this element
                currentRow[j] = triangle[i][j] + min(fromUp, fromUpLeft);
            }
        }
        
        // Update dp with the values from the current row
        dp = currentRow;
    }

    // Find the minimum path sum at the last row
    int minAns = INT_MAX;
    for (int j = 0; j < n; j++) {
        minAns = min(minAns, dp[j]);
    }
    
    // Return the minimum path sum
    return minAns;
}

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    
    int n = triangle.size();
    int result = minimumPathSum(triangle, n);
    
    cout << "The minimum path sum in the triangle is: " << result << endl;
    
    return 0;
}
