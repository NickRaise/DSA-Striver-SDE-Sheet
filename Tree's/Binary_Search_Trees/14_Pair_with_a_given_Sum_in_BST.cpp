// Find a pair with given sum in BST


// Input:
//         2
//       /   \
//      1     3
// sum = 5
// Output: 1 
// Explanation: 
// Nodes with value 2 and 3 sum up to 5.


#include <iostream>
#include <vector>
#include <stack>

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

class BSTIterator {
private:
    stack<TreeNode *> st; // Stack to hold nodes during traversal
    bool reverse; // Flag to indicate the direction of traversal

    /**
     * Push all nodes from a given root in the specified direction
     * - If reverse is false, push all nodes from root to the leftmost node (inorder)
     * - If reverse is true, push all nodes from root to the rightmost node (reverse inorder)
     */
    void pushAllNodes(TreeNode *root) {
        while (root) {
            st.push(root); // Push the current node onto the stack
            if (reverse) {
                root = root->right; // Move to the right child for reverse inorder
            } else {
                root = root->left; // Move to the left child for inorder
            }
        }
    }

public:
    /**
     * Constructor to initialize the iterator with a root and direction
     * @param root - The root of the BST
     * @param Reverse - The direction of traversal (false for inorder, true for reverse inorder)
     */
    BSTIterator(TreeNode *root, bool Reverse) : reverse(Reverse) {
        pushAllNodes(root); // Populate the stack with initial nodes
    }

    /**
     * Check if there are more nodes to iterate
     * @return true if the stack is not empty, false otherwise
     */
    bool hasNext() {
        return !st.empty();
    }

    /**
     * Get the next node's value in the traversal
     * @return The value of the next node, or -1 if the stack is empty
     */
    int next() {
        if (st.empty()) return -1; // Return -1 if stack is empty

        TreeNode *node = st.top(); // Get the top node from the stack
        st.pop(); // Remove the top node from the stack

        // Depending on the direction, push nodes from the opposite subtree
        if (!reverse) {
            pushAllNodes(node->right); // For inorder, push nodes from the right subtree
        } else {
            pushAllNodes(node->left); // For reverse inorder, push nodes from the left subtree
        }

        return node->val; // Return the value of the current node
    }
};

class Solution {
public:
    /**
     * Function to find if there exist two elements in the BST that sum up to k
     * @param root - The root of the BST
     * @param k - The target sum
     * @return true if there exists a pair with sum equal to k, false otherwise
     */
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false; // If the tree is empty, return false

        // Initialize two iterators: one for inorder and one for reverse inorder
        BSTIterator start(root, false); // Iterator for the smallest values (inorder)
        BSTIterator end(root, true);    // Iterator for the largest values (reverse inorder)

        int startVal = start.next(); // Get the next smallest value
        int endVal = end.next();     // Get the next largest value

        // Two-pointer technique to find the pair with sum equal to k
        while (startVal != endVal) {
            if (startVal + endVal == k) {
                return true; // Pair found
            } else if (startVal + endVal < k) {
                startVal = start.next(); // Move the start pointer to the next smallest value
            } else {
                endVal = end.next(); // Move the end pointer to the next largest value
            }
        }

        return false; // No such pair found
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
    // Create an example BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // Create a Solution object
    Solution sol;

    // Find if there exists a pair with sum equal to 9
    bool result = sol.findTarget(root, 9);

    // Print the result
    cout << "Pair with sum 9 exists: " << (result ? "Yes" : "No") << endl;

    return 0;
}
