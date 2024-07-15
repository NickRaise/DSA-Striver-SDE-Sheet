// Height of Binary Tree


#include <iostream>
#include <algorithm> // for std::max

using namespace std;

// Definition for a binary tree node.
template <typename T>
struct TreeNode {
    T data; // The value of the node
    TreeNode *left; // Pointer to the left child
    TreeNode *right; // Pointer to the right child
    // Default constructor
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    // Constructor with value initialization
    TreeNode(T x) : data(x), left(nullptr), right(nullptr) {}
    // Constructor with value and children initialization
    TreeNode(T x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

template <typename T>
int heightOfBinaryTree(TreeNode<T> *root) {
    if (!root) return 0; // Base case: if the node is null, the height is 0

    int leftHeight = heightOfBinaryTree(root->left); // Recursively calculate the height of the left subtree
    int rightHeight = heightOfBinaryTree(root->right); // Recursively calculate the height of the right subtree

    return 1 + max(leftHeight, rightHeight); // The height of the tree is 1 + the maximum height of the subtrees
}

// Function to create a sample tree and call the height function
int main() {
    // Create nodes of the tree
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    int height = heightOfBinaryTree(root);
    cout << "Height of the binary tree: " << height << endl;

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
