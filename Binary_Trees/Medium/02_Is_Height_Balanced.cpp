// Is Height Balanced Binary Tree

// An empty tree is a height-balanced tree. A non-empty binary tree is a height-balanced binary tree if
// 1. The left subtree of a binary tree is already the height-balanced tree.
// 2. The right subtree of a binary tree is also the height-balanced tree.
// 3. The difference between heights of left subtree and right subtree must not more than ‘1’.

//          1
//        /   \
//       2     3
//      / \
//     4   -1
//    / \
//   -1  5

// Sample Input:
// 1 2 3 4 -1 -1 -1 -1 5 -1 -1
// Expected Answer:
// false



#include <iostream>
#include <cmath> // for std::abs and std::max

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

// Function to calculate the height of the tree and check if it is balanced
int heightOfTree(TreeNode* root) {
    if (!root) return 0; // Base case: if the node is null, the height is 0

    int leftHeight = heightOfTree(root->left); // Recursively calculate the height of the left subtree
    int rightHeight = heightOfTree(root->right); // Recursively calculate the height of the right subtree

    // If either subtree is not balanced, propagate the -1 upwards
    if (leftHeight == -1 || rightHeight == -1) return -1;
    // If the current node is not balanced, return -1
    if (abs(leftHeight - rightHeight) > 1) return -1;

    // Return the height of the tree rooted at this node
    return 1 + max(leftHeight, rightHeight);
}

// Function to check if a binary tree is balanced
bool isBalanced(TreeNode* root) {
    return heightOfTree(root) != -1; // A tree is balanced if its height is not -1
}

// Function to create a sample tree and call the isBalanced function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    bool balanced = isBalanced(root);
    cout << "Is the binary tree balanced? " << (balanced ? "Yes" : "No") << endl;

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
