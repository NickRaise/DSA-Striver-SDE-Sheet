// Construct Binary Tree From Inorder and Preorder Traversal

// Sample Input 1:
// 5
// 1 2 4 7 3
// 4 2 7 1 3
// Sample Output 1:
// 1 2 3 4 7

#include <iostream>
#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        // If the input arrays are empty, return nullptr
        if (n == 0) return nullptr;

        unordered_map<int, int> mp;

        // Create a map to store the index of each value in the inorder array for quick lookup
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        // Call the helper function to build the tree
        TreeNode *head = helperFunction(preorder, 0, n - 1, inorder, 0, n - 1, mp);

        return head;
    }

private:
    TreeNode *helperFunction(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &mp) {
        // Base case: if there are no elements to process, return nullptr
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // The root node value is the first element in the preorder array
        int nodeData = preorder[preStart];

        // Create a new tree node with the root node value
        TreeNode *node = new TreeNode(nodeData);

        // Find the index of the root node value in the inorder array
        int inNode = mp[nodeData];

        // Calculate the size of the left subtree
        int nodeSize = inNode - inStart;

        // Recursively build the left subtree
        node->left = helperFunction(preorder, preStart + 1, preStart + nodeSize, inorder, inStart, inNode - 1, mp);

        // Recursively build the right subtree
        node->right = helperFunction(preorder, preStart + nodeSize + 1, preEnd, inorder, inNode + 1, inEnd, mp);

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

    // Define the preorder and inorder traversal arrays
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Build the binary tree from the preorder and inorder arrays
    TreeNode* root = sol.buildTree(preorder, inorder);

    // Print the inorder traversal of the constructed binary tree
    cout << "Inorder traversal of the constructed binary tree: ";
    printInorder(root);
    cout << endl;

    // Clean up memory
    // Deleting nodes is omitted for simplicity, but should be implemented in practice to avoid memory leaks

    return 0;
}
