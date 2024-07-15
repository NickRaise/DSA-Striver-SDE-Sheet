// Maximum Width of Binary Tree

// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
// where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.


//       1
//      / \
//     3   2
//    /     \
//   5       9
//  /       /
// 6       7

// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).



#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;               // Value of the node
    TreeNode *left;        // Pointer to the left child
    TreeNode *right;       // Pointer to the right child

    // Default constructor initializing value to 0 and children to nullptr
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor initializing value and setting children to nullptr
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor initializing value and setting children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to calculate the maximum width of a binary tree
    int widthOfBinaryTree(TreeNode* root) {
        // If the tree is empty, the width is 0
        if (!root) return 0;
        
        int ans = 0; // Initialize the answer to 0, this will store the maximum width

        // Use a queue to perform level-order traversal
        // Each element in the queue is a pair consisting of a TreeNode pointer and an unsigned long long representing the index of the node
        queue<pair<TreeNode*, unsigned long long>> q;

        // Push the root node with index 0
        q.push({root, 0});

        // Traverse the tree level by level
        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            int minIndex = q.front().second; // Minimum index at the current level (used for normalization)
            int start, end; // Variables to store the start and end indices at the current level

            // Iterate through all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front().first; // Get the current node
                unsigned long long index = q.front().second - minIndex; // Normalize the index by subtracting the minimum index
                q.pop(); // Remove the node from the queue

                // Record the start and end indices for the current level
                if (i == 0) start = index; // Start index for the first node in the level
                if (i == size - 1) end = index; // End index for the last node in the level

                // Push the left and right children to the queue with their respective indices
                if (node->left)
                    q.push({node->left, 2 * index + 1});
                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }

            // Update the maximum width
            ans = max(ans, end - start + 1);
        }

        return ans; // Return the maximum width found
    }
};

// Function to create a sample tree and call the widthOfBinaryTree function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    int width = sol.widthOfBinaryTree(root); // Calculate the maximum width

    // Print the maximum width
    cout << "Maximum width of the binary tree is: " << width << endl;

    // Clean up dynamically allocated nodes
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
