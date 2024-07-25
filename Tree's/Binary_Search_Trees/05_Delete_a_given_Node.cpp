// Delete a node from BST



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
    // Function to delete a node with the given key in the BST
    TreeNode* deleteNode(TreeNode* root, int key) {
        // If the root is null, return nullptr.
        if (!root) return nullptr;

        // If the key to be deleted is greater than the root's key, go to the right subtree.
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        // If the key to be deleted is less than the root's key, go to the left subtree.
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            // Node with the key found.
            TreeNode* node = nullptr;
            // If the node has no children, delete the node and return nullptr.
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // If the node has only a right child, replace the node with its right child.
            else if (!root->left) {
                node = root->right;
                delete root;
                return node;
            }
            // If the node has only a left child, replace the node with its left child.
            else if (!root->right) {
                node = root->left;
                delete root;
                return node;
            }
            // If the node has two children, find the in-order successor (smallest in the right subtree).
            else {
                node = root->right;
                TreeNode* temp = node;
                // Find the leftmost child in the right subtree.
                while (temp->left)
                    temp = temp->left;
                // Replace the node's value with the in-order successor's value.
                temp->left = root->left;
                delete root;
                return node;
            }
        }
        // Return the root after deletion.
        return root;
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

    cout << "Inorder Traversal of the BST before deletion: ";
    inorderTraversal(root);
    cout << endl;

    // Delete a node with value 7
    root = solution.deleteNode(root, 7);

    cout << "Inorder Traversal of the BST after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
