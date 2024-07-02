// L to R XOR

// You are given two numbers 'L' and 'R'.
// Find the XOR of the elements in the range [L, R].

// Sample Input:
// 3 5
// Sample Output:
// 2
// Explanation of sample output 1:
// 'L' = 3 and ‘R’ = 5
// Answer is 2. Value of 3^4^5 is 2.


#include <iostream>
using namespace std;

// Function to compute XOR from 1 to N based on pattern observation
int numXOR(int N) {
    if (N % 4 == 1) return 1;
    else if (N % 4 == 2) return N + 1;
    else if (N % 4 == 3) return 0;
    else if (N % 4 == 0) return N;
    return 0;  // Added to handle all control paths
}

// Function to find the XOR of all numbers in the range [l, r]
int findXOR(int l, int r) {
    return numXOR(l - 1) ^ numXOR(r);
}

int main() {
    // Example input
    int l = 5;
    int r = 8;

    // Get the output
    int result = findXOR(l, r);

    // Print the result to the console
    cout << "The XOR of all numbers in the range [" << l << ", " << r << "] is: " << result << endl;

    return 0;
}

/*
Explanation of the numXOR function:
1. The function computes the XOR of all numbers from 1 to N based on the pattern:
   - If N % 4 == 1, the result is 1.
   - If N % 4 == 2, the result is N + 1.
   - If N % 4 == 3, the result is 0.
   - If N % 4 == 0, the result is N.
2. This pattern repeats every 4 numbers, simplifying the computation of the XOR from 1 to N.

Explanation of the findXOR function:
1. To find the XOR of all numbers in the range [l, r], use the property:
   XOR(l to r) = XOR(1 to r) ^ XOR(1 to l-1)
2. Call numXOR(l-1) to get XOR of numbers from 1 to l-1.
3. Call numXOR(r) to get XOR of numbers from 1 to r.
4. XOR the results of the above two calls to get the XOR of numbers from l to r.

The `main` function demonstrates the usage of the `findXOR` function with an example input and prints the result.
*/
