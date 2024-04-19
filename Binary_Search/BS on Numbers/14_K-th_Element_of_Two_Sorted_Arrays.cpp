// K-th Element of two sorted arrays

// Problem Statement: Given two sorted arrays of size m and n respectively, 
// you are tasked with finding the element that would be at the kth position of the final sorted array.

// Input: m = 5
//        n = 4
//        array1 = [2,3,6,7,9]
//        array2 = [1,4,8,10]
//        k = 5
// Output:
//  6

// Explanation: Merging both arrays and sorted. Final array will be -
//  [1,2,3,4,6,7,8,9,10]
// We can see at k = 5 in the final array has 6. 


#include<bits/stdc++.h>
using namespace std;

// Function to find the kth element in two sorted arrays
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    // Ensure n1 <= n2 to simplify calculations
    if(n1 > n2) return kthElement(b, a, n2, n1, k);

    // Initialize pointers for binary search
    int low = max(0, k - n2);
    int high = min(k, n1);
    int left = k;
    int n = n1 + n2;

    // Perform binary search
    while(low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        // Set boundary values for partitions
        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];

        // Check if partitions are correctly sorted
        if(l1 <= r2 && l2 <= r1) {
            // If partitions are correctly sorted, return maximum of the left partition ends
            return max(l1, l2);
        } else if(l1 > r2) {
            // If elements in a's left partition are too big, move towards left
            high = mid1 - 1;
        } else {
            // If elements in b's left partition are too big, move towards right
            low = mid1 + 1;
        }
    }
    // Return -1 if kth element is not found
    return -1;
}

int main() {
    // Example usage
    vector<int> a = {1, 3, 8, 10, 15};
    vector<int> b = {7, 11, 18, 19, 25};
    int n1 = a.size();
    int n2 = b.size();
    int k = 5;
    cout << "The kth element is: " << kthElement(a, b, n1, n2, k) << endl;
    return 0;
}
