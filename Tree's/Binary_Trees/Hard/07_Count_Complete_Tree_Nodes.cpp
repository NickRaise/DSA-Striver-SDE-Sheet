// Count Complete Tree Nodes

// Given the root of a complete binary tree, return the number of the nodes in the tree.

// Every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. 
// It can have between 1 and 2h nodes inclusive at the last level h.

// Input: 
// root = [1,2,3,4,5,6]
// Output: 
// 6
// Explanation: 
// There are a total of 6 nodes in the given tree.


#include <iostream>
#include <cmath>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        // If the tree is empty, return 0
        if (!root) return 0;

        // Calculate the height of the leftmost and rightmost paths
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        // If the heights are the same, the tree is a perfect binary tree
        if (leftHeight == rightHeight) {
            // Return the total number of nodes in a perfect binary tree: 2^height - 1
            return (1 << leftHeight) - 1;
        }

        // If the heights are different, recursively count the nodes in the left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    // Helper function to find the height of the leftmost path
    int findLeftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    // Helper function to find the height of the rightmost path
    int findRightHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->right;
        }
        return height;
    }
};

// Function to create a simple binary tree for demonstration
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    return root;
}

int main() {
    Solution sol;

    // Create a simple binary tree
    TreeNode* root = createTree();

    // Count the nodes in the binary tree
    int nodeCount = sol.countNodes(root);

    // Output the result
    cout << "Number of nodes in the binary tree: " << nodeCount << endl;

    // Clean up memory
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
