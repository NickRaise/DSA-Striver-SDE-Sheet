// Program to generate Pascal’s Triangle
// Given row number r and column number c. 
// Print the element at position (r, c) in Pascal’s triangle.

// Example 1:
// Input Format:r = 5, c = 3
// Result: 6 (for variation 1)


// Pascal Triangle
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1    




#include <iostream>

using namespace std;

// Function to calculate the element at row r and column c in Pascal's Triangle
int getPascalsTriangleElement(int r, int c) {
    int pro = 1;
    for (int i = 0; i < c - 1; i++) {
        pro = pro * (r - 1 - i);
        pro = pro / (i + 1);
    }
    return pro;
}

int main() {
    int r, c;

    // Prompt the user to enter the row number (r)
    cout << "Enter the row number (r): ";
    cin >> r;

    // Prompt the user to enter the column number (c)
    cout << "Enter the column number (c): ";
    cin >> c;

    // Check if the column number (c) is greater than the row number (r)
    if (c > r) {
        cout << "Column number (c) cannot be greater than row number (r)." << endl;
    } else {
        // If c is less than or equal to r, call the getPascalsTriangleElement function to calculate the element
        int element = getPascalsTriangleElement(r, c);
        cout << "Element at position (" << r << ", " << c << ") in Pascal's Triangle: " << element << endl;
    }

    return 0;
}
