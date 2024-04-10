// Capacity to Ship Packages within D Days

// Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another.
//  The packages must be shipped within 'd' days.The weights of the packages are given in an array 'of weights'. 
// The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.

// Example 1:
// Input Format:
//  N = 5, weights[] = {5,4,5,2,3,4,5,6}, d = 5
// Result:
//  9
// Explanation:
//  If the ship capacity is 9, the shipment will be done in the following manner:
// Day         Weights            Total
// 1        -       5, 4          -        9
// 2        -       5, 2          -        7
// 3        -       3, 4          -        7
// 4        -       5              -        5
// 5        -       6              -        6
// So, the least capacity should be 9.




#include <bits/stdc++.h>
using namespace std;

// Function to check if the given weight can be distributed among 'days' days
bool isSol(vector<int> &weights, int days, int num) {
    int days_need = 1; // Initialize days needed to 1
    int w_cnt = 0; // Initialize the count of weight for a day to 0

    // Loop through the weights
    for(auto i : weights) {
        // If adding the current weight exceeds the limit 'num'
        if(w_cnt + i > num) {
            days_need++; // Increase the number of days needed
            w_cnt = i; // Reset the weight count for the new day
        }
        else
            w_cnt += i; // Otherwise, add the weight to the current day
    } 

    // If the days needed are less than or equal to the given 'days', return true
    if(days_need <= days) 
        return true;
    return false; // Otherwise, return false
}

// Function to find the least weight capacity such that all weights can be distributed within 'd' days
int leastWeightCapacity(vector<int> &weights, int d) {
    int max_ele = *max_element(weights.begin(), weights.end()); // Find the maximum element in the weights
    int sum_arr = accumulate(weights.begin(), weights.end(), 0); // Calculate the sum of all elements in weights
    int ans = sum_arr; // Initialize the answer to the sum of all weights
    int left = max_ele, right = sum_arr, mid; // Initialize binary search boundaries

    // Perform binary search
    while(left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle value

        // If the current mid value satisfies the condition
        if(isSol(weights, d, mid)) {
            ans = mid; // Update the answer
            right = mid - 1; // Move towards left for possible smaller value
        }
        else {
            left = mid + 1; // Otherwise, move towards right
        }
    }

    return ans; // Return the least weight capacity
}

// Main function
int main() {
    // Example usage
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sample weights
    int d = 5; // Number of days
    cout << "Least weight capacity: " << leastWeightCapacity(weights, d) << endl; // Output the least weight capacity
    return 0;
}
