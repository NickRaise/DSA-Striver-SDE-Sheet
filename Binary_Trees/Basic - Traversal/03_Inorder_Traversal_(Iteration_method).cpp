// Inorder Traversal (Iteration method)

#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; // Vector to store the inorder traversal
        if (!root) return ans; // If the root is null, return an empty vector

        stack<TreeNode*> st; // Stack to manage the traversal
        TreeNode* current = root; // Start with the root node

        // Loop until all nodes are processed
        while (current || !st.empty()) {
            // Reach the left most Node of the current Node
            while (current) {
                st.push(current); // Place pointer to a tree node on the stack before traversing the node's left subtree
                current = current->left;
            }

            // Current must be NULL at this point
            current = st.top();
            st.pop(); // Node must be popped from stack and value added to result

            ans.push_back(current->val); // Add the node value to the result

            // We have visited the node and its left subtree. Now, it's right subtree's turn
            current = current->right;
        }

        return ans;
    }
};

// Function to create a sample tree and call the inorder traversal function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // Print the inorder traversal result
    cout<<"Inorder -> ";
    for (int val : result) {
        cout << val << " ";
    }

    // Clean up dynamically allocated nodes
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
