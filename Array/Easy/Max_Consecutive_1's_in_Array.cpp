// Problem: Max Consecutive Ones

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. 
// The maximum number of consecutive 1s is 3.

#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_occurance = 0; // To store the maximum consecutive ones encountered
    int count = 0; // To keep track of the current consecutive ones count

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) { // If the current element is 1, increment the count
            count++;
        } else { // If the current element is not 1, update max_occurance and reset count
            max_occurance = max(max_occurance, count);
            count = 0; // Reset count to 0
        }
    }

    max_occurance = max(max_occurance, count); // Handle the case where the sequence ends with consecutive ones

    return max_occurance;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1};

    int maxConsecutiveOnes = findMaxConsecutiveOnes(nums);

    cout << "Maximum Consecutive Ones: " << maxConsecutiveOnes << endl;

    return 0;
}
