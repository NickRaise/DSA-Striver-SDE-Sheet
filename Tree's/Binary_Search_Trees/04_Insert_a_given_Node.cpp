// Insert a given Node in Binary Search Tree

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
    // Function to insert a new value into the BST
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the root is null, create a new node with the given value and return it.
        if (!root) return new TreeNode(val);
        
        // If the value is greater than the current node's value, insert into the right subtree.
        if (root->val < val) {
            if (root->right)
                insertIntoBST(root->right, val);
            else 
                root->right = new TreeNode(val);
        } 
        // If the value is less than or equal to the current node's value, insert into the left subtree.
        else {
            if (root->left)
                insertIntoBST(root->left, val);
            else 
                root->left = new TreeNode(val);
        }

        // Return the root node after insertion.
        return root;
    }
};

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
    root = solution.insertIntoBST(root, 4);
    root = solution
