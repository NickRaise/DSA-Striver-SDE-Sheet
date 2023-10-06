// Leaders in an Array
// Problem Statement: Given an array, print all the elements which are leaders. 
// A Leader is an element that is greater than all of the elements on its right side in the array.

// Example 1:
// Input:
//  arr = [4, 7, 1, 0]
// Output:
//  7 1 0
// Explanation:
//  Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.


#include <iostream>
#include <vector>
using namespace std;

// Function to find leaders in an array
vector<int> leaders(int a[], int n) {
    vector<int> ans;
    int max = -1;
    
    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // If the current element is greater than the maximum element encountered so far
        if (a[i] > max) {
            ans.push_back(a[i]); // Add it to the list of leaders
            max = a[i]; // Update the maximum element
        }
    }
    
    reverse(ans.begin(), ans.end()); // Reverse the list to get the leaders in the original order
    
    return ans; // Return the list of leaders
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int a[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> result = leaders(a, n);
    
    cout << "Leaders in the array are: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
