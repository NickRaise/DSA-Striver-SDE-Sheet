// Merge Overlapping Sub-intervals

// Problem Statement: Given an array of intervals, merge all the overlapping intervals 
// and return an array of non-overlapping intervals.

// Example 1: 
// Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
// intervals.

// Example 2:
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    // Initialize the answer vector to store merged intervals
    vector<vector<int>> ans;

    // Sort the input intervals based on their start times
    sort(arr.begin(), arr.end());

    // Initialize the start and end of the current interval
    int start = arr[0][0];
    int end = arr[0][1];

    // Iterate through the sorted intervals
    for (int i = 1; i < arr.size(); i++) {
        // If the current interval overlaps with the previous one, merge them
        if (end >= arr[i][0]) {
            end = max(end, arr[i][1]);
        } else {
            // If there is no overlap, push the merged interval (start, end) to the answer
            ans.push_back({start, end});
            // Update the start and end for the new interval
            start = arr[i][0];
            end = arr[i][1];
        }
    }

    // Push the last merged interval (or the only interval if there's just one)
    ans.push_back({start, end});

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = mergeOverlappingIntervals(intervals);

    cout << "Merged Intervals: ";
    for (const vector<int> &interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}
