// Balance a Binary Search Tree

// Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. 
// Return the balanced BST.

// Input:
//        30
//       /
//      20
//     /
//    10

// Output:
//      20
//    /   \
//  10     30


#include <iostream>
#include <vector>
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
    // Function to balance a BST
    TreeNode* balanceBST(TreeNode* root) {
        // If the tree is empty, return nullptr
        if (!root) return nullptr;

        // Vector to store the inorder traversal of the tree
        vector<int> inorder;
        // Get the inorder traversal of the tree
        getInorder(root, inorder);
        // Get the size of the inorder vector
        int n = inorder.size() - 1;
        // Construct a balanced BST from the inorder traversal
        TreeNode *head = constructBST(inorder, 0, n);
        // Return the new root of the balanced BST
        return head;
    }

private:
    // Helper function to perform inorder traversal and store it in a vector
    void getInorder(TreeNode* root, vector<int> &inorder) {
        if (!root) return; // If the node is null, return

        getInorder(root->left, inorder); // Recursively get the inorder traversal of the left subtree
        inorder.push_back(root->val); // Add the current node's value to the vector
        getInorder(root->right, inorder); // Recursively get the inorder traversal of the right subtree
    }

    // Helper function to construct a balanced BST from inorder traversal
    TreeNode *constructBST(vector<int> &inorder, int start, int end) {
        if (start > end) return nullptr; // Base case: if start index exceeds end index, return nullptr

        int mid = start + (end - start) / 2; // Find the middle element
        TreeNode *node = new TreeNode(inorder[mid]); // Create a new node with the middle element

        // Recursively construct the left and right subtrees
        node->left = constructBST(inorder, start, mid - 1);
        node->right = constructBST(inorder, mid + 1, end);

        return node; // Return the constructed node
    }
};

// Helper function to perform inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (!root) return; // If the node is null, return
    inorderTraversal(root->left); // Recursively traverse the left subtree
    cout << root->val << " "; // Print the value of the current node
    inorderTraversal(root->right); // Recursively traverse the right subtree
}

int main() {
    // Example usage:
    // Create an unbalanced BST
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);

    // Create a Solution object
    Solution sol;
    // Balance the BST
    TreeNode* balancedRoot = sol.balanceBST(root);

    // Print the inorder traversal of the balanced BST
    cout << "Inorder traversal of the balanced BST: ";
    inorderTraversal(balancedRoot);
    cout << endl;

    return 0;
}
