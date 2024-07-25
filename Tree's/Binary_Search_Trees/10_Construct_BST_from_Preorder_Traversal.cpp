// Construct Binary Search Tree from Preorder Traversal


#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Default constructor, initializes the node value to 0 and left, right pointers to nullptr.
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // Constructor to initialize node with a specific value, and left, right pointers to nullptr.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor to initialize node with a specific value, and given left, right pointers.
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to construct a BST from its preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0; // Start with the first element of the preorder traversal
        // Call the helper function with the initial upper bound set to INT_MAX
        return builder(preorder, idx, INT_MAX);
    }

private:
    // Helper function to construct the BST
    TreeNode* builder(vector<int>& preorder, int &idx, int upperBound) {
        // If all elements are processed or current element is greater than upper bound, return nullptr
        if (idx == preorder.size() || preorder[idx] > upperBound) return nullptr;

        // Create a new node with the current value
        TreeNode *node = new TreeNode(preorder[idx]);
        idx++; // Move to the next element in the preorder traversal

        // Recursively build the left subtree with the current value as the new upper bound
        node->left = builder(preorder, idx, node->val);
        // Recursively build the right subtree with the initial upper bound
        node->right = builder(preorder, idx, upperBound);

        return node; // Return the constructed node
    }
};

// Helper function to perform inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution solution;
    TreeNode* root = solution.bstFromPreorder(preorder);

    cout << "Inorder Traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
