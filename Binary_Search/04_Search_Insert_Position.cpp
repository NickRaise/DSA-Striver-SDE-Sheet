// Search Insert Position

// Problem Statement: You are given a sorted array arr of distinct values and a target value x. 
// You need to search for the index of the target value in the array.

// If the value is present in the array, then return its index. 
// Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

// Example 1:
// Input Format: arr[] = {1,2,4,7}, x = 6
// Result: 3
// Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.




#include <iostream>
#include <vector>

// Function to search and insert an element in a sorted vector
int searchInsert(std::vector<int>& arr, int m) {
    int idx; // Variable to store the index
    int left = 0; // Left boundary of the search range
    int right = arr.size() - 1; // Right boundary of the search range
    int mid; // Variable to hold the middle index

    // Binary search within the range [left, right]
    while (left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle index

        if (arr[mid] == m)
            return mid; // If the element is found, return its index
        else if (arr[mid] < m) {
            left = mid + 1; // Update the left boundary for the right half of the array
            idx = mid + 1; // Update the potential index (to insert after mid)
        }
        else {
            right = mid - 1; // Update the right boundary for the left half of the array
            idx = mid; // Update the potential index (to insert before mid)
        }
    }

    return idx; // Return the index to insert the element at the appropriate position
}

// Main function to demonstrate the searchInsert function
int main() {
    std::vector<int> sortedArray = {1, 3, 5, 6}; // Example sorted array

    int elementToSearch = 5; // Element to search/insert
    int index = searchInsert(sortedArray, elementToSearch); // Call the searchInsert function

    // Output the result
    std::cout << "Element " << elementToSearch << " should be inserted at index: " << index << std::endl;

    return 0;
}
