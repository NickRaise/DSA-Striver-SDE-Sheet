// Two Sum : Check if a pair with given sum exists in Array
// Problem Statement: Given an array of integers arr[] and an integer target.

// Example 1:
// Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
// Result: YES (for 1st variant)
//        [1, 3] (for 2nd variant)
// Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string read(int n, vector<int> book, int target) {
    sort(book.begin(), book.end()); // Sort the book vector in ascending order.
    int left = 0; // Initialize a pointer to the leftmost book.
    int right = n - 1; // Initialize a pointer to the rightmost book.

    while (left < right) {
        int sum = book[left] + book[right]; // Calculate the sum of the book at left and right pointers.

        if (sum == target) {
            return "YES"; // If the sum matches the target, return "YES".
        } else if (sum < target) {
            left++; // If the sum is less than the target, move the left pointer to the right.
        } else {
            right--; // If the sum is greater than the target, move the right pointer to the left.
        }
    }

    return "NO"; // If no pair of books with the given target sum is found, return "NO".
}

int main() {
    int n; // Number of books
    cout << "Enter the number of books: ";
    cin >> n;

    vector<int> books(n); // Create a vector to store book heights.
    cout << "Enter the heights of the books: ";
    for (int i = 0; i < n; i++) {
        cin >> books[i]; // Input the heights of the books.
    }

    int target; // Target sum
    cout << "Enter the target sum: ";
    cin >> target;

    string result = read(n, books, target); // Call the read function to check if a pair of books has the target sum.

    cout << "Result: " << result << endl; // Print the result ("YES" or "NO").

    return 0;
}
