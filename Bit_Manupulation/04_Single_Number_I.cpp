// Single Number

// Given a non-empty array of integers nums, every element appears twice except for one. 
// Find that single one.

// Example 1:
// Input: nums = [2,2,1]
// Output: 1

// Example 2:
// Input: nums = [4,1,2,1,2]
// Output: 4



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the single number in an array where every other number appears twice
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];  // Initialize ans with the first element
        for (int i = 1; i < nums.size(); i++) 
            ans = ans ^ nums[i];  // XOR all elements to find the single number

        return ans;  // Return the single number
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {4, 1, 2, 1, 2};

    // Get the output
    int result = solution.singleNumber(nums);

    // Print the result to the console
    cout << "The single number in the array is: " << result << endl;

    return 0;
}

/*
Explanation of the singleNumber function:
1. Initialize `ans` with the first element of the input vector `nums`.
2. Iterate over the remaining elements of `nums` starting from the second element.
   - For each element, update `ans` by performing XOR with the current element.
   - XORing the same number twice cancels out the number, leaving the single number that appears only once.
3. Return `ans`, which contains the single number.

The `main` function demonstrates the usage of the `singleNumber` function with an example input and prints the result.
*/
