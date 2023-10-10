// Spiral Traversal of Matrix
// Problem Statement: Given a Matrix, print the given matrix in spiral order.

// Example 1:
// Input: Matrix[][] = { {  1,  2,  3,  4 },
// 		              {  5,  6,  7,  8 },
// 		              {  9, 10, 11, 12 },
// 	                  { 13, 14, 15, 16 } }

// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.


#include <iostream>
#include <vector>

using namespace std;

// Function to traverse a matrix in a spiral order
vector<int> spiralMatrix(vector<vector<int>>& MATRIX) {
    int n = MATRIX.size();    // Number of rows in the matrix
    int m = MATRIX[0].size(); // Number of columns in the matrix

    vector<int> ans; // Initialize a vector to store the result

    int top = 0;     // Initialize the top row index
    int bottom = n - 1; // Initialize the bottom row index
    int left = 0;    // Initialize the leftmost column index
    int right = m - 1; // Initialize the rightmost column index

    // Traverse the matrix in a spiral order
    while (top <= bottom && left <= right) {
        // Traverse the top row from left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(MATRIX[top][i]);
        }
        top++; // Move to the next row

        // Traverse the rightmost column from top to bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(MATRIX[i][right]);
        }
        right--; // Move to the previous column

        // Check if there's a remaining row to traverse
        if (top <= bottom) {
            // Traverse the bottom row from right to left
            for (int i = right; i >= left; i--) {
                ans.push_back(MATRIX[bottom][i]);
            }
            bottom--; // Move to the previous row
        }

        // Check if there's a remaining column to traverse
        if (left <= right) {
            // Traverse the leftmost column from bottom to top
            for (int i = bottom; i >= top; i--) {
                ans.push_back(MATRIX[i][left]);
            }
            left++; // Move to the next column
        }
    }

    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralMatrix(matrix);

    cout << "Spiral Order Traversal:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
