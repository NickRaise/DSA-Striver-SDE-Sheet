// Power Set

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to generate all subsets of a given set of numbers
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset_count = 1 << n;  // Total number of subsets is 2^n
        vector<vector<int>> ans;    // Vector to store all subsets

        // Iterate over all possible subsets
        for (int i = 0; i < subset_count; i++) {
            vector<int> set;
            for (int j = 0; j < n; j++) {
                // Check if j-th element is included in the i-th subset
                if (i & (1 << j)) 
                    set.push_back(nums[j]);
            }
            ans.push_back(set);  // Add the current subset to the answer
        }
        return ans;  // Return the vector containing all subsets
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {1, 2, 3};

    // Get the output
    vector<vector<int>> result = solution.subsets(nums);

    // Print the results to the console
    cout << "Subsets of {1, 2, 3} are:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

/*
Explanation of the subsets function:
1. Initialize `n` to the size of the input vector `nums`.
2. Calculate the total number of subsets `subset_count` as `1 << n` (which is 2^n).
3. Initialize an empty vector `ans` to store all subsets.
4. Iterate over all possible subsets using a loop from 0 to `subset_count - 1`.
   - For each subset `i`:
     - Initialize an empty vector `set` to store the current subset.
     - Iterate over each element `j` in `nums`.
       - If the j-th bit of `i` is set (`i & (1 << j)`), include `nums[j]` in the current subset.
     - Add the current subset `set` to `ans`.
5. Return the vector `ans` containing all subsets.

The `main` function demonstrates the usage of the `subsets` function with an example input and prints the results.
*/
