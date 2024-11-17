// Maximum sum of non-adjacent elements

// Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

// Input:
// N = 6
// Arr[] = {5, 5, 10, 100, 10, 5}
// Output: 110
// Explanation: If you take indices 0, 3
// and 5, then Arr[0]+Arr[3]+Arr[5] =
// 5+100+5 = 110.


#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of non-adjacent elements in the array
int findMaxSum(int *arr, int n) {
    // Base cases
    if(n == 0) return 0; // If there are no elements, the maximum sum is 0
    if(n == 1) return arr[0]; // If there is only one element, the maximum sum is the element itself

    // Initialize variables to store the maximum sum up to the previous two elements
    int twoStepBack = 0, oneStepBack = arr[0];

    // Loop through the array starting from the second element
    for(int idx = 1; idx < n; idx++) {
        // Calculate the sum if the current element is included
        int pickedCurrentElement = arr[idx] + twoStepBack;
        // Calculate the sum if the current element is not included
        int notPickedCurrentElement = oneStepBack;

        // The current maximum sum is the maximum of the above two sums
        int currentMaxValue = max(pickedCurrentElement, notPickedCurrentElement);

        // Update the variables for the next iteration
        twoStepBack = oneStepBack;
        oneStepBack = currentMaxValue;
    }

    // The maximum sum of non-adjacent elements is stored in oneStepBack
    return oneStepBack;
}

int main() {
    int arr[] = {3, 2, 7, 10}; // Predefined array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Call the function and print the result
    int result = findMaxSum(arr, n);
    cout << "Maximum sum of non-adjacent elements: " << result << endl;

    return 0;
}
