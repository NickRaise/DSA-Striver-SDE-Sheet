// Last occurrence in a sorted array
// Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. 
// If the target is not found then return -1.

// Example 1:
// Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
// Output: 4
// Explanation: As the target value is 13 , it appears for the first time at index number 2.


#include <iostream>
#include <vector>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = -1, last = -1;
    int left = 0, right = n - 1;
    int mid;

    // Finding the first occurrence of the target element using binary search
    while(left <= right) {
        mid = left + (right - left) / 2;

        if(arr[mid] >= k) {
            right = mid - 1; // Adjusting the right boundary
            if(arr[mid] == k)
                first = mid; // Updating the index of the first occurrence
        }
        else
            left = mid + 1; // Adjusting the left boundary
    }

    left = 0;
    right = n - 1;

    // Finding the last occurrence of the target element using binary search
    while(left <= right) {
        mid = left + (right - left) / 2;

        if(arr[mid] <= k) {
            left = mid + 1; // Adjusting the left boundary
            if(arr[mid] == k)
                last = mid; // Updating the index of the last occurrence
        }
        else
            right = mid - 1; // Adjusting the right boundary
    }

    return {first, last}; // Returning the pair of first and last occurrences
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 2, 4, 4, 4, 5, 6, 6};
    int target = 4;
    int size = arr.size();

    pair<int, int> result = firstAndLastPosition(arr, size, target);

    cout << "First occurrence: " << result.first << ", Last occurrence: " << result.second << endl;

    return 0;
}
