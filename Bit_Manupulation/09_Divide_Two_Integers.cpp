// Divide Two Integers without using Divide and Multiply operator


#include <bits/stdc++.h>
using namespace std;

int divideTwoInteger(int dividend, int divisor) {
    // Handle special case of division by zero
    if (divisor == 0) {
        return INT_MAX;
    }
    
    // Handle special case of division by one
    if (divisor == 1) {
        return dividend;
    }
    
    // Handle special case where dividend is INT_MIN and divisor is -1
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    
    // Determine the sign of the result
    bool negative = (dividend < 0) ^ (divisor < 0);
    
    // Convert both dividend and divisor to long to handle edge cases
    long n = labs(dividend);
    long d = labs(divisor);
    
    // Initialize result and count of shifts
    long quotient = 0;
    
    // Perform bitwise division
    while (n >= d) {
        long temp = d;
        long multiple = 1;
        
        // Shift divisor left until it's larger than dividend
        while (n >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        
        // Subtract the largest shifted divisor from dividend
        n -= temp;
        
        // Accumulate the quotient
        quotient += multiple;
    }
    
    // Apply sign to the quotient
    return negative ? -quotient : quotient;
}

int main() {
    // Example input
    int dividend = 10;
    int divisor = 3;
    
    // Get the output
    int result = divideTwoInteger(dividend, divisor);
    
    // Print the result to the console
    cout << "The result of dividing " << dividend << " by " << divisor << " is: " << result << endl;
    
    return 0;
}

/*
Explanation of the divideTwoInteger function:
1. Handle special cases:
   - If `divisor` is 0, return `INT_MAX` to indicate an error (division by zero is undefined).
   - If `divisor` is 1, return `dividend` as the result directly.
   - If `dividend` is `INT_MIN` and `divisor` is -1, return `INT_MAX` to avoid overflow.
2. Determine the sign of the result based on the signs of `dividend` and `divisor`.
3. Convert both `dividend` and `divisor` to their absolute values using `labs` to handle negative numbers.
4. Initialize `quotient` to 0.
5. Perform bitwise division:
   - While the absolute value of `dividend` (n) is greater than or equal to the absolute value of `divisor` (d):
     - Initialize `temp` to `d` and `multiple` to 1.
     - Shift `temp` and `multiple` left until `temp` is greater than `n`.
     - Subtract the largest shifted `temp` from `n` and add the corresponding `multiple` to `quotient`.
6. Apply the determined sign to `quotient`.
7. Return the `quotient`.

The `main` function demonstrates the usage of the `divideTwoInteger` function with an example input and prints the result.
*/
