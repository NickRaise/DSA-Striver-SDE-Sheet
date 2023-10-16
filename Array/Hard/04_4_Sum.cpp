// 4 Sum | Find Quads that add up to a target value

// Problem Statement: Given an array of N integers, your task is to find unique quads that add up to 
// give a target value. In short, you need to return an array of all the unique quadruplets 
// [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

// Example 1:
// Input Format: arr[] = [1,0,-1,0,-2,2], target = 0
// Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Explanation: We have to find unique quadruplets from the array such that the sum of those elements 
// is equal to the target sum given that is 0. The result obtained is such that the sum of the quadruplets yields 0.



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> st; // Initialize a set to store unique quadruplets.
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Sort the input array in ascending order.

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue; // Skip duplicates to avoid duplicate quadruplets.
        }

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue; // Skip duplicates to avoid duplicate quadruplets.
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                    sort(temp.begin(), temp.end()); // Sort the quadruplet.

                    st.insert(temp); // Add the sorted quadruplet to the set to ensure uniqueness.
                    left++;
                    right--;

                    // Skip duplicates on both sides to avoid duplicate quadruplets.
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                } else if (sum < target) {
                    left++; // Move left pointer to increase the sum.
                } else {
                    right--; // Move right pointer to decrease the sum.
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end()); // Convert set to vector.
    return ans;
}

int main() {
    // Input array and target value.
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // Find and print the unique quadruplets that sum up to the target.
    vector<vector<int>> result = fourSum(nums, target);

    cout << "Unique Quadruplets that sum to " << target << " are:\n";
    for (const vector<int>& quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
