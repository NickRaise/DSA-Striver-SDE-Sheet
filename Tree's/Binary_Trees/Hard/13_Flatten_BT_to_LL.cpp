// Flatten Binary Tree to Linked List

// Problem Statement: Given a Binary Tree, convert it to a Linked List where the linked list nodes follow the same order as the pre-order traversal of the binary tree.

// Use the right pointer of the Binary Tree as the ‘next’ pointer for the linked list and set the left pointer to null. Do this in place and do not create extra nodes.

// Input : 
//           1
//         /   \
//        2     5
//       / \     \
//      3   4     6
// Output :
// 1 2 3 4 5 6 
// Explanation: 
// After flattening, the tree looks 
// like this
//     1
//      \
//       2
//        \
//         3
//          \
//           4
//            \
//             5
//              \
//               6 
// Here, left of each node points 
// to NULL and right contains the 
// next node in preorder.The inorder 
// traversal of this flattened tree 
// is 1 2 3 4 5 6.



#include<bits/stdc++.h>
using namespace std;

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
    void flatten(TreeNode* root) {
        TreeNode* current = root; // Start with the root of the tree
        
        // Traverse the tree until all nodes are processed
        while (current) {
            // If the current node has a left child
            if (current->left) {
                // Find the rightmost node in the left subtree
                TreeNode* prev = current->left;
                while (prev->right) {
                    prev = prev->right;
                }
                
                // Connect the right subtree of the current node to the rightmost node of the left subtree
                prev->right = current->right;
                
                // Move the entire left subtree to the right
                current->right = current->left;
                current->left = nullptr; // Set the left child to null
            }
            
            // Move to the right child of the current node
            current = current->right;
        }
    }
};

// Main function to test the flatten function
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // Create a solution object and flatten the tree
    Solution sol;
    sol.flatten(root);

    // Output the flattened tree
    TreeNode* current = root;
    while (current) {
        cout << current->val << " ";
        current = current->right;
    }

    return 0;
}
