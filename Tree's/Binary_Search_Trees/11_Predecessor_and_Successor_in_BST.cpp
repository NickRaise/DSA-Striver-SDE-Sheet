// Predecessor And Successor In BST

// Input:
//       8
//     /   \
//    1     9
//     \     \
//      4    10
//     /
//    3
// key = 8 
// Output: 4 9
// Explanation: 
// In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.


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
    // Function to find the predecessor and successor of a given key in the BST
    pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
        int pre = -1, suc = -1; // Initialize predecessor and successor to -1

        // Find predecessor
        TreeNode *node = root;
        while (node) {
            if (node->val < key) {  // If current node's value is less than the key
                pre = node->val;    // Update predecessor
                node = node->right; // Move to the right child
            } else {
                node = node->left;  // Move to the left child
            }
        }

        // Find successor
        node = root;
        while (node) {
            if (node->val > key) {  // If current node's value is greater than the key
                suc = node->val;    // Update successor
                node = node->left;  // Move to the left child
            } else {
                node = node->right; // Move to the right child
            }
        }

        // Return the predecessor and successor as a pair
        return {pre, suc};
    }
};

// Helper function to insert a new value in the BST
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) return new TreeNode(val); // If the tree is empty, create a new node with the given value
    if (val < root->val)                 // If the given value is less than the current node's value
        root->left = insertNode(root->left, val); // Recursively insert into the left subtree
    else                                 // If the given value is greater than or equal to the current node's value
        root->right = insertNode(root->right, val); // Recursively insert into the right subtree
    return root;                         // Return the root node
}

// Helper function to perform inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (!root) return;          // If the tree is empty, do nothing
    inorderTraversal(root->left); // Recursively traverse the left subtree
    cout << root->val << " ";     // Print the current node's value
    inorderTraversal(root->right); // Recursively traverse the right subtree
}

int main() {
    // Create the root of the tree
    TreeNode* root = nullptr;

    // Insert values into the BST
    root = insertNode(root, 20);
    root = insertNode(root, 8);
    root = insertNode(root, 22);
    root = insertNode(root, 4);
    root = insertNode(root, 12);
    root = insertNode(root, 10);
    root = insertNode(root, 14);

    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    Solution solution;
    int key = 10;

    pair<int, int> result = solution.predecessorSuccessor(root, key);
    cout << "Predecessor of " << key << " is: " << result.first << endl;
    cout << "Successor of " << key << " is: " << result.second << endl;

    return 0;
}
