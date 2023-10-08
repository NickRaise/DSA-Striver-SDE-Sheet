// Longest Consecutive Sequence in an Array
// Problem Statement: You are given an array of ‘N’ integers. 
// You need to find the length of the longest sequence which contains the consecutive elements.

// Example 1:
// Input: [100, 200, 1, 3, 2, 4]
// Output: 4

// Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.




#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the length of the longest sequence of successive elements
int longestSuccessiveElements(vector<int>& a) {
    // Create an unordered set to store the unique elements of the array
    unordered_set<int> s;

    // Insert all elements from the array into the set to remove duplicates
    for (int i = 0; i < a.size(); i++) {
        s.insert(a[i]);
    }

    // Initialize variables to keep track of the current count and maximum count
    int count = 1;
    int max_ele = 1;

    // Iterate through the unique elements in the set
    for (auto it : s) {
        // Check if the previous element (it - 1) is not in the set
        if (s.find(it - 1) != s.end())
            continue;

        int ele = it;
        
        // Count the length of the current sequence of successive elements
        while (s.find(ele + 1) != s.end()) {
            count++;
            ele++;
        }

        // Update the maximum count if the current sequence is longer
        max_ele = max(max_ele, count);
        count = 1; // Reset count for the next sequence
    }

    return max_ele;
}

int main() {
    // Input data: an array of integers
    vector<int> arr = {1, 5, 8, 3, 4, 2, 7, 6};

    // Call the function to find the length of the longest successive elements
    int maxLength = longestSuccessiveElements(arr);

    // Output the result
    cout << "Length of the longest sequence of successive elements: " << maxLength << endl;

    return 0;
}
