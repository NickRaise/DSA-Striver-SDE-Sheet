// Program to generate Pascal’s Triangle
// Given the row number n. Print the n-th row of Pascal’s triangle.

// Example 1:
// Input Format: N = 5, r = 5, c = 3
// Result:  1 4 6 4 1 

// Pascal Triangle
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1    


#include <bits/stdc++.h>
using namespace std;

void pascalTriangle(int n) {
    long long ans = 1;

    // First loop prints each row of Pascal's triangle
    for (int i = 0; i < n; i++) {
        // The first and last elements in each row are always 1
        if (i == 0 || i == n - 1) {
            cout << 1 << " ";
            continue; // Skip the remaining logic and print 1
        }

        // The logic to compute the elements between 1 and n-1
        // Use the formula for binomial coefficients (n choose k):
        // C(n, k) = n! / (k! * (n - k)!)
        ans = ans * (n - i);  // Compute the numerator part (n! / (n - i)!)
        ans = ans / (i);      // Divide by the denominator part (i!)

        cout << ans << " ";  // Print the computed value
    }
    cout << endl; // Move to the next row
}

int main() {
    int n = 5; // Number of rows in Pascal's triangle
    pascalTriangle(n); // Call the function to print Pascal's triangle
    return 0;
}
