#include <iostream>
using namespace std;

double myPow(double x, int n) {
    double ans = 1;
    long long m = n;
    // If n is negative, convert it to positive and remember to take reciprocal at the end
    if(m < 0) m = -m;

    // Loop until m becomes 0
    while(m > 0) {
        // If m is odd, multiply ans by x and decrement m
        if(m % 2 == 1) {
            ans = ans * x;
            m--;
        }
        // If m is even, square x and halve m
        else {
            x = x * x;
            m /= 2;
        }
    }

    // If original n was negative, take reciprocal of the result
    if(n < 0) ans = 1.0 / ans;

    return ans;
}

int main() {
    // Example input
    double x = 2.0;
    int n = -3;
    
    // Calculate x raised to the power of n
    double result = myPow(x, n);
    
    // Print the result to the console
    cout << x << " raised to the power of " << n << " is: " << result << endl;
    
    return 0;
}

/*
Explanation of the myPow function:
1. **Initialization**:
   - Initialize `ans` to 1 to store the result.
   - Convert `n` to a long long `m` to handle large negative values. 
   - If `m` is negative, convert it to positive and remember to take the reciprocal of the result at the end.

2. **Exponentiation by Squaring**:
   - Loop until `m` becomes 0:
     - If `m` is odd (`m % 2 == 1`):
       - Multiply `ans` by `x` and decrement `m`.
     - If `m` is even:
       - Square `x` and halve `m`.

3. **Adjust for Negative Exponent**:
   - If the original `n` was negative, take the reciprocal of `ans`.

4. **Return Result**:
   - Return `ans` which contains the result of `x` raised to the power `n`.

The `main` function demonstrates the usage of the `myPow` function with an example input and prints the result.
*/
