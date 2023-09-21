// Problem: Move Zero's to end

// Sample Input 1:
// 4
// 0 0 0 1 
// Sample Output 1:
// 1 0 0 0 

// Sample Input 2:
// 5
// 4 0 3 2 5 
// Sample Output 2:
// 4 3 2 5 0 

#include <iostream>
#include <vector>
using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
    int left = -1;

    // Find the index of the first zero (if any)
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            left = i;
            break;
        }
    }

    // If there are no zeros, return the original vector
    if (left == -1)
        return a;

    int right = left + 1;

    // Move non-zero elements to the left
    while (right < n) {
        if (a[right] != 0) {
            swap(a[left], a[right]);
            left++;
        }
        right++;
    }

    return a;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> result = moveZeros(n, a);

    cout << "Array after moving zeros to the end: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
