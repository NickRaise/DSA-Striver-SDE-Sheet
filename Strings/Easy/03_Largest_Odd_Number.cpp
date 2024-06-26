// Largest Odd Number in String

// Example 1:
// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

// Example 2:
// Input: num = "35427"
// Output: "35"

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to return the largest prefix of the input string that ends with an odd digit
    string maxOdd(string num) {
        int right = num.size() - 1;  // Initialize the index to the last character of the string

        // Traverse the string from the end to the beginning
        while (right >= 0) {
            // Check if the current character is an odd digit
            if ((num[right] - '0') % 2 != 0) {
                // Return the substring from the start to the current position (inclusive)
                return num.substr(0, right + 1);
            }
            right--;  // Move to the previous character
        }

        // If no odd digit is found, return an empty string
        return "";
    }
};

int main() {
    Solution solution;
    
    // Example inputs
    string input1 = "35427";
    string input2 = "123456";
    string input3 = "888888";
    string input4 = "13579";

    // Get the outputs for the example inputs
    string output1 = solution.maxOdd(input1);
    string output2 = solution.maxOdd(input2);
    string output3 = solution.maxOdd(input3);
    string output4 = solution.maxOdd(input4);

    // Print the input and output strings to the console
    cout << "Input: " << input1 << "\nOutput: " << output1 << endl;
    cout << "Input: " << input2 << "\nOutput: " << output2 << endl;
    cout << "Input: " << input3 << "\nOutput: " << output3 << endl;
    cout << "Input: " << input4 << "\nOutput: " << output4 << endl;

    return 0;
}

/*
Explanation of the maxOdd function:
1. Initialize `right` to the last index of the input string `num`.
2. Use a while loop to traverse the string from the end to the beginning.
3. For each character at index `right`, check if it represents an odd digit:
   - Convert the character to an integer by subtracting the ASCII value of '0'.
   - Check if the integer is odd using the modulus operator.
4. If an odd digit is found, return the substring from the beginning of the string to the current position (inclusive).
5. If no odd digit is found after traversing the entire string, return an empty string.
6. The `main` function creates an instance of the `Solution` class, provides example input strings, and prints the outputs.
*/
