#include <iostream>
#include <set>
using namespace std;

void print_divisors(int n) {
    set<int> ans;
    // Loop through numbers from 1 to sqrt(n)
    for(int i = 1; i * i <= n; i++) {
        // If i is a divisor of n
        if(n % i == 0) {
            ans.insert(i); // Insert i into the set
            ans.insert(n / i); // Insert n/i into the set
        }
    }
    
    // Print all unique divisors stored in the set
    for(auto e : ans) {
        cout << e << " ";
    }
    cout << endl; // Add a newline at the end for better output formatting
}

int main() {
    // Example input
    int n = 28;
    
    // Print divisors of n
    cout << "The divisors of " << n << " are: ";
    print_divisors(n);
    
    return 0;
}

/*
Explanation of the print_divisors function:
1. **Set for Unique Divisors**:
   - Use a set `ans` to store the divisors to ensure they are unique.
   
2. **Loop through Possible Divisors**:
   - Loop from 1 to the square root of `n` (`i * i <= n`):
     - If `i` is a divisor of `n` (`n % i == 0`):
       - Insert `i` into the set.
       - Insert the corresponding divisor `n / i` into the set.

3. **Print Divisors**:
   - Iterate over the set `ans` and print each element, which represents a unique divisor of `n`.
   
The `main` function demonstrates the usage of the `print_divisors` function with an example input and prints the divisors.
*/
