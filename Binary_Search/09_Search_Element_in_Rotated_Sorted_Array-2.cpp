// Search Element in Rotated Sorted Array II

// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. 
// Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 

// Example 1:
// Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
// Result: True
// Explanation: The element 3 is present in the array. So, the answer is True.


#include <iostream>
#include <vector>

using namespace std;

// Function to search for the target value in a rotated sorted array
bool searchInARotatedSortedArrayII(vector<int>& A, int key) {
    int left = 0, right = A.size() - 1;
    int mid;

    while(left <= right) {
        mid = left + (right - left) / 2;

        // If the middle element is the key, return true
        if (A[mid] == key)
            return true;
        // Handling cases where elements at left, mid, and right are the same
        else if (A[left] == A[mid] && A[mid] == A[right]) {
            left++;
            right--;
        }
        // Left half is sorted
        else if (A[left] <= A[mid]) {
            // If the key is within the left sorted half, adjust the search space accordingly
            if (A[left] <= key && key < A[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Right half is sorted
        else {
            // If the key is within the right sorted half, adjust the search space accordingly
            if (A[mid] < key && key <= A[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    // Key not found, return false
    return false;
}

int main() {
    // Example usage of the search function
    vector<int> rotatedArray = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    if (searchInARotatedSortedArrayII(rotatedArray, target)) {
        cout << "Target found in the rotated sorted array." << endl;
    } else {
        cout << "Target not found in the rotated sorted array." << endl;
    }

    return 0;
}
