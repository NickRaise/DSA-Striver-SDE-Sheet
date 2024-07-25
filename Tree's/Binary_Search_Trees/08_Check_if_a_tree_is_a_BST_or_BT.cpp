// Check if a tree is a BST or BT


#include <iostream>
#include <climits> // For LONG_MIN and LONG_MAX
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
    // Function to check if the tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // If the tree is empty, it is considered a valid BST
        if (!root) return true;
        // Call the helper function with the initial range set to [LONG_MIN, LONG_MAX]
        return helperFunction(root, LONG_MIN, LONG_MAX);
    }

private:
    // Helper function to validate the BST property in a subtree
    bool helperFunction(TreeNode* root, long start, long end) {
        // If the subtree is empty, it is valid
        if (!root) return true;
        // Check if the current node's value is within the valid range
        if (start < root->val && root->val < end) {
            // Recursively validate the left and right subtrees with updated ranges
            bool checkLeft = helperFunction(root->left, start, root->val);
            bool checkRight = helperFunction(root->right, root->val, end);
            // Return true if both subtrees are valid
            return (checkLeft && checkRight);
        } else {
            // If the current node's value is not within the valid range, return false
            return false;
        }
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

// Helper function to perform inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create the root of the tree
    TreeNode* root = nullptr;

    // Insert values into the BST
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    Solution solution;
    bool isValid = solution.isValidBST(root);
    cout << "The tree is " << (isValid ? "a valid BST." : "not a valid BST.") << endl;

    return 0;
}
