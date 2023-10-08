// next_permutation : find next lexicographically greater permutation

// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array 
// into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange to the lowest possible order 
// (i.e., sorted in ascending order).


// Example 1 :
// Input format: Arr[] = {1,3,2}
// Output: Arr[] = {2,1,3}
// Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. 
// So, the next permutation just after {1,3,2} is {2,1,3}.

// Example 2:
// Input format: Arr[] = {3,2,1}
// Output: Arr[] = {1,2,3}
// Explanation: As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. 
// So, we have to return the topmost permutation.


#include <iostream>
#include <vector>

using namespace std;

// Function to reverse a subarray from 'left' to 'right' in vector A
void reverse(vector<int> &A, int left, int right) {
    while (left < right) {
        swap(A[left], A[right]);
        left++;
        right--;
    }
}

// Function to find the next greater permutation of a given vector A
vector<int> nextGreaterPermutation(vector<int> &A) {
    int index = -1; // Initialize the index to -1
    int n = A.size(); // Get the size of the vector A

    // Find the rightmost element A[i] such that A[i] < A[i+1]
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            index = i; // Store the index of A[i]
            break; // Exit the loop since we found a valid index
        }
    }

    // If no such element is found (index remains -1), it means A is the largest permutation
    // So, reverse the entire vector A to make it the smallest permutation
    if (index == -1) {
        reverse(A, 0, n - 1); // Reverse the entire vector
        return A;
    }

    // Find the rightmost element A[j] such that A[j] > A[index]
    for (int i = n - 1; i >= 0; i--) {
        if (A[index] < A[i]) {
            swap(A[index], A[i]); // Swap A[index] and A[j]
            break; // Exit the loop since we found a valid swap
        }
    }

    // Reverse the subarray from index+1 to the end to make it the smallest possible permutation
    reverse(A, index + 1, n - 1);

    return A; // Return the next greater permutation
}

int main() {
    // Input vector A
    vector<int> A = {1, 2, 3};

    // Call the nextGreaterPermutation function to find the next greater permutation
    vector<int> result = nextGreaterPermutation(A);

    // Print the result
    cout << "Next Greater Permutation: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}






