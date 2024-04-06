// Search Single Element in a sorted array

// Problem Statement: Given an array of N integers. Every number in the array except one appears twice. 
// Find the single number in the array.

// Example 1:
// Input Format:
//  arr[] = {1,1,2,2,3,3 ,4, 5,5 ,6,6}
//             <-left----->   <-right->
//             (e,o)(e,o)(e,o)   (o,e)(o,e)   ------ this is for index
// Result:
//  4
// Explanation:
//  Only the number 4 appears once in the array.





#include <iostream>
#include <vector>
using namespace std;

// Function to find the single non-duplicate element in a sorted array
int singleNonDuplicate(vector<int>& arr) {
    // If the array has only one element, it's the single non-duplicate
    if(arr.size() == 1) 
        return arr[0];
    
    // Check the first two elements
    if(arr[0] != arr[1]) 
        return arr[0];
    
    int n = arr.size() - 1; // index of last element
    
    // Check the last two elements
    if(arr[n] != arr[n - 1]) 
        return arr[n];

    int left = 1, right = n - 1, mid;

    // Binary search loop
    while(left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle index

        // If the middle element is not equal to its adjacent elements,
        // then it's the single non-duplicate
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        // Check if the number of elements to the left of mid (including mid)
        // is even or odd
        bool even = (mid % 2 == 0);

        // If mid is at even index and its next element is equal to mid,
        // or if mid is at odd index and its previous element is equal to mid,
        //then it means mid is on the right part,
        // then the single non-duplicate element is to the right of mid
        if((even && arr[mid] == arr[mid + 1]) || (!even && arr[mid] == arr[mid - 1])) {
            left = mid + 1; // Update left to search in the right half
        }
        else {
            right = mid - 1; // Update right to search in the left half
        }
    }

    return -1; // If no single non-duplicate element is found
}

// Main function
int main() {
    // Example usage
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8}; // Sorted array with one non-duplicate element
    cout << "Single non-duplicate element: " << singleNonDuplicate(arr) << endl;
    return 0;
}
