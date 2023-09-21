//Problem: Linear Search

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(int n, int num, vector<int> &arr) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num)
            return i; // Return the index where the element is found
    }
    return -1; // Return -1 if the element is not found in the array
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

    int num;
    cout << "Enter the number to search for: ";
    cin >> num;

    int result = linearSearch(n, num, arr);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
