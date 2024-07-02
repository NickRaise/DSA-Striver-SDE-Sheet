// Preorder Traversal (Iteration method)

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; // Vector to store the preorder traversal result
        if (!root) return ans; // If the root is null, return an empty vector

        stack<TreeNode*> st; // Stack to manage the traversal
        st.push(root); // Start with the root node

        // Loop until all nodes are processed
        while (!st.empty()) {
            TreeNode *node = st.top(); // Get the node at the top of the stack
            st.pop(); // Remove the node from the stack
            ans.push_back(node->val); // Add the node value to the result

            // Push right child first so that left child is processed first
            if (node->right) {
                st.push(node->right); // Push the right child onto the stack
            }
            if (node->left) {
                st.push(node->left); // Push the left child onto the stack
            }
        }

        return ans;
    }
};

// Function to create a sample tree and call the preorder traversal function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    // Print the preorder traversal result
    cout<<"Preorder -> ";
    for (int val : result) {
        cout << val << " ";
    }

    // Clean up dynamically allocated nodes
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
