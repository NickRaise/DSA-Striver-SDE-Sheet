// Given a number N, calculate the prime numbers up to N using Sieve of Eratosthenes.  

#include <iostream>
#include <vector>
using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<int> ans; 
    // Create an array to mark prime numbers
    vector<int> arr(n + 1, 1);

    // Start marking non-prime numbers from 2
    for(int i = 2; i * i <= n; i++) {
        // If i is a prime number
        if(arr[i] == 1) {
            // Mark all multiples of i as non-prime
            for(int j = i * i; j <= n; j += i) {
                arr[j] = 0;
            }
        }
    }
    
    // Collect all prime numbers into the result vector
    for(int i = 2; i <= n; i++) {
        if(arr[i] == 1) ans.push_back(i);
    }
    return ans;
}

int main() {
    // Example input
    int n = 30;
    
    // Get all prime numbers up to n
    vector<int> primes = sieveOfEratosthenes(n);
    
    // Print the prime numbers to the console
    cout << "Prime numbers up to " << n << " are: ";
    for(int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Explanation of the sieveOfEratosthenes function:
1. **Initialization**:
   - Create a vector `arr` of size `n + 1` and initialize all elements to 1, assuming all numbers are prime initially.
   
2. **Mark Non-Prime Numbers**:
   - Loop from `2` to `sqrt(n)` (`i * i <= n`):
     - If `i` is a prime number (`arr[i] == 1`):
       - Mark all multiples of `i` starting from `i * i` as non-prime (`arr[j] = 0`).

3. **Collect Prime Numbers**:
   - Loop from `2` to `n` and collect all numbers that are still marked as prime (`arr[i] == 1`) into the result vector `ans`.

4. **Return Result**:
   - Return the vector `ans` containing all prime numbers up to `n`.

The `main` function demonstrates the usage of the `sieveOfEratosthenes` function with an example input and prints the prime numbers up to `n`.
*/
