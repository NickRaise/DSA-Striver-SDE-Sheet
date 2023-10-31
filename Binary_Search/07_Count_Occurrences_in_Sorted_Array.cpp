// Count Occurrences in Sorted Array

// Problem Statement: You are given a sorted array containing N integers and a number X, 
// you have to find the occurrences of X in the given array.

// Example 1:
// Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
// Output: 4
// Explanation: 3 is occurring 4 times in 
// the given array so it is our answer.


#include <iostream>
#include <vector>

using namespace std;

// Function to find the first occurrence of x in a sorted vector
int findFirstOccurrence(vector<int>& arr, int n, int x) {
    int first = -1;  // Initialize the first occurrence index as -1
    int left = 0, right = n - 1; // Set the leftmost and rightmost indices of the vector
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle index

        if (arr[mid] >= x) { // If the middle element is greater or equal to x
            right = mid - 1; // Update the right index to the element left to mid

            if (arr[mid] == x)
                first = mid; // Update the first occurrence index to the current mid
        } else {
            left = mid + 1; // Update the left index to the element right to mid
        }
    }

    return first; // Return the index of the first occurrence of x
}

// Function to find the last occurrence of x in a sorted vector
int findLastOccurrence(vector<int>& arr, int n, int x) {
    int last = -1; // Initialize the last occurrence index as -1
    int left = 0, right = n - 1; // Set the leftmost and rightmost indices of the vector
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle index

        if (arr[mid] <= x) { // If the middle element is less than or equal to x
            left = mid + 1; // Update the left index to the element right to mid

            if (arr[mid] == x)
                last = mid; // Update the last occurrence index to the current mid
        } else {
            right = mid - 1; // Update the right index to the element left to mid
        }
    }

    return last; // Return the index of the last occurrence of x
}

// Function to count occurrences of x in a sorted vector
int count(vector<int>& arr, int n, int x) {
    int first = findFirstOccurrence(arr, n, x); // Find the first occurrence of x
    int last = findLastOccurrence(arr, n, x);   // Find the last occurrence of x

    if (first == -1)
        return 0; // If the first occurrence is not found, return 0

    return last - first + 1; // Return the total count of occurrences of x in the vector
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5};
    int x = 3;
    int n = arr.size();

    int occurrences = count(arr, n, x); // Count occurrences of x in the array

    cout << "The number " << x << " occurs " << occurrences << " times in the array." << endl;

    return 0;
}
