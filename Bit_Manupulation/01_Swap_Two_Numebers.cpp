// Swap two numebers

#include <iostream>
using namespace std;

class Solution {
public:
    // Function to swap two integers using XOR bitwise operation
    void swapNumber(int &a, int &b) {
        a = a ^ b;  // Step 1: a becomes (a XOR b)
        b = b ^ a;  // Step 2: b becomes (b XOR (a XOR b)) which simplifies to a
        a = a ^ b;  // Step 3: a becomes ((a XOR b) XOR a) which simplifies to b
    }
};

int main() {
    Solution solution;
    
    // Example input
    int num1 = 5;
    int num2 = 10;

    // Print the numbers before swapping
    cout << "Before swapping:\n";
    cout << "num1: " << num1 << "\nnum2: " << num2 << endl;

    // Call the swapNumber function
    solution.swapNumber(num1, num2);

    // Print the numbers after swapping
    cout << "After swapping:\n";
    cout << "num1: " << num1 << "\nnum2: " << num2 << endl;

    return 0;
}

/*
Explanation of the swapNumber function:
1. The function takes two integer references, `a` and `b`, and swaps their values using XOR bitwise operation.
2. XOR operation properties:
   - x ^ x = 0
   - x ^ 0 = x
   - x ^ y ^ x = y (commutative and associative properties)
3. Steps to swap:
   - Step 1: `a` is updated to `a ^ b`.
   - Step 2: `b` is updated to `b ^ a`, which is equivalent to `b ^ (a ^ b)`, simplifying to `a`.
   - Step 3: `a` is updated to `a ^ b`, which is equivalent to `(a ^ b) ^ a`, simplifying to `b`.
4. The `main` function creates an instance of the `Solution` class, provides example input integers, and prints the values before and after swapping.
*/
