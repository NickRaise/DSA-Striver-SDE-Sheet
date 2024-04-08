// Minimum in Rotated Sorted Array

// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). 
// Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array.

// Example 1:
// Input Format: arr = [4,5,6,7,0,1,2,3]
// Result: 0
// Explanation: Here, the element 0 is the minimum element in the array.


#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

// Function to find the minimum element in a rotated sorted vector
int findMin(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    int mid;
    int ans = INT_MAX; // Initializing ans to maximum integer value

    while (left <= right) {
        mid = left + (right - left) / 2; // Finding the middle element

        // If the array is already sorted, return the first element
        if (arr[left] <= arr[right]) {
            ans = min(ans, arr[left]);
            break;
        }
        
        if (arr[left] <= arr[mid]) { // Left half is sorted
            ans = min(ans, arr[left]); // Update ans with the minimum value
            left = mid + 1; // Update the left pointer to search the right half
        } else { // Right half is sorted or contains the minimum
            ans = min(arr[mid], ans); // Update ans with the minimum value
            right = mid - 1; // Update the right pointer to search the left half
        }
    }

    return ans; // Return the minimum element found
}

int main() {
    vector<int> rotatedArray = {7, 8, 9, 1, 2, 3, 4, 5, 6}; // Example of a rotated and sorted array

    // Finding the minimum element in the rotated array
    int minimum = findMin(rotatedArray);

    // Output the minimum element
    cout << "The minimum element in the rotated sorted array is: " << minimum << endl;

    return 0;
}
