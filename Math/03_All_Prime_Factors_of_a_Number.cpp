#include <iostream>
#include <vector>
using namespace std;

vector<int> AllPrimeFactors(int n) {
    vector<int> ans;
    // Loop through numbers from 2 to sqrt(n)
    for(int i = 2; i * i <= n; i++) {
        // Check if i is a factor of n
        if(n % i == 0) {
            ans.push_back(i); // Add i to the result vector
            // Divide n by i until it's no longer divisible
            while(n % i == 0)
                n /= i;
        }
    }
    // If n is a prime number greater than 1, add it to the result vector
    // i.e if the provided number was a prime number itself
    // so it never went inside the loop
    if(n != 1) ans.push_back(n);
    return ans;
}

int main() {
    // Example input
    int n = 56;
    
    // Get all prime factors of n
    vector<int> primeFactors = AllPrimeFactors(n);
    
    // Print the prime factors to the console
    cout << "The prime factors of " << n << " are: ";
    for(int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Explanation of the AllPrimeFactors function:
1. **Initialize Result Vector**:
   - Use a vector `ans` to store the prime factors of `n`.

2. **Loop through Possible Factors**:
   - Loop from `2` to `sqrt(n)` (`i * i <= n`):
     - If `i` is a factor of `n` (`n % i == 0`):
       - Add `i` to the result vector `ans`.
       - Divide `n` by `i` repeatedly until `n` is no longer divisible by `i`.

3. **Check for Remaining Prime Factor**:
   - If `n` is still greater than `1` after the loop, add `n` to the result vector because it is a prime factor.

4. **Return Result**:
   - Return the vector `ans` containing all prime factors of `n`.

The `main` function demonstrates the usage of the `AllPrimeFactors` function with an example input and prints the prime factors.
*/
