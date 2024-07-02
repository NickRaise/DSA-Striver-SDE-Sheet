// Diameter Of Binary Tree

// The diameter of a binary tree is the length of the longest path between any two end nodes in a tree.
// The number of edges between two nodes represents the length of the path between them.

//          1
//        /   \
//       2     3
//      / \
//     4   7

// Sample Input 1 :
// 1 2 3 4 7 -1 -1 -1 -1 -1 -1
// Sample Output 1 :
// 3

#include <iostream>
#include <algorithm> // for std::max

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

class Solution {
public:
    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // Variable to store the maximum diameter
        maxHeight(root, diameter); // Call the helper function to calculate the height and update the diameter
        return diameter; // Return the diameter
    }

private:
    // Helper function to calculate the height of the tree and update the diameter
    int maxHeight(TreeNode* root, int &maxi) {
        if (!root) return 0; // Base case: if the node is null, the height is 0

        int leftHeight = maxHeight(root->left, maxi); // Recursively calculate the height of the left subtree
        int rightHeight = maxHeight(root->right, maxi); // Recursively calculate the height of the right subtree

        // Update the diameter with the maximum value of the current diameter and the sum of left and right heights
        maxi = max(maxi, leftHeight + rightHeight);

        // Return the height of the tree rooted at this node
        return 1 + max(leftHeight, rightHeight);
    }
};

// Function to create a sample tree and call the diameter function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    // Clean up dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
