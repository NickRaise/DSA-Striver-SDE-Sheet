// Implement Lower Bound

// Problem Statement: Given a sorted array of N integers and an integer x, 
// write a program to find the lower bound of x.

// Example 1:
// Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
// Result: 1
// Explanation: Index 1 is the smallest index such that arr[1] >= x.



#include <iostream>
#include <vector>
using namespace std;

// Function to find the lower bound of an element in a sorted vector
int lowerBound(vector<int> arr, int n, int x) {
    int left = 0; // Initialize the left pointer to the start of the array
    int right = n - 1; // Initialize the right pointer to the end of the array
    int ans = n; // Initialize ans as the size of the array

    int mid;

    // Binary search to find the lower bound
    while (left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle index

        if (arr[mid] < x) {
            left = mid + 1; // If the middle element is less than x, move the left pointer to mid + 1
        } else {
            ans = mid; // Update the answer to the current middle index
            right = mid - 1; // Move the right pointer to mid - 1 to search left side
        }
    }

    return ans; // Return the lower bound index
}

int main() {
    vector<int> arr = {2, 3, 5, 7, 9, 11, 13};
    int n = arr.size(); // Size of the array
    int x = 6; // Element to find its lower bound

    // Find the lower bound of x in the array
    int lb = lowerBound(arr, n, x);

    if (lb < n) {
        cout << "Lower bound of " << x << " is at index: " << lb << endl;
        cout << "The element just greater than or equal to " << x << " is: " << arr[lb] << endl;
    } else {
        cout << "No element found greater than or equal to " << x << " in the array." << endl;
    }

    return 0;
}
