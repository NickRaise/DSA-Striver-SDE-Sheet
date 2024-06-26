// Single Number II

// Given an integer array nums where every element appears three times except for one, which appears exactly once. 
// Find the single element and return it.

// Example 1:
// Input: nums = [2,2,3,2]
// Output: 3

// Example 2:
// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the single number in an array where every other number appears three times
    int singleNumber(vector<int>& nums) {
        int one = 0;  // To hold XOR of all elements appearing once
        int two = 0;  // To hold XOR of all elements appearing twice

        for (auto e : nums) {
            // Update 'one' with elements that appear once or thrice
            one = (one ^ e) & ~two;
            // Update 'two' with elements that appear twice or thrice
            two = (two ^ e) & ~one;
        }

        return one;  // 'one' contains the single number
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {2, 2, 3, 2};

    // Get the output
    int result = solution.singleNumber(nums);

    // Print the result to the console
    cout << "The single number in the array is: " << result << endl;

    return 0;
}

/*
Explanation of the singleNumber function:
1. Initialize two variables `one` and `two` to 0.
   - `one` holds the XOR of all elements that appear once.
   - `two` holds the XOR of all elements that appear twice.
2. Iterate over each element `e` in the input vector `nums`.
   - Update `one` with elements that appear once or thrice, using the expression `(one ^ e) & ~two`.
   - Update `two` with elements that appear twice or thrice, using the expression `(two ^ e) & ~one`.
3. The bitwise operations ensure that elements appearing three times do not affect the final value of `one`.
4. Return `one`, which contains the single number that appears exactly once in the array.

The `main` function demonstrates the usage of the `singleNumber` function with an example input and prints the result.
*/
