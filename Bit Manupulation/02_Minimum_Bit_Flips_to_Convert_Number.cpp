// Minimum Bit Flips to Convert Number

// Input: start = 10, goal = 7
// Output: 3
// Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
// - Flip the first bit from the right: 1010 -> 1011.
// - Flip the third bit from the right: 1011 -> 1111.
// - Flip the fourth bit from the right: 1111 -> 0111.
// It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.


#include <bits/stdc++.h>
using namespace std;

// Function to count the number of set bits in a number
int countBits(int n) {
    int cnt = 0;  // Initialize counter to count set bits
    while (n > 0) {
        cnt++;  // Increment counter for each set bit
        n = n & (n - 1);  // Remove the lowest set bit
    }
    return cnt;  // Return the total count of set bits
}

// Function to calculate the number of bit flips required to convert 'a' to 'b'
int numberOfFlips(int a, int b) {
    int res = a ^ b;  // XOR 'a' and 'b' to find differing bits
    int cnt = countBits(res);  // Count the number of differing bits
    return cnt;  // Return the count of differing bits
}

int main() {
    // Example inputs
    int a1 = 29;  // Binary: 11101
    int b1 = 15;  // Binary: 01111

    int a2 = 10;  // Binary: 1010
    int b2 = 20;  // Binary: 10100

    // Get the outputs for the example inputs
    int flips1 = numberOfFlips(a1, b1);
    int flips2 = numberOfFlips(a2, b2);

    // Print the results to the console
    cout << "Number of bit flips to convert " << a1 << " to " << b1 << ": " << flips1 << endl;
    cout << "Number of bit flips to convert " << a2 << " to " << b2 << ": " << flips2 << endl;

    return 0;
}

/*
Explanation of the countBits function:
1. Initialize `cnt` to 0 to keep track of the number of set bits.
2. Use a while loop to iterate as long as `n` is greater than 0.
3. For each iteration:
   - Increment `cnt` to account for the current set bit.
   - Update `n` to `n & (n - 1)` to remove the lowest set bit.
4. Return `cnt`, which contains the total number of set bits.

Explanation of the numberOfFlips function:
1. Calculate `res` as the result of XORing `a` and `b`, which highlights the differing bits.
2. Use the countBits function to count the number of set bits in `res`, which indicates the number of bit flips required.
3. Return the count of differing bits.

The `main` function demonstrates the usage of the `numberOfFlips` function with example inputs and prints the results.
*/
