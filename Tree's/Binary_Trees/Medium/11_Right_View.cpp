// Binary Tree Right Side View

// Given the root of a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

#include <iostream>
#include <vector>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; // Vector to store the right view nodes
        if (!root) return ans; // If the tree is empty, return an empty vector

        rightViewHelper(root, 0, ans); // Call the helper function to populate the vector

        return ans; // Return the right view nodes
    }

private:
    void rightViewHelper(TreeNode* root, int level, vector<int> &ans) {
        if (!root) return; // If the current node is null, return

        // If the current level is not yet in the vector, add the current node's value
        if (ans.size() == level)
            ans.push_back(root->val);

        // Traverse the right subtree first to ensure the rightmost node at each level is captured
        if (root->right)
            rightViewHelper(root->right, level + 1, ans);

        // Traverse the left subtree
        if (root->left)
            rightViewHelper(root->left, level + 1, ans);
    }
};

// Function to create a sample tree and call the rightSideView function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    // Print the right view of the binary tree
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
