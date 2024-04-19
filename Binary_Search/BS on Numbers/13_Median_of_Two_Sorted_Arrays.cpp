// Median of Two Sorted Arrays of different sizes

// Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. 
// The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

// Input Format:
//  n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
// Result:
//  3.5
// Explanation:
//  The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the median is the average of the two middle elements. 
//  Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.





#include <bits/stdc++.h>
using namespace std;

// Function to find the median of two sorted arrays
double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();

    // Ensure n1 is smaller or equal to n2
    if(n1 > n2) return median(b, a);

    // Total number of elements in the combined array
    int n = n1 + n2;

    // Binary search on the smaller array a
    int low = 0, high = n1, mid1, mid2;
    int leftHalf = (n1 + n2 + 1) / 2;

    while(low <= high) {
        mid1 = (low + high) >> 1;
        mid2 = leftHalf - mid1;

        // Initialize the boundary elements of the left and right partitions for both arrays
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];

        // Check if the partitions are valid
        if(l1 <= r2 && l2 <= r1) {
            // If total number of elements is odd, return the maximum of the left partition
            if(n % 2 == 1) return max(l1, l2);
            // If total number of elements is even, return the average of the maximum element of the left partition and the minimum element of the right partition
            else return (double)(max(l1, l2) + min(r1, r2)) / 2;
        }
        else if(l1 > r2) high = mid1 - 1; // Move towards left in array a
        else low = mid1 + 1; // Move towards right in array a
    }

    return -1; // If arrays are not sorted, return -1
}

// Main function
int main() {
    // Example usage
    vector<int> a = {1, 3, 8, 9, 15};
    vector<int> b = {7, 11, 18, 19, 21, 25};
    cout << "Median: " << median(a, b) << endl;
    return 0;
}
