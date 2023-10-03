// Sort an array of 0s, 1s and 2s
// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. 
// Write a program to in-place sort the array without using inbuilt sort functions. 
// ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Input: nums = [2,0,1]
// Output: [0,1,2]


#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int>& arr, int n) {
    int left = 0;
    int right = n - 1;
    int curr = 0;

    while (curr <= right) {
        if (arr[curr] == 0) {
            swap(arr[curr], arr[left]); // Swap the current element with the leftmost (0) element
            left++; // Move the left pointer to the right
            curr++; // Move the current pointer to the right
        } else if (arr[curr] == 2) {
            swap(arr[curr], arr[right]); // Swap the current element with the rightmost (2) element
            right--; // Move the right pointer to the left
        } else {
            curr++; // If the current element is 1, move the current pointer to the right
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 1, 0, 2};
    int n = arr.size();

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortArray(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
