// Problenm: Find the smallest and second smallest element in an array

// Given an array of integers, your task is to find the smallest and second smallest element in the array. 
// If smallest and second smallest do not exist, print -1.


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> minAnd2ndMin(int a[], int n) {
    int min = a[0];
    int sec_min = INT_MAX;
    
    // Traverse the array to find the minimum and second minimum elements.
    for(int i = 0; i < n; i++) {
        if (min > a[i]) {
            sec_min = min;
            min = a[i];
        } else if (a[i] > min && a[i] < sec_min) {
            sec_min = a[i];
        }
    }
    
    // If no second minimum is found, return -1.
    if (sec_min == INT_MAX) {
        return {-1};
    }
    
    // Otherwise, return the minimum and second minimum elements in a vector.
    return {min, sec_min};
}

int main() {
    int n;
    
    // Input the number of elements in the array.
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int a[n];
    
    // Input the array elements.
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Call the minAnd2ndMin function to find the minimum and second minimum elements.
    vector<int> result = minAnd2ndMin(a, n);
    
    // Output the result.
    if (result.size() == 1 && result[0] == -1) {
        cout << "No second minimum element found." << endl;
    } else {
        cout << "Minimum: " << result[0] << endl;
        cout << "Second Minimum: " << result[1] << endl;
    }
    
    return 0;
}
