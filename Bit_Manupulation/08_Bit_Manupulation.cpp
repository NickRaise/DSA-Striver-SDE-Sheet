#include <iostream>
#include <vector>
using namespace std;

vector<int> bitManipulation(int num, int i) {
    // Retrieve the i-th bit
    int ithBit = (num >> (i - 1)) & 1;

    // Set the i-th bit
    num = num | (1 << (i - 1));
    int setIthBit = num;

    // Clear the i-th bit
    num = setIthBit;
    int clearIthBit = num & ~(1 << (i - 1));

    // Return the results as a vector
    return {ithBit, setIthBit, clearIthBit};
}

int main() {
    // Example input
    int num = 10;
    int i = 2;

    // Get the results
    vector<int> results = bitManipulation(num, i);

    // Print the results to the console
    cout << "The " << i << "-th bit of " << num << " is: " << results[0] << endl;
    cout << "The number after setting the " << i << "-th bit is: " << results[1] << endl;
    cout << "The number after clearing the " << i << "-th bit is: " << results[2] << endl;

    return 0;
}

/*
Explanation of the bitManipulation function:
1. **Retrieve the i-th bit**:
   - Shift the number `num` right by `(i - 1)` positions.
   - Use the bitwise AND operator `&` with `1` to isolate the i-th bit.
   - Store the result in `ithBit`.

2. **Set the i-th bit**:
   - Use the bitwise OR operator `|` to set the i-th bit.
   - The expression `(1 << (i - 1))` creates a mask with only the i-th bit set.
   - Update `num` with the result and store it in `setIthBit`.

3. **Clear the i-th bit**:
   - Use the bitwise AND operator `&` with the negation of the mask `~(1 << (i - 1))` to clear the i-th bit.
   - Store the result in `clearIthBit`.

4. **Return**: Return the results as a vector containing `ithBit`, `setIthBit`, and `clearIthBit`.

The `main` function demonstrates the usage of the `bitManipulation` function with an example input and prints the results.
*/
