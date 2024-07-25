// Recover Binary Search Tree

// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
// Recover the tree without changing its structure.


//         3                       2
//        /  \                    / \
//      1     4       =>         1   4
//           /                      /
//         2                       3

// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // For std::swap

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    /**
     * Function to recover the BST where exactly two nodes have been swapped by mistake.
     * @param root - The root of the BST.
     */
    void recoverTree(TreeNode* root) {
        if (!root)
            return;

        // Initialize the pointers used for detecting swapped nodes
        first = second = middle = prev = nullptr;

        // Perform the inorder traversal to find the misplaced nodes
        inorderToRecoverTree(root);

        // Fix the swapped nodes
        if (first && second) {
            // If two pairs are found, swap the first and second
            swap(first->val, second->val);
        } else if (first && middle) {
            // If only one pair is found, swap the first and middle
            swap(first->val, middle->val);
        }
    }

private:
    // Pointers to keep track of the nodes that need to be swapped
    TreeNode *first, *second, *middle, *prev;

    /**
     * Inorder traversal to detect the swapped nodes in the BST.
     * @param root - The current node being processed.
     */
    void inorderToRecoverTree(TreeNode* root) {
        if (!root) return;

        // Traverse the left subtree
        inorderToRecoverTree(root->left);

        // If the previous node is greater than the current node, it means there's a violation of BST properties
        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                // If this is the first violation, mark these two nodes as 'first' and 'middle'
                first = prev;
                middle = root;
            } else {
                // If this is the second violation, mark this node as 'second'
                second = root;
            }
        }

        // Mark this node as the previous node before moving to the right subtree
        prev = root;

        // Traverse the right subtree
        inorderToRecoverTree(root->right);
    }
};

// Function to perform inorder traversal of BST and collect values in a vector
void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;

    inorderTraversal(root->left, result); // Traverse the left subtree
    result.push_back(root->val);          // Add the current node's value to the result vector
    inorderTraversal(root->right, result);// Traverse the right subtree
}

// Function to print the values in a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " "; // Print each value
    }
    cout << endl;
}

// Main function to demonstrate usage
int main() {
    // Example usage:
    // Create an example BST where nodes 1 and 3 are swapped
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    // Create a Solution object
    Solution sol;

    // Recover the BST
    sol.recoverTree(root);

    // Perform inorder traversal to verify the tree is recovered
    vector<int> result;
    inorderTraversal(root, result);

    // Print the result
    cout << "Inorder traversal after recovering BST: ";
    printVector(result);

    return 0;
}
