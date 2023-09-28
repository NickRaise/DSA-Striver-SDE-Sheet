// Problem: Missing Number in the array

// Given an array a containing N distinct numbers in the range [0, n],
// return the only number in the range that is missing from the array.

// Sample Input 1 :
// 4 
// 1 2 3
// Sample Output 1:
// 4
// Explanation Of Sample Input 1:
// 4 is the missing value in the range 1 to 4.

#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& a, int N) {
    int ans = 0;

    // XOR all numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        ans = ans ^ i;
        
        // XOR each element in the input vector
        if (i < N) {
            ans = ans ^ a[i - 1];
        }
    }

    return ans; // The result will be the missing number
}

int main() {
    vector<int> input = {1, 2, 4, 5}; // Example input vector with one missing number
    int N = 5; // N represents the range of numbers from 1 to N

    int result = missingNumber(input, N);

    cout << "The missing number is: " << result << endl;

    return 0;
}
