//  Remove Outermost Parentheses
//  The goal is to remove the outermost parentheses from every primitive pair of parentheses in the string and return the modified string.

// Example 1:
// Input: s = "(()())(())"
// Output: "()()()"
// Explanation: 
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

// Example 2:
// Input: s = "(()())(())(()(()))"
// Output: "()()()()(())"
// Explanation: 
// The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
// After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') {
                // Only add the '(' to the answer if it's not an outer parenthesis
                if (cnt >= 1)
                    ans += '(';
                cnt++;  // Increase the count of '('
            } else {
                // Only add the ')' to the answer if it's not an outer parenthesis
                if (cnt >= 2)
                    ans += ')';
                cnt--;  // Decrease the count of '(' as we've encountered a ')'
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string input = "(()())(())"; // Example input
    string output = solution.removeOuterParentheses(input);
    
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;

    return 0;
}

/*
Explanation:
1. The function removeOuterParentheses takes a string s consisting of parentheses and removes the outermost parentheses of every primitive valid parentheses string.
2. We initialize an empty string ans to store the result and an integer cnt to keep track of the balance of parentheses.
3. We iterate over each character in the input string s.
4. When we encounter '(': 
    - If cnt is at least 1, it means this '(' is not an outer parenthesis, so we add it to ans.
    - We then increment cnt.
5. When we encounter ')':
    - If cnt is at least 2, it means this ')' is not an outer parenthesis, so we add it to ans.
    - We then decrement cnt.
6. By the end of the loop, ans contains the input string s with all outer parentheses removed.
7. In the main function, we create an instance of the Solution class, provide an example input string, and print the output of the removeOuterParentheses function.
*/
