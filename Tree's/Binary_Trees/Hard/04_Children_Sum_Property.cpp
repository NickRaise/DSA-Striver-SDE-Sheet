// Children Sum Property

// Problem Statement: Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property. 
// The Children Sum Property in a binary tree states that for every node, the sum of its children's values (if they exist) should be equal to the node's value. 
// If a child is missing, it is considered as having a value of 0.

// Note:
//     ->The node values can be increased by any positive integer any number of times, but decrementing any node value is not allowed.
//     ->A value for a NULL node can be assumed as 0.
//     ->We cannot change the structure of the given binary tree.



#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;               // Value of the node
    TreeNode *left;        // Pointer to the left child
    TreeNode *right;       // Pointer to the right child

    // Default constructor initializing value to 0 and children to nullptr
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor initializing value and setting children to nullptr
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor initializing value and setting children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to modify the tree according to the given problem statement
void changeTree(TreeNode *root) {
    // Base case: If the node is null, return
    if (!root) return;

    // Base case: If the node is a leaf node, return
    if (!root->left && !root->right) return;

    // Calculate the sum of the values of the left and right children
    int leftSum = (root->left) ? root->left->val : 0;
    int rightSum = (root->right) ? root->right->val : 0;
    int childSum = leftSum + rightSum;

    // If the root's value is less than the sum of its children, update the root's value
    if (root->val < childSum)
        root->val = childSum;
    // If the root's value is greater than the sum of its children, update the children's values
    else if (root->val > childSum) {
        if (root->left)
            root->left->val = root->val;
        if (root->right)
            root->right->val = root->val;
    }

    // Recursively call the function for the left and right subtrees
    changeTree(root->left);
    changeTree(root->right);

    // Recalculate the sum of the values of the left and right children
    leftSum = (root->left) ? root->left->val : 0;
    rightSum = (root->right) ? root->right->val : 0;
    childSum = leftSum + rightSum;

    // Update the root's value to the sum of the values of its children
    root->val = childSum;
}

// Function to create a sample tree and call the changeTree function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Print the tree before modification
    cout << "Tree before modification:" << endl;
    cout << "    " << root->val << endl;
    cout << "   / \\ " << endl;
    cout << "  " << root->left->val << "   " << root->right->val << endl;
    cout << " / \\   \\" << endl;
    cout << root->left->left->val << "   " << root->left->right->val << "   " << root->right->right->val << endl;

    // Modify the tree
    changeTree(root);

    // Print the tree after modification
    cout << "\nTree after modification:" << endl;
    cout << "    " << root->val << endl;
    cout << "   / \\ " << endl;
    cout << "  " << root->left->val << "   " << root->right->val << endl;
    cout << " / \\   \\" << endl;
    cout << root->left->left->val << "   " << root->left->right->val << "   " << root->right->right->val << endl;

    // Clean up dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
