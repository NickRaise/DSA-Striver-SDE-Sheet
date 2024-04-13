// Painter's Partition Problem

// Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. 
// Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. 
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

// Input Format:
//  N = 4, boards[] = {10, 20, 30, 40}, k = 2
// Result:
//  60
// Explanation:
//  We can divide the first 3 boards for one painter and the last board for the second painter.

#include<bits/stdc++.h>
using namespace std;

// Function to check if it's possible to assign painters such that
// no painter has to paint more than mid units of boards
bool isPossible(vector<int> &arr, int k, int mid) {
    int cntPainters = 0;
    int sum = 0;
    
    // Iterate through the boards
    for(auto i : arr) {
        // If adding the current board exceeds mid, start a new painter
        if(sum + i > mid) {
            cntPainters++;
            sum = i;
        }
        else 
            // Otherwise, add the current board to the current painter
            sum += i;
    }

    // If there's still a remaining painter, count it
    if(sum != 0) cntPainters++;

    // If the count of painters is less than or equal to k, it's possible
    if(cntPainters <= k) return true;
    return false;
}

// Function to find the largest minimum distance among painters
int findLargestMinDistance(vector<int> &boards, int k) {
    // Initialize left as the maximum length of a board
    int left = *max_element(boards.begin(), boards.end()),
    // Initialize right as the sum of lengths of all boards
        right = accumulate(boards.begin(), boards.end(), 0), mid;
    int ans = -1;
    
    // Perform binary search to find the largest minimum distance
    while(left <= right) {
        mid = left +  (right - left) / 2;

        // If it's possible to assign painters with a maximum distance of mid
        if(isPossible(boards, k, mid)) {
            // Update ans and search in the left half
            ans = mid;
            right = mid - 1;
        }
        else
            // Otherwise, search in the right half
            left = mid + 1;
    }

    return ans;
}

int main() {
    // Sample usage of the function
    vector<int> boards = {3, 6, 9, 12};
    int k = 3;
    cout << findLargestMinDistance(boards, k); // Output the result
    return 0;
}
