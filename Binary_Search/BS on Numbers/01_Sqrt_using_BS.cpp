// Finding Sqrt of a number using Binary Search

// Problem Statement: You are given a positive integer n. Your task is to find and return its square root. 
// If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.


#include <iostream>

using namespace std;

// Function to find the floor square root of a given number
int floorSqrt(int n) {
    // If the number is 0 or 1, return the number itself
    if(n == 0 || n == 1)
        return n;

    int left = 1, right = n;
    long long mid; // Using long long to prevent overflow during calculation
    int ans;

    // Binary search to find the square root
    while(left <= right) {
        mid = left + (right - left) / 2;

        if(mid * mid > n) {
            right = mid - 1; // Move to the left half
        }
        else if(mid * mid <= n) {
            ans = mid; // Store the current value as potential answer
            left = mid + 1; // Move to the right half
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = floorSqrt(n);
    cout << "Floor square root of " << n << " is: " << result << endl;

    return 0;
}
