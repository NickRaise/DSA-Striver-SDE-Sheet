// Count Reverse Pairs

// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. 
// Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

// Example 1:
// Input: N = 5, array[] = {1,3,2,3,1)
// Output: 2 
// Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.


#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of inversions between skill[l, m] and skill[m+1, r]
int counter(int arr[], int l, int m, int r) {
    int ctn = 0;  // Initialize the inversion count to 0
    int left = l, right = m + 1;

    // Iterate through the two subarrays
    while (left <= m) {
        while (right <= r && arr[left] > (2 * arr[right])) {
            right++;
        }
        // Count the number of inversions
        ctn += right - (m + 1);
        left++;
    }
    return ctn;
}

// Function to merge two subarrays arr[l, m] and arr[m+1, r]
void merge(int arr[], int l, int m, int r) {
    int left = l, right = m + 1;
    vector<int> temp;  // Temporary vector to store merged subarrays

    while (left <= m && right <= r) {
        if (arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from left subarray, if any
    while (left <= m) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right subarray, if any
    while (right <= r) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back to the original array
    for (int i = 0; i < temp.size(); i++) {
        arr[l + i] = temp[i];
    }
}

// Recursive function to perform merge sort and count inversions
int mergeSort(int arr[], int left, int right) {
    int ctn = 0;  // Initialize inversion count to 0

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort and count inversions in the left and right subarrays
        ctn += mergeSort(arr, left, mid);
        ctn += mergeSort(arr, mid + 1, right);

        // Count inversions between the two subarrays and merge them
        ctn += counter(arr, left, mid, right);
        merge(arr, left, mid, right);
    }

    return ctn;
}

// Function to calculate the number of teams with a qualified skill distribution
int team(int arr[], int n) {
    int ctn = 0;  // Initialize inversion count to 0
    ctn = mergeSort(arr, 0, n - 1);  // Call mergeSort to sort and count inversions
    return ctn;
}

int main() {
    int n;
    cout << "Enter the number of players: ";
    cin >> n;

    int arr[n];
    cout << "Enter the skill levels of players:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int totalTeams = team(arr, n);
    cout << "Number of teams with a qualified skill distribution: " << totalTeams << endl;

    return 0;
}
