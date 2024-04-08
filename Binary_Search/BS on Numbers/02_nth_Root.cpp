// Nth Root of a Number using Binary Search

// Problem Statement: Given two numbers N and M, find the Nth root of M. 
// The nth root of a number M is defined as a number X when raised to the power N equals M. 
// If the 'nth root is not an integer, return -1.

// Example 1:
// Input Format:
//  N = 3, M = 27
// Result:
//  3
// Explanation:
//  The cube root of 27 is equal to 3.





#include <iostream>

using namespace std;

// Function to calculate x raised to the power of n, considering the modulo m
long long fnc(int x, int n, int m) {
    long long temp = 1;
    for(int i = 0; i < n; i++) {
        temp *= x; // Multiply x by itself 'n' times
        if(temp > m) // If the result exceeds the modulo, break the loop
            break;
    }
    return temp;
}

// Function to find the Nth root of a given number
int NthRoot(int n, int m) {
    int left = 1, right = m, mid;

    // Binary search to find the Nth root
    while(left <= right) {
        mid = left + (right - left) / 2; // Calculate the middle value

        long long val = fnc(mid, n, m); // Calculate mid raised to the power of n modulo m

        if(val == m) // If the result is equal to the given number, return mid
            return mid;
        else if(val < m) // If the result is less than the given number, search in the right half
            left = mid + 1;
        else // If the result is greater than the given number, search in the left half
            right = mid - 1;
    }

    return -1; // If the Nth root doesn't exist, return -1
}

int main() {
    int n, m;
    cout << "Enter the exponent (n): ";
    cin >> n;
    cout << "Enter the number (m): ";
    cin >> m;

    int result = NthRoot(n, m);
    if(result == -1)
        cout << "Nth root does not exist." << endl;
    else
        cout << "The Nth root is: " << result << endl;

    return 0;
}
