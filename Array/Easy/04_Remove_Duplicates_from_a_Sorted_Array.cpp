// Problem: Remove Duplicate from a Sorted Array
// return the number of unique elments

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
    int i = 0; // Initialize a pointer at the beginning of the array to keep track of unique elements.
    int j = 1; // Initialize another pointer to traverse the array and find duplicate elements.

    while (j < n) {
        if (arr[i] != arr[j]) {
            // If the elements at i and j are not equal, it means a new unique element is found.
            i++; // Move the unique element pointer i to the next position.
            arr[i] = arr[j]; // Store the unique element at position i.
        }

        j++; // Always move the j pointer to the next element.
    }

    // After traversing the array, i will be pointing to the last unique element.
    // The count of unique elements is (i + 1) because i is 0-based.
    return i + 1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int newSize = removeDuplicates(arr, n);

    cout << "Array with duplicates removed:" << endl;
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "Size of the updated array: " << newSize << endl;

    return 0;
}
