// Find the repeating and missing numbers

// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. 
// Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and 
// missing numbers A and B where A repeats twice and B is missing.

// Example 1:
// Input Format:  array[] = {3,1,2,5,3}
// Result: {3,4)
// Explanation: A = 3 , B = 4 
// Since 3 is appearing twice and 4 is missing



#include <iostream>
#include <vector>

using namespace std;

// Function to find a missing number and a repeating number in an array
vector<int> findMissingRepeatingNumbers(vector<int> numbers) {
    // Calculate the total number of elements in the array
    long long n = numbers.size();

    // Calculate the expected sum and sum of squares for 1 to n
    long long expectedSum = (n * (n + 1)) / 2;
    long long expectedSumOfSquares = (n * (n + 1) * (2 * n + 1)) / 6;

    // Initialize variables to calculate the actual sum and sum of squares of the elements
    long long actualSum = 0;
    long long actualSumOfSquares = 0;

    // Calculate the actual sum and sum of squares of the elements in the array
    for (int i = 0; i < n; i++) {
        actualSum += numbers[i];
        actualSumOfSquares += static_cast<long long>(numbers[i]) * static_cast<long long>(numbers[i]);
    }

    // Calculate the differences between expected and actual sums and sum of squares
    long long sumDifference = actualSum - expectedSum;
    long long sumOfSquaresDifference = actualSumOfSquares - expectedSumOfSquares;

    // Calculate the repeating and missing numbers
    long long repeatingNumber = (sumDifference + sumOfSquaresDifference / sumDifference) / 2;
    long long missingNumber = repeatingNumber - sumDifference;

    // Convert the results to integers and return them in a vector
    return {static_cast<int>(repeatingNumber), static_cast<int>(missingNumber)};
}

int main() {
    // Example usage of the function
    vector<int> numbers = {4, 3, 2, 7, 8, 2, 1};
    vector<int> result = findMissingRepeatingNumbers(numbers);

    // Display the result
    int repeatingNumber = result[0];
    int missingNumber = result[1];
    cout << "Repeating Number: " << repeatingNumber << endl;
    cout << "Missing Number: " << missingNumber << endl;

    return 0;
}
