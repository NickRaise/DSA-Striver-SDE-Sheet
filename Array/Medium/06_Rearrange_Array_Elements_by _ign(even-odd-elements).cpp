// Rearrange Array Elements by Sign

// Variety-2 (Even/Odd elements)

// Problem Statement:There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). 
// Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. 
// The leftover elements should be placed at the very end in the same order as in array A.

// Example 1:
// Input:
// arr[] = {1,2,-4,-5,3,4}, N = 6
// Output:
// 1 -4 2 -5 3 4

// Explanation: 
// Positive elements = 1,2
// Negative elements = -4,-5
// To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.
// Leftover positive elements are 3 and 4 which are then placed at the end of the array.


#include <iostream>
#include <vector>

using namespace std;

// Function to rearrange an array with positive and negative integers
void rearrange(int arr[], int n) {
    // Create vectors to store positive and negative integers separately
    vector<int> pos; // Vector to store positive integers
    vector<int> neg; // Vector to store negative integers

    // Separate positive and negative integers from the input array
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            neg.push_back(arr[i]); // If the element is negative, add it to the 'neg' vector
        else
            pos.push_back(arr[i]); // If the element is positive, add it to the 'pos' vector
    }

    // Check if there are more negative integers than positive integers
    if (pos.size() < neg.size()) {
        // Rearrange the array by alternating positive and negative integers
        for (int i = 0; i < pos.size(); i++) {
            arr[2 * i] = pos[i]; // Place a positive integer at even indices
            arr[2 * i + 1] = neg[i]; // Place a negative integer at odd indices
        }

        // Add the remaining negative integers to the end of the array
        int start = pos.size() * 2; // Start position for adding negative integers
        for (int i = pos.size(); i < neg.size(); i++) {
            arr[start] = neg[i];
            start++;
        }
    } else { // When there are more positive integers or an equal number of both
        // Rearrange the array by alternating positive and negative integers
        for (int i = 0; i < neg.size(); i++) {
            arr[2 * i] = pos[i]; // Place a positive integer at even indices
            arr[2 * i + 1] = neg[i]; // Place a negative integer at odd indices
        }

        // Add the remaining positive integers to the end of the array
        int start = neg.size() * 2; // Start position for adding positive integers
        for (int i = neg.size(); i < pos.size(); i++) {
            arr[start] = pos[i];
            start++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the rearrange function to modify the array
    rearrange(arr, n);

    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
