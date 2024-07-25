// Search in a Binary Search Tree


#include <iostream>
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
    // Function to search a value in the Binary Search Tree (BST)
    TreeNode* searchBST(TreeNode* root, int val) {
        // If the current node is null, the value is not found, return nullptr.
        if (!root) return nullptr;

        // If the current node's value matches the target value, return the current node.
        if (root->val == val) return root;

        // If the target value is less than the current node's value, search in the left subtree.
        if (val < root->val)
            return searchBST(root->left, val);
        else 
            // Otherwise, search in the right subtree.
            return searchBST(root->right, val);
    }
};

// Helper function to insert a new value in the BST
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}

int main() {
    // Create the root of the tree
    TreeNode* root = nullptr;
    // Insert values into the BST
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 3);

    Solution solution;
    // Search for a value in the BST
    TreeNode* result = solution.searchBST(root, 2);

    if (result) {
        cout << "Found node with value: " << result->val << endl;
    } else {
        cout << "Value not found in the BST" << endl;
    }

    return 0;
}
