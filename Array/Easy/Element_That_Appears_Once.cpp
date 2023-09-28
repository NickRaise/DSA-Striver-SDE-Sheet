// Problem Statement: Given a non-empty array of integers arr, 
// every element appears twice except for one. Find that single one.

// Example 1:
// Input Format: arr[] = {2,2,1}
// Result: 1
// Explanation: In this array, only the element 1 appear once and so it is the answer.


#include <iostream>
#include <vector>

using namespace std;

int getSingleElement(vector<int> &arr) {
    int n = arr.size();
    int result = 0; // Initialize the result variable to 0

    for (int i = 0; i < n; i++) {
        result = result ^ arr[i]; // Use bitwise XOR to find the single non-repeating element
    }

    return result; // Return the single non-repeating element
}

int main() {
    vector<int> arr = {4, 1, 2, 1, 2};
    
    int singleElement = getSingleElement(arr);
    
    cout << "The single non-repeating element is: " << singleElement << endl;

    return 0;
}
