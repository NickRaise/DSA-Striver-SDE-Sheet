// Floor and Ceil in Sorted Array

// Problem Statement: You’re given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].

// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

// Example 1:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
// Result: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.



#include <iostream>
#include <vector>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int floor = -1, ceil = -1;
    int left = 0, right = n - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        // If the middle element is equal to x, then it is both the floor and the ceiling
        if (a[mid] == x)
            return {a[mid], a[mid]};
        // If the middle element is less than x, update the floor and search in the right half
        else if (a[mid] < x) {
            floor = a[mid];
            left = mid + 1;
        }
        // If the middle element is greater than x, update the ceiling and search in the left half
        else {
            ceil = a[mid];
            right = mid - 1;
        }
    }

    return {floor, ceil};
}

int main() {
    // Example usage
    vector<int> arr = {1, 4, 6, 8, 10, 12, 14};
    int size = arr.size();
    int target = 7;

    pair<int, int> result = getFloorAndCeil(arr, size, target);

    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
    cout << "Target: " << target << "\n";
    cout << "Floor: " << result.first << ", Ceiling: " << result.second << "\n";

    return 0;
}
