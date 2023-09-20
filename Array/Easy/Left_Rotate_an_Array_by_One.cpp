// Problem: Left Rotate an Array by One

// Sample Input 1:
// 4
// 5 7 3 2 

// Sample Output 1:
// 7 3 2 5

#include <iostream>
#include <vector>

using namespace std;

// Function to rotate an array to the left by one position
vector<int> rotateArray(vector<int>& arr, int n) {
    int first = arr[0]; // Store the first element of the array

    // Shift all elements to the left by one position
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Place the first element at the end of the array
    arr[n - 1] = first;

    return arr; // Return the rotated array
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Rotate the array to the left by one position
    vector<int> rotated = rotateArray(arr, n);

    cout << "Array after rotating to the left by one position:" << endl;
    for (int i = 0; i < n; i++) {
        cout << rotated[i] << " ";
    }

    return 0;
}
