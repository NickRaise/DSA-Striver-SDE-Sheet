// Problem: Left Rotate an Array by K Elements

// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]



#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for reverse
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // To handle cases where k is larger than the array size
    
    reverse(nums.begin(), nums.end()); // Reverse the entire array
    reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
    reverse(nums.begin() + k, nums.end()); // Reverse the remaining n - k elements
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    rotate(nums, k); // Rotate the vector
    
    cout << "Rotated Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    
    return 0;
}
