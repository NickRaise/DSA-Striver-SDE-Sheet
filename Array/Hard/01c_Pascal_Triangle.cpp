// Program to generate Pascal’s Triangle
// Given the number of rows n. Print the first n rows of Pascal’s triangle.

// Example 1:
// Input Format: N = 5
// Result:
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1    

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;

    // Iterate through rows from 0 to N-1
    for (int i = 0; i < N; i++) {
        vector<int> row;
        int pro = 1;  // Initialize the product to 1

        // Iterate through columns within the current row
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                // The first and last elements in each row are always 1
                row.push_back(1);
                continue;
            }

            // Calculate the value for the current position using the previous row's values
            pro *= (i - j + 1);
            pro /= j;

            row.push_back(pro);
        }

        // Add the current row to the Pascal's Triangle
        ans.push_back(row);
    }

    return ans;
}

int main() {
    int N;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> N;

    vector<vector<int>> pascal = pascalTriangle(N);

    // Display Pascal's Triangle
    for (int i = 0; i < N; i++) {
        // Print leading spaces to center-align the triangle
        for (int s = 0; s < N - i; s++) {
            cout << "  ";
        }

        for (int j = 0; j <= i; j++) {
            cout << pascal[i][j] << "   ";  // Adjust spacing for readability
        }
        cout << endl;
    }

    return 0;
}
