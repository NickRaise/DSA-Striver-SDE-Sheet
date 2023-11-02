// Search Element in a Rotated Sorted Array

// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. 
// Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

// Example 1:
// Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
// Result: 4
// Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. 
// Thus, we get output as 4, which is the index at which 0 is present in the array.



#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& arr, int n, int k) {
    int left = 0, right = n - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        // If the middle element is the target 'k', return its index
        if (arr[mid] == k)
            return mid;

        // Check if the left half is sorted
        if (arr[left] <= arr[mid]) {
            // If 'k' lies within the range of the left half, adjust 'right' pointer
            if (arr[left] <= k && k < arr[mid])
                right = mid - 1;
            else
                // Otherwise, adjust 'left' pointer
                left = mid + 1;
        }
        // Right half is sorted
        else {
            // If 'k' lies within the range of the right half, adjust 'left' pointer
            if (arr[mid] < k && k <= arr[right])
                left = mid + 1;
            else
                // Otherwise, adjust 'right' pointer
                right = mid - 1;
        }
    }

    // 'k' not found in the array, return -1
    return -1;
}

int main() {
    vector<int> rotatedArray = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6}; // Example rotated array
    int target = 3; // Target value to search

    // Calling the search function to find the index of the target
    int index = search(rotatedArray, rotatedArray.size(), target);

    if (index != -1)
        cout << "Target " << target << " found at index: " << index << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;

    return 0;
}
