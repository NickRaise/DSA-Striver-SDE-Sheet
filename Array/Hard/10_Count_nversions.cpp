// Count inversions in an array
// Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

// What is an inversion of an array? 
// Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// Example 1:
// Input Format: N = 5, array[] = {1,2,3,4,5}
// Result: 0
// Explanation: we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. 
// More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.



#include <iostream>
#include <vector>

using namespace std;

// Merge function to merge two subarrays and count inversions
int merge(vector<int>& a, int l, int m, int r) {
    vector<int> temp; // Temporary vector to store merged elements
    int left = l, mid = m, right = m + 1; // Pointers to divide the array
    int cnt = 0; // Count of inversions

    // Merge two sorted subarrays into temp[]
    while (left <= mid && right <= r) {
        if (a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        } else {
            temp.push_back(a[right]);
            // If a[left] > a[right], it means there are inversions
            // Since both left and right subarrays are sorted,
            // all elements from left to mid are greater than a[right]
            cnt += (mid - left + 1);
            right++;
        }
    }

    // Copy remaining elements from left subarray (if any)
    while (left <= mid) {
        temp.push_back(a[left]);
        left++;
    }

    // Copy remaining elements from right subarray (if any)
    while (right <= r) {
        temp.push_back(a[right]);
        right++;
    }

    // Copy merged elements from temp[] back to a[]
    for (int i = 0; i < temp.size(); i++) {
        a[l + i] = temp[i];
    }

    return cnt; // Return the count of inversions
}

// MergeSort function to sort the array and count inversions
int mergeSort(vector<int>& a, int l, int r) {
    int left = l, right = r;
    int cnt = 0; // Count of inversions

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively divide the array into two halves
        cnt += mergeSort(a, left, mid);
        cnt += mergeSort(a, mid + 1, right);

        // Merge the two halves and count inversions
        cnt += merge(a, left, mid, right);
    }

    return cnt; // Return the count of inversions
}

int numberOfInversions(vector<int>& a, int n) {
    int cnt;
    cnt = mergeSort(a, 0, n - 1);
    return cnt; // Return the total count of inversions
}

int main() {
    vector<int> a = {12, 11, 13, 5, 6, 7};
    int n = a.size();

    int inversionCount = numberOfInversions(a, n);

    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "\nNumber of inversions: " << inversionCount << endl;

    return 0;
}
