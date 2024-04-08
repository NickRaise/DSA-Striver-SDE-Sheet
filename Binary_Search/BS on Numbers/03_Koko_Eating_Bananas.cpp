// Koko Eating Bananas

// Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. 
// An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. 
// If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

// Example 1:
// Input Format:
//  N = 4, a[] = {7, 15, 6, 3}, h = 8
// Result:
//  5
// Explanation:
//  If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. 
//  So, he will take 8 hours to complete all the piles.  




#include <iostream>
#include <vector>
#include <algorithm> // Required for max_element
#include <cmath>     // Required for ceil

using namespace std;

// Function to check if it's possible to consume all bananas within the given hours using a specific rate
bool isSol(int mid, vector<int> v, int h) {
    int t_used = 0; // Total time used to consume all bananas

    // Iterate through each element in the vector
    for(auto it: v) {
        // Calculate the time required to consume the bananas at the current rate
        t_used += ceil((double)it / (double)mid);

        if(t_used > h) // If the total time exceeds the given hours, break the loop
            break;
    }

    // If total time used is less than or equal to the given hours, return true
    if(t_used <= h)
        return true;
    return false;
}

// Function to find the minimum rate required to consume all bananas within the given hours
int minimumRateToEatBananas(vector<int> v, int h) {
    // Find the maximum element in the vector
    auto max_pt  = max_element(v.begin(), v.end());
    int max_element = *max_pt;

    int left = 1, right = max_element, mid;

    // Binary search to find the minimum rate
    while(left <= right) {
        mid = left + (right - left) / 2;

        if(isSol(mid, v, h)) { // If it's possible to consume all bananas within given hours at the current rate
            right = mid - 1; // Move to the left half
        }
        else {
            left = mid  + 1; // Move to the right half
        }
    }

    return left; // Return the minimum rate
}

int main() {
    // Example usage
    vector<int> bananas = {30, 11, 23, 4, 20}; // Number of bananas for each pile
    int hours = 5; // Given hours

    int min_rate = minimumRateToEatBananas(bananas, hours);
    cout << "Minimum rate to eat all bananas within " << hours << " hours: " << min_rate << endl;

    return 0;
}
