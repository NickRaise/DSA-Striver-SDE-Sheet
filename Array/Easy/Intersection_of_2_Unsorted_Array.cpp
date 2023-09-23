// Problem: Intersection of 2 Unsorted Array

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;
    vector<int> ans;
    sort(nums1.begin(), nums1.end()); // Sort the first vector
    sort(nums2.begin(), nums2.end()); // Sort the second vector
    int last = -1; // To keep track of the last added element

    while (i < n && j < m) {
        if (nums1[i] == nums2[j] && last != nums1[i]) {
            ans.push_back(nums1[i]); // If there's a common element not equal to the last one, add it to ans
            last = nums1[i]; // Update last with the added element
            i++; // Move to the next element in nums1
            j++; // Move to the next element in nums2
        } else if (nums1[i] < nums2[j]) {
            i++; // If the current element in nums1 is smaller, move to the next element in nums1
        } else {
            j++; // If the current element in nums2 is smaller, move to the next element in nums2
        }
    }

    return ans; // Return the vector containing the intersection elements
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    vector<int> result = intersection(nums1, nums2);
    
    cout << "Intersection of the two vectors: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
