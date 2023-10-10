// Rotate Image by 90 degree
// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

// Example 1:
// Input: [[1,2,3],
//         [4,5,6],
//         [7,8,9]]

// Output: [[7,4,1],
//          [8,5,2],
//          [9,6,3]]

// Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.


#include <iostream>
#include <vector>

using namespace std;

// Function to rotate a square matrix 90 degrees clockwise
void rotateMatrix(vector<vector<int>> &mat) {
    int n = mat.size(); // Get the size of the matrix (assuming it's a square matrix)

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Swap the elements at (i, j) and (j, i)
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each row of the transposed matrix
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    // Initialize the square matrix of size n x n
    vector<vector<int>> matrix(n, vector<int>(n));

    // Input the elements of the matrix
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Rotate the matrix 90 degrees clockwise
    rotateMatrix(matrix);

    // Output the rotated matrix
    cout << "Rotated Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
