// Symmetric Tree

// Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

// Example 1:
// Input:
//          5
//        /   \
//       1     1
//      /       \
//     2         2
// Output: 
//     True
// Explanation: 
// Tree is mirror image of itself i.e. tree is symmetric

// Example 2:
// Input:
//          5
//        /   \
//       10     10
//      /  \     \
//     20  20     30
// Output: 
//     False




#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data; // The value of the node
    Node *left; // Pointer to the left child
    Node *right; // Pointer to the right child
    // Default constructor
    Node() : data(0), left(nullptr), right(nullptr) {}
    // Constructor with value initialization
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    // Constructor with value and children initialization
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(Node* root) {
        // An empty tree is symmetric
        if (!root) return true;
        // Check symmetry for the left and right subtrees
        return symmetricHelper(root->left, root->right);
    }

private:
    bool symmetricHelper(Node* leftSide, Node* rightSide) {
        // If either of the nodes is null, they should both be null to be symmetric
        if (!leftSide || !rightSide) 
            return leftSide == rightSide;

        // Check if the current nodes' values are equal
        bool currentVal = (leftSide->data == rightSide->data);
        // Check the outer pair (left of left and right of right)
        bool outerCheck = symmetricHelper(leftSide->left, rightSide->right);
        // Check the inner pair (right of left and left of right)
        bool innerCheck = symmetricHelper(leftSide->right, rightSide->left);

        // Both conditions need to be true for the tree to be symmetric
        return (currentVal && outerCheck && innerCheck);
    }
};

// Function to create a sample tree and call the isSymmetric function
int main() {
    // Create nodes of the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    Solution sol;
    bool result = sol.isSymmetric(root);

    // Print whether the binary tree is symmetric
    cout << (result ? "The tree is symmetric." : "The tree is not symmetric.") << endl;

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

