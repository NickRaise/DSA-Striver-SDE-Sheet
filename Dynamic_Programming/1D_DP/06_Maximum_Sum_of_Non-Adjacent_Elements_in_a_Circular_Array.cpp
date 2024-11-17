// Maximum Sum of Non-Adjacent Elements in a Circular Array


// Given an array nums of size N where each element represents the value of an item, 
// find the maximum sum of any subsequence such that no two elements in the subsequence are adjacent, 
// considering that the array is circular (i.e., the first and last elements are also adjacent).



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the maximum amount of money that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Create two temporary vectors to handle the circular nature of the problem
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);    // Exclude the first house
            if (i != n - 1) temp2.push_back(nums[i]); // Exclude the last house
        }

        // Solve the problem for the two linear cases and return the maximum result
        int withoutFirstElement = solutionForLinear(temp2);
        int withoutLastElement = solutionForLinear(temp1);
        return max(withoutFirstElement, withoutLastElement);
    }

private:
    // Helper function to solve the house robber problem for a linear street of houses
    int solutionForLinear(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int oneStepBack = nums[0], twoStepBack = 0;

        // Loop through the houses starting from the second house
        for (int idx = 1; idx < n; idx++) {
            // Calculate the maximum money if the current house is robbed
            int currentPicked = nums[idx] + twoStepBack;
            // Calculate the maximum money if the current house is not robbed
            int currentNotPicked = oneStepBack;

            // The current maximum is the maximum of the two choices
            int current = max(currentPicked, currentNotPicked);

            // Update the variables for the next iteration
            twoStepBack = oneStepBack;
            oneStepBack = current;
        }

        // The result is the maximum money that can be robbed from the linear street of houses
        return oneStepBack;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 2}; // Predefined list of house values
    int result = sol.rob(nums);
    cout << "Maximum amount of money that can be robbed: " << result << endl;

    return 0;
}
