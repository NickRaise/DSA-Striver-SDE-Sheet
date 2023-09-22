// Problem: Union of 2 Sorted Array


#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b) {
    vector<int> ans;
    int n = a.size(), m = b.size();

    int i = 0, j = 0;

    // Merge the two sorted arrays 'a' and 'b' into 'ans' while eliminating duplicates
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            // Check if 'ans' is empty or if the current element is not the same as the last element in 'ans'
            if (ans.empty() || a[i] != ans.back()) {
                ans.push_back(a[i]);
            }
            i++;
        } else {
            // Check if 'ans' is empty or if the current element is not the same as the last element in 'ans'
            if (ans.empty() || b[j] != ans.back()) {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    // Add remaining elements from 'a' to 'ans'
    while (i < n) {
        // Check if 'ans' is empty or if the current element is not the same as the last element in 'ans'
        if (ans.empty() || a[i] != ans.back()) {
            ans.push_back(a[i]);
        }
        i++;
    }

    // Add remaining elements from 'b' to 'ans'
    while (j < m) {
        // Check if 'ans' is empty or if the current element is not the same as the last element in 'ans'
        if (ans.empty() || b[j] != ans.back()) {
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}

int main() {
    // Input sorted arrays 'a' and 'b'
    vector<int> a = {1, 3, 5, 7, 9};
    vector<int> b = {2, 4, 4, 6, 8};

    // Call the sortedArray function to merge and eliminate duplicates
    vector<int> merged = sortedArray(a, b);

    // Display the merged and sorted result
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
