// Reverse Words in a String

// Problem Statement: Given a string s, reverse the words of the string.

// Example 1:
// Input: s=”this is an amazing program”
// Output: “program amazing an is this”

// Example 2:
// Input: s=”This is decent”
// Output: “decent is This”

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to reverse the words in a given string
    string reverseWords(string str) {
        int n = str.size();  // Get the length of the input string
        string ans = "";     // Initialize the result string
        int i = 0;           // Initialize the index to iterate through the string

        while (i < n) {
            string word = "";  // Initialize a temporary string to store the current word

            // Skip any leading spaces
            while (i < n && str[i] == ' ')
                i++;

            // Capture the word by concatenating characters until a space or end of string is encountered
            while (i < n && str[i] != ' ') {
                word += str[i];
                i++;
            }

            // If a word was captured, add it to the result string in reverse order
            if (!word.empty()) {
                if (ans.empty())  // If it's the first word, initialize the result with it
                    ans = word;
                else              // Otherwise, prepend the word followed by a space
                    ans = word + ' ' + ans;
            }
            i++;  // Move to the next character
        }

        return ans;  // Return the final reversed words string
    }
};

int main() {
    Solution solution;
    
    // Example input
    string input1 = "the sky is blue";
    string input2 = "  hello world  ";
    string input3 = "a good   example";

    // Get the outputs for the example inputs
    string output1 = solution.reverseWords(input1);
    string output2 = solution.reverseWords(input2);
    string output3 = solution.reverseWords(input3);

    // Print the input and output strings to the console
    cout << "Input: \"" << input1 << "\"\nOutput: \"" << output1 << "\"" << endl;
    cout << "Input: \"" << input2 << "\"\nOutput: \"" << output2 << "\"" << endl;
    cout << "Input: \"" << input3 << "\"\nOutput: \"" << output3 << "\"" << endl;

    return 0;
}

/*
Explanation of the reverseWords function:
1. Initialize the length of the input string `n` and an empty result string `ans`.
2. Use a variable `i` to iterate through the string.
3. Use a while loop to traverse the string until `i` is less than `n`.
4. Initialize a temporary string `word` to store the current word.
5. Skip any leading spaces by advancing `i` while the character is a space.
6. Capture the word by concatenating characters to `word` until a space or the end of the string is encountered.
7. If a word is captured, prepend it to the result string `ans`:
   - If `ans` is empty, assign `word` to `ans`.
   - Otherwise, prepend the word followed by a space to `ans`.
8. Increment `i` to move to the next character.
9. Return the final result string `ans` after all words are reversed.
10. The `main` function creates an instance of the `Solution` class, provides example input strings, and prints the outputs.
*/
