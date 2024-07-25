// Lowest Common Ancestor in a BST

// Input:
//               5
//             /   \
//           4      6
//          /        \
//         3          7
//                     \
//                      8
// n1 = 7, n2 = 8
// Output: 7


#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize node with a specific value, and left, right pointers to nullptr.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the lowest common ancestor (LCA) of two nodes in a BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the tree is empty, return nullptr
        if (!root) return nullptr;

        // If both p and q are greater than root, LCA must be in the right subtree
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // If both p and q are less than root, LCA must be in the left subtree
        else if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // If p and q are on either side of root, or one of them is the root itself, root is the LCA
        else return root;
    }
};

// Helper function to insert a new value in the BST
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}

// Helper function to perform inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create the root of the tree
    TreeNode* root = nullptr;

    // Insert values into the BST
    root = insertNode(root, 6);
    root = insertNode(root, 2);
    root = insertNode(root, 8);
    root = insertNode(root, 0);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    root = insertNode(root, 3);
    root = insertNode(root, 5);

    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    Solution solution;
    TreeNode* p = root->left; // Node with value 2
    TreeNode* q = root->left->right->right; // Node with value 5

    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "The lowest common ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "The lowest common ancestor was not found in the tree." << endl;

    return 0;
}
