// Binary Tree Level Order Traversal

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val; // The value of the node
    TreeNode *left; // Pointer to the left child
    TreeNode *right; // Pointer to the right child
    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // Constructor with value initialization
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor with value and children initialization
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; // Result vector to store levels of the tree

        if (!root) return ans; // If the root is null, return an empty vector

        queue<TreeNode*> q; // Queue to manage the traversal
        q.push(root); // Start with the root node

        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            vector<int> level; // Vector to store nodes at the current level

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front(); // Get the front node in the queue
                q.pop(); // Remove the node from the queue

                if (node->left) q.push(node->left); // Add left child to the queue if it exists
                if (node->right) q.push(node->right); // Add right child to the queue if it exists

                level.push_back(node->val); // Add the node's value to the current level vector
            }
            ans.push_back(level); // Add the current level vector to the result
        }

        return ans;
    }
};

// Function to create a sample tree and call the level order traversal function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the level order traversal result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
