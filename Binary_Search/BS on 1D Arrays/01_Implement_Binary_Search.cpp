//Implement binary Search (Recursive Approach)


#include <iostream>
using namespace std;

// Recursive function to perform binary search
int BS(int arr[], int left, int right, int k) {
    if (left > right)
        return -1; // If the element is not found, return -1

    int mid = left + (right - left) / 2; // Calculate the middle index

    if (arr[mid] == k)
        return mid; // If the element is found at the middle index, return the index
    else if (arr[mid] > k)
        return BS(arr, left, mid - 1, k); // If the middle element is greater than k, search the left subarray
    else
        return BS(arr, mid + 1, right, k); // If the middle element is less than k, search the right subarray
}

// Function to initiate binary search
int binarysearch(int arr[], int n, int k) {
    return BS(arr, 0, n - 1, k); // Call the binary search function with initial left and right indices
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int key = 14; // Element to search in the array

    // Find the element using binary search
    int result = binarysearch(arr, n, key);

    if (result != -1) {
        cout << "Element " << key << " found at index: " << result << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
