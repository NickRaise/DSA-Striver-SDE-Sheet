// Problem: Left Rotate an Array by K Elements

// Sample Input 1:
// 8
// 7 5 2 11 2 43 1 1
// 2

// Sample Output 1:
// 2 11 2 43 1 1 7 5

// Sample Input 2:
// 4
// 5 6 7 8
// 3

// Sample Output 2:
// 8 5 6 7



#include <iostream>
#include <vector>

using namespace std;

// Function to reverse a portion of the array
void reverse(vector<int> &arr, int left, int right) {
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Function to rotate an array to the right by 'k' positions
vector<int> rotateArray(vector<int> arr, int k) {
    int n = arr.size();

    // Ensure 'k' is within the range of the array length
    k = k % n;

    // Reverse the first 'k' elements
    reverse(arr, 0, k - 1);

    // Reverse the remaining 'n-k' elements
    reverse(arr, k, n - 1);

    // Reverse the entire array to get the final result
    reverse(arr, 0, n - 1);

    return arr;
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of positions to rotate to the right: ";
    cin >> k;

    vector<int> rotated = rotateArray(arr, k);

    cout << "Rotated Array: ";
    for (int num : rotated) {
        cout << num << " ";
    }

    return 0;
}
