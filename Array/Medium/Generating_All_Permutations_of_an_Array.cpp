// Problem Statement: Generating All Permutations of an Array

// You are given an array of distinct integers. 
// Your task is to write a C++ program to generate all possible permutations of this array and display them.

// Example:
// Suppose you are given the following input array:

// Input Array: [1, 2, 3]

// Your program should generate all permutations of this array. A permutation is an arrangement of elements, and for the input array [1, 2, 3], the possible permutations are:

// [1, 2, 3]
// [1, 3, 2]
// [2, 1, 3]
// [2, 3, 1]
// [3, 1, 2]
// [3, 2, 1]


#include <iostream>
#include <vector>

using namespace std;

// Function to generate permutations
void permutation(vector<vector<int>>& ans, vector<int>& nums, vector<int>& ds, int hash[], int n) {
    // If the current permutation is complete, add it to the answer
    if(ds.size() == n) {
        ans.push_back(ds);
        return;
    }

    // Iterate through the elements in the 'nums' array
    for(int i = 0; i < n; i++) {
        // Check if the element has not been used in the current permutation
        if(hash[i] == 0) {
            // Add the element to the current permutation
            ds.push_back(nums[i]);
            // Mark the element as used
            hash[i] = 1; 
            // Recursively generate permutations with the updated state
            permutation(ans, nums, ds, hash, n);
            // Backtrack by removing the last element and marking it as unused
            hash[i] = 0;
            ds.pop_back();
        }
    }
}

// Function to generate all permutations of an input vector
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    int n = nums.size();
    int hash[n]; // An array to keep track of used elements
    for(int i = 0; i < n; i++)
        hash[i] = 0; // Initialize the hash array
    permutation(ans, nums, ds, hash, n); // Generate permutations
    return ans; // Return the list of permutations
}

int main() {
    // Input vector
    vector<int> nums = {1, 2, 3};

    // Generate permutations
    vector<vector<int>> permutations = permute(nums);

    // Display the generated permutations
    for (const vector<int>& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
