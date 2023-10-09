// Set Matrix Zero

// Problem Statement: Given a matrix if an element in the matrix is 0 
// then you will have to set its entire column and row to 0 and then return the matrix.

// Example 1:
// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.
 
// Example 2:
// Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0




#include <bits/stdc++.h>
using namespace std;

// Function to set entire row and column to 0 if any element in the corresponding row or column is 0
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    int col0 = 1; // A flag to track if the first column should be zeroed out

    // First pass: Mark rows and columns that need to be zeroed
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark the first element of the corresponding row as 0
                if(j != 0) {
                    matrix[0][j] = 0; // Mark the first element of the corresponding column as 0
                }
                else {
                    col0 = 0; // Set the col0 flag to 0 for the first column
                }
            }
        }
    }

    // Second pass: Zero out elements based on the marks
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] != 0) {
                // If either the first element of the row or column is marked as 0, zero out the current element
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
    }

    // Zero out the first row if the first element was marked
    if(matrix[0][0] == 0) {
        for(int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Zero out the first column if the col0 flag was set
    if(col0 == 0) {
        for(int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the matrix elements row by row:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> result = zeroMatrix(matrix, n, m);

    cout << "Matrix after zeroing out rows and columns:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
