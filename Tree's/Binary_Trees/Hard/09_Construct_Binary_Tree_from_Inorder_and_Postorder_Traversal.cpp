// Construct Binary Tree from Inorder and Postorder Traversal

// You are given arrays 'inOrder' and 'postOrder', which represent 'inorder' traversal and 'postorder' traversal of a 'Binary Tree' respectively.
// Construct a 'Binary Tree' represented by the given arrays and return it's head.

// Input: n = 8, inorder[] = {4, 8, 2, 5, 1, 6, 3, 7}, postorder[] = {8, 4, 5, 2, 6, 7, 3, 1}
// Output: 1 2 4 8 5 3 6 7
// Explanation: For the given postorder and inorder traversal of tree the  resultant binary tree will be
//           1
//        /      \
//      2        3
//    /  \      /  \
//   4   5    6   7
//    \
//     8

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to build a tree from inorder and postorder traversal arrays
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        if (n == 0) return nullptr;

        // Map to store the index of each value in the inorder array for quick lookup
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        // Call the helper function to build the tree
        TreeNode *head = helperFunction(inorder, 0, n - 1, postorder, 0, n - 1, mp);

        return head;
    }

private:
    // Recursive helper function to build the tree
    TreeNode * helperFunction(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int> &mp) {
        // Base case: if there are no elements to process, return nullptr
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        // The root node value is the last element in the postorder array
        int nodeData = postorder[postEnd];

        // Create a new tree node with the root node value
        TreeNode *node = new TreeNode(nodeData);

        // Find the index of the root node value in the inorder array
        int InNodeIdx = mp[nodeData];

        // Calculate the size of the right subtree
        int leftSize = inEnd - InNodeIdx;

        // Recursively build the left subtree
        node->left = helperFunction(inorder, inStart, InNodeIdx - 1, postorder, postStart, postEnd - leftSize - 1, mp);

        // Recursively build the right subtree
        node->right = helperFunction(inorder, InNodeIdx + 1, inEnd, postorder, postEnd - leftSize, postEnd - 1, mp);

        return node;
    }
};

// Function to print the inorder traversal of the binary tree
void printInorder(TreeNode* node) {
    if (node == nullptr)
        return;

    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    Solution sol;

    // Define the inorder and postorder traversal arrays
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Build the binary tree from the inorder and postorder arrays
    TreeNode* root = sol.buildTree(inorder, postorder);

    // Print the inorder traversal of the constructed binary tree
    cout << "Inorder traversal of the constructed binary tree: ";
    printInorder(root);
    cout << endl;

    // Clean up memory
    // Deleting nodes is omitted for simplicity, but should be implemented in practice to avoid memory leaks

    return 0;
}
