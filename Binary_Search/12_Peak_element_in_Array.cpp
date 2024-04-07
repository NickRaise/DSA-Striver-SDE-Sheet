// Peak element in Array

// Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors.
//  Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. 
//  If there are multiple peak numbers, return the index of any peak number.

// Note: For the first element, the previous element should be considered as negative infinity as well as for the last element,
//  the next element should be considered as negative infinity.

//  Example 1:
// Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
// Result: 7
// Explanation: In this example, there is only 1 peak that is at index 7.

// Example 2:
// Input Format: arr[] = {1,2,1,3,5,6,4}
// Result: 1
// Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. We can consider any of them.






#include <vector>
#include <iostream>

using namespace std;

// Function to find the peak element in an array
int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    
    // If array has only one element, return its index (0)
    if(n == 1) return 0;
    
    // If the first element is greater than the second, it's a peak
    if(arr[0] > arr[1]) return 0;
    
    // If the last element is greater than the second last, it's a peak
    if(arr[n-1] > arr[n-2]) return n-1;

    int left = 1, right = n - 2, mid;

    // Binary search for finding the peak
    while(left <= right) {
        mid = left + (right - left)/2;

        // If the middle element is greater than its neighbors, it's a peak
        if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        // If the element to the left of middle is less than middle, move right
        else if(arr[mid - 1] < arr[mid]) {
            left = mid + 1;
        }
        // Otherwise, move left
        else {
            right = mid - 1;
        }
    }

    // If no peak found, return -1
    return -1; 
}

int main() {
    // Example usage
    vector<int> arr = {1, 3, 20, 4, 1, 0}; // Sample array
    int peakIndex = findPeakElement(arr); // Find peak
    if (peakIndex != -1)
        cout << "Peak element found at index: " << peakIndex << ", value: " << arr[peakIndex] << endl;
    else
        cout << "No peak element found in the array." << endl;
    
    return 0;
}
