//  Smallest divisor

// Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. 
// Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, 
// the sum of the division's result is less than or equal to the given threshold value.

// Input Format:
//  N = 5, arr[] = {1,2,3,4,5}, limit = 8
// Result:
//  3
// Explanation:
//  We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
// The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. 
// Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.




#include <iostream>
#include <vector>
#include <algorithm> // Required for max_element

using namespace std;

// Function to check if it's possible to divide the array elements into subarrays such that the sum of each subarray is less than or equal to the limit
bool isSol(vector<int>& arr, int limit, int num) {
    int sum = 0;
    // Iterate through each element in the array
    for(auto i : arr) {
        if(i % num == 0)
            sum += i / num;
        else
            sum += (i / num) + 1;
    }
    // If the total sum of subarrays is less than or equal to the limit, return true
    if(sum <= limit)
        return true;
    return false;
}

// Function to find the smallest divisor such that the sum of each subarray is less than or equal to the limit
int smallestDivisor(vector<int>& arr, int limit) {
    // Find the maximum element in the array
    int max_ele = *max_element(arr.begin(), arr.end());
    int left = 1, right = max_ele, mid;
    int ans = max_ele; // Initialize the answer as the maximum element

    // Binary search to find the smallest divisor
    while(left <= right) {
        mid = left + (right - left) / 2;

        if(isSol(arr, limit, mid)) { // If it's possible to divide the array elements into subarrays such that the sum of each subarray is less than or equal to the limit
            ans = mid; // Update the answer
            right = mid - 1; // Move to the left half
        }
        else {
            left = mid + 1; // Move to the right half
        }
    }

    return ans; // Return the smallest divisor
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 3, 4, 5}; // Array of elements
    int limit = 5; // Limit for the sum of each subarray

    int result = smallestDivisor(arr, limit);
    cout << "Smallest divisor such that the sum of each subarray is less than or equal to " << limit << ": " << result << endl;

    return 0;
}
