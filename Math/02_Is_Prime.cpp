#include <iostream>
using namespace std;

int isPrime(int N) {
    // Handle edge cases for numbers less than 2
    if (N <= 1) return 0;

    // Check for factors from 2 to sqrt(N)
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) return 0; // Not a prime number if divisible by i
    }

    return 1; // N is a prime number
}

int main() {
    // Example input
    int N = 29;
    
    // Check if N is prime
    int result = isPrime(N);
    
    // Print the result to the console
    if (result == 1)
        cout << N << " is a prime number." << endl;
    else
        cout << N << " is not a prime number." << endl;
    
    return 0;
}

/*
Explanation of the isPrime function:
1. **Edge Case Handling**:
   - If `N` is less than or equal to 1, return `0` because numbers less than 2 are not prime.
   
2. **Loop through Possible Factors**:
   - Loop from `2` to `sqrt(N)` (i.e., while `i * i <= N`):
     - If `N` is divisible by `i` (`N % i == 0`), return `0` because `N` is not a prime number.

3. **Return Prime Status**:
   - If no factors are found in the loop, return `1` indicating `N` is a prime number.
   
The `main` function demonstrates the usage of the `isPrime` function with an example input and prints whether the number is prime or not.
*/
