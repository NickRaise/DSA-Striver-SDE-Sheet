// 3 Sum : Find triplets that add up to a zero

// Problem Statement: Given an array of N integers, 
// your task is to find unique triplets that add up to give a sum of zero. 
// In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, 
// and their sum is equal to zero.


// Example 1: 
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] 
// satisfy the condition of summing up to zero with i!=j!=k


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end()); // Sort the input array in ascending order

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            // Skip duplicate elements to avoid duplicate triplets
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            
            if (sum == 0) {
                // Found a triplet whose sum is zero
                vector<int> temp = {arr[i], arr[left], arr[right]};
                sort(temp.begin(), temp.end()); // Sort the triplet elements

                ans.push_back(temp); // Add the triplet to the result
                left++;
                right--;

                // Skip duplicates in the left and right pointers
                while (left < right && arr[right] == arr[right + 1]) right--;
                while (left < right && arr[left] == arr[left - 1]) left++;
            } else if (sum < 0) {
                left++; // Move the left pointer to increase the sum
            } else {
                right--; // Move the right pointer to decrease the sum
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> result = triplet(n, arr);

    cout << "Triplets with a sum of 0 are: " << endl;
    for (const vector<int> &triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
