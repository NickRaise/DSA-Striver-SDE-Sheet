// Left View of Binary Tree

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8   



#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
template <typename T>
struct BinaryTreeNode {
    T data; // The value of the node
    BinaryTreeNode *left; // Pointer to the left child
    BinaryTreeNode *right; // Pointer to the right child
    // Default constructor
    BinaryTreeNode() : data(0), left(nullptr), right(nullptr) {}
    // Constructor with value initialization
    BinaryTreeNode(T x) : data(x), left(nullptr), right(nullptr) {}
    // Constructor with value and children initialization
    BinaryTreeNode(T x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
};

void leftViewHelper(BinaryTreeNode<int>* root, int level, vector<int> &ans) {
    if (!root) return; // If the current node is null, return

    // If the current level is not yet in the vector, add the current node's value
    if (ans.size() == level)
        ans.push_back(root->data);

    // Traverse the left subtree first to ensure the leftmost node at each level is captured
    if (root->left)
        leftViewHelper(root->left, level + 1, ans);

    // Traverse the right subtree
    if (root->right)
        leftViewHelper(root->right, level + 1, ans);
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ans; // Vector to store the left view nodes
    if (!root) return ans; // If the tree is empty, return an empty vector

    leftViewHelper(root, 0, ans); // Call the helper function to populate the vector

    return ans; // Return the left view nodes
}

// Function to create a sample tree and call the printLeftView function
int main() {
    // Create nodes of the tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    vector<int> result = printLeftView(root);

    // Print the left view of the binary tree
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

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
