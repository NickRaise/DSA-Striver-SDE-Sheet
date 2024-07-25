// k-th smallest element in BST

// Input:
//       2
//     /   \
//    1     3
// K = 2
// Output: 2
// Explanation: 2 is the 2nd smallest element in the BST


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
    // Function to find the kth smallest element in the BST
    int kthSmallest(TreeNode* root, int k) {
        int count = 0; // Initialize the counter to track the number of nodes visited
        return inorderHelper(root, k, count); // Call the helper function with the root, k, and count
    }

private:
    // Helper function to perform inorder traversal and find the kth smallest element
    int inorderHelper(TreeNode* root, int k, int &count) {
        // If the root is null, return -1 (indicating the kth smallest element is not found)
        if (!root) return -1;

        // Recursively call the helper function on the left subtree
        int leftSide = inorderHelper(root->left, k, count);
        // If the left subtree returns a valid value, return it
        if (leftSide != -1) return leftSide;
        
        // Increment the count for the current node
        count++;
        // If the count matches k, return the current node's value
        if (count == k) return root->val;

        // Recursively call the helper function on the right subtree
        int rightSide = inorderHelper(root->right, k, count);
        // Return the value from the right subtree (if valid) or -1 if not found
        return rightSide;
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
    Solution solution;

    // Insert values into the BST
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 6);

    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    int k = 3;
    int kthSmallestValue = solution.kthSmallest(root, k);

    cout << "The " << k << "rd smallest value in the BST is: " << kthSmallestValue << endl;

    return 0;
}
