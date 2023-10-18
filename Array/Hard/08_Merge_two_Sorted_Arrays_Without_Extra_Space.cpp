// Merge two Sorted Arrays Without Extra Space

// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and 
// m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains 
// the first N elements and modify arr2 so that it contains the last M elements.

// Example 1:
// Input: 
// n = 4, arr1[] = [1 4 8 10] 
// m = 5, arr2[] = [2 3 9]
// Output: 
// arr1[] = [1 2 3 4]
// arr2[] = [8 9 10]

// Explanation:
// After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to merge two sorted arrays a and b without using extra space
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b) {
    int n = a.size(); // Size of array a
    int m = b.size(); // Size of array b

    int end = n - 1;  // Pointer to the last element of array a
    int start = 0;    // Pointer to the first element of array b

    while (end >= 0 && start < m) {
        if (a[end] > b[start]) {
            swap(a[end], b[start]); // Swap the elements if a[end] is greater than b[start]
            end--;
            start++;
        } else {
            break; // If a[end] is not greater than b[start, we break out of the loop
        }
    }

    sort(a.begin(), a.end()); // Sort array a to ensure it's in non-decreasing order
    sort(b.begin(), b.end()); // Sort array b to ensure it's in non-decreasing order
}

int main() {
    // Example usage
    vector<long long> a = {1, 3, 5, 7};
    vector<long long> b = {2, 4, 6, 8};

    cout << "Array a before merging: ";
    for (long long num : a) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Array b before merging: ";
    for (long long num : b) {
        cout << num << " ";
    }
    cout << endl;

    mergeTwoSortedArraysWithoutExtraSpace(a, b);

    cout << "Merged array a: ";
    for (long long num : a) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Merged array b: ";
    for (long long num : b) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
