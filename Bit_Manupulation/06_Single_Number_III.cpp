// Single Number III

// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
// Find the two elements that appear only once. You can return the answer in any order.

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.

#include <bits/stdc++.h>
using namespace std;

void twoNonRepeatingElements(int arr[], int n) {
    long xorVal = 0;
    // XOR all elements to get xorVal which is the XOR of the two non-repeating elements
    for (int i = 0; i < n; i++)
        xorVal ^= arr[i];

    // Get the rightmost set bit in xorVal
    int rightMostSetBit = xorVal & (-xorVal);
    int b1 = 0, b2 = 0;

    // Divide elements into two groups based on the rightmost set bit
    for (int i = 0; i < n; i++) {
        if ((arr[i] & rightMostSetBit) == 0)
            b1 ^= arr[i];  // XOR elements in the first group
        else
            b2 ^= arr[i];  // XOR elements in the second group
    }

    // Output the two non-repeating elements in ascending order
    if (b1 < b2)
        cout << b1 << " " << b2;
    else
        cout << b2 << " " << b1;
}

int main() {
    // Example input
    int arr[] = {2, 4, 7, 9, 2, 4, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find and print the two non-repeating elements
    cout << "The two non-repeating elements are: ";
    twoNonRepeatingElements(arr, n);

    return 0;
}

/*
Explanation of the twoNonRepeatingElements function:
1. Initialize `xorVal` to 0 and XOR all elements in the array to get the combined XOR of the two non-repeating elements.
2. Calculate `rightMostSetBit` as the rightmost set bit in `xorVal` using `xorVal & (-xorVal)`.
3. Initialize `b1` and `b2` to 0 to hold the two non-repeating elements.
4. Iterate over the array again and divide elements into two groups based on whether they have the `rightMostSetBit` set or not.
   - XOR elements in the first group to get one of the non-repeating elements in `b1`.
   - XOR elements in the second group to get the other non-repeating element in `b2`.
5. Output the two non-repeating elements in ascending order.

The `main` function demonstrates the usage of the `twoNonRepeatingElements` function with an example input and prints the result.
*/
