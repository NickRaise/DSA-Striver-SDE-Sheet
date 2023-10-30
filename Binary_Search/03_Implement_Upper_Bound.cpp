// Implement Upper Bound

// Problem Statement: Given a sorted array of N integers and an integer x, 
// write a program to find the upper bound of x.

// Example 1:
// Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
// Result: 3
// Explanation: Index 3 is the smallest index such that arr[3] > x.



#include <iostream>
#include <vector>

// Function to find the upper bound of a given value x in a sorted array using binary search
int upperBound(std::vector<int> &arr, int x, int n) {
    int left = 0; // Initialize the left pointer to the start of the array
    int right = n - 1; // Initialize the right pointer to the end of the array
    int ans = n; // Initialize ans as the size of the array (default if the value x is greater than the largest element)

    int mid; // Declare a variable to store the mid index during the search

    while (left <= right) { // Perform binary search until the left pointer is less than or equal to the right pointer

        mid = left + (right - left) / 2; // Calculate the middle index to divide the search space

        if (arr[mid] <= x)
            left = mid + 1; // If the middle element is less than or equal to x, move the left pointer to mid + 1 to search in the right half
        else {
            ans = mid; // If the middle element is greater than x, update the answer to the current middle index
            right = mid - 1; // Move the right pointer to mid - 1 to search in the left half for a potentially smaller upper bound
        }
    }

    return ans; // Return the index of the first element that is greater than x or the size of the array if x is greater than all elements
}

int main() {
    // Example usage
    std::vector<int> array = {2, 3, 5, 8, 12, 18, 23}; // Sorted array
    int target = 6; // Value to find the upper bound for

    int size = array.size();
    int upperIndex = upperBound(array, target, size);

    std::cout << "The upper bound of " << target << " in the array is at index: " << upperIndex << std::endl;

    return 0;
}
