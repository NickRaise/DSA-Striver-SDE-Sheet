// Rearrange Array Elements by Sign
// Variety-1 (Even elements)

// Problem Statement: There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
// Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Input:
// arr[] = {1,2,-4,-5}, N = 4
// Output:
// 1 -4 2 -5
// Explanation: 
// Positive elements = 1,2
// Negative elements = -4,-5
// To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.

#include <iostream>
#include <vector>

using namespace std;

// Function to return a vector with alternate positive and negative numbers.
vector<int> alternateNumbers(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, 0); // Create a result vector of the same size, initialized with zeros.
    int positive = 0; // Index for placing positive numbers in the result vector.
    int negative = 1; // Index for placing negative numbers in the result vector.

    // Iterate through the input vector 'a'.
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            ans[negative] = a[i]; // Place negative number in the result vector at the 'negative' index.
            negative += 2; // Move 'negative' index two positions forward.
        } else {
            ans[positive] = a[i]; // Place positive number in the result vector at the 'positive' index.
            positive += 2; // Move 'positive' index two positions forward.
        }
    }

    return ans; // Return the resulting vector.
}

int main() {
    // Input vector containing both positive and negative numbers.
    vector<int> input = {1, -2, 3, -4, 5, -6};
    
    // Call the alternateNumbers function to get the result.
    vector<int> result = alternateNumbers(input);
    
    // Print the result.
    cout << "Resulting vector: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
