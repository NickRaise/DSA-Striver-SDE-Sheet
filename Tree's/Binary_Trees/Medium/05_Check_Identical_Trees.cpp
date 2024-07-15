//  Check Identical Trees

//  Input:
//      1          1
//    /   \      /   \
//   2     3    2     3
// Output: 
// Yes
// Explanation: 
// There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.



#include <iostream>

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

// Function to check if two binary trees are identical
bool identicalTrees(TreeNode* root1, TreeNode* root2) {
    // If either node is null, check if both are null
    if (!root1 || !root2) {
        return (root1 == root2); // Both should be null for trees to be identical
    }

    // Check if the current nodes' values are the same
    bool valSame = (root1->val == root2->val);

    // Recursively check if the left and right subtrees are identical
    bool leftCheck = identicalTrees(root1->left, root2->left);
    bool rightCheck = identicalTrees(root1->right, root2->right);

    // Return true if the current nodes' values are the same and both subtrees are identical
    return (valSame && leftCheck && rightCheck);
}

// Function to create a sample tree and call the identicalTrees function
int main() {
    // Create nodes of the first tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    // Create nodes of the second tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    // Check if the two trees are identical
    bool areIdentical = identicalTrees(root1, root2);
    cout << "Are the two binary trees identical? " << (areIdentical ? "Yes" : "No") << endl;

    // Clean up dynamically allocated nodes for the first tree
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    // Clean up dynamically allocated nodes for the second tree
    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
