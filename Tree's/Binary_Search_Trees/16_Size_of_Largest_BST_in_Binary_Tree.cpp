// Size of Largest BST in Binary Tree

// Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
// Note: Here Size equals the number of nodes in the subtree.

// Input:    6
//         /   \
//       6      2              
//        \    / \
//         2  1   3
// Output: 3
// Explanation: The following sub-tree is a BST of size 3:  2
//                                                        /   \
//                                                       1     3



#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

/**
 * Class to store the size, minimum value, and maximum value of a BST subtree.
 */
class NodeData {
public:
    int size;
    int minValue;
    int maxValue;

    NodeData(int size, int minValue, int maxValue) {
        this->size = size;
        this->minValue = minValue;
        this->maxValue = maxValue;
    }
};

class Solution {
public:
    /**
     * Function to return the size of the largest subtree which is also a BST.
     * @param root - The root of the binary tree.
     * @return The size of the largest BST subtree.
     */
    int largestBst(Node *root) {
        if (!root) return 0;

        // Get the NodeData for the root node, which includes the size of the largest BST subtree.
        auto data = helperFunction(root);
        return data.size;
    }

private:
    /**
     * Helper function to determine the largest BST subtree.
     * @param root - The current node being processed.
     * @return A NodeData object containing the size, min value, and max value of the largest BST subtree.
     */
    NodeData helperFunction(Node* root) {
        // Base case: If the current node is nullptr, return size 0, INT_MAX for min value, and INT_MIN for max value.
        if (root == nullptr) return NodeData(0, INT_MAX, INT_MIN);

        // Base case: If the current node is a leaf node, return size 1 with its value as both min and max.
        if (root->left == nullptr && root->right == nullptr)
            return NodeData(1, root->data, root->data);

        // Recursively process the left and right subtrees.
        auto leftData = helperFunction(root->left);
        auto rightData = helperFunction(root->right);

        int size;
        // Check if the current node can be a root of a BST.
        if (leftData.maxValue < root->data && root->data < rightData.minValue) {
            // Calculate the size of the BST subtree.
            size = 1 + leftData.size + rightData.size;
            // Determine the minimum value in the BST subtree.
            int minValue = (leftData.size == 0) ? root->data : leftData.minValue;
            // Determine the maximum value in the BST subtree.
            int maxValue = (rightData.size == 0) ? root->data : rightData.maxValue;
            return NodeData(size, minValue, maxValue);
        } else {
            // If the current node cannot be a root of a BST, return the maximum size from the left or right subtree.
            size = max(leftData.size, rightData.size);
            return NodeData(size, INT_MIN, INT_MAX); // Mark this subtree as invalid BST.
        }
    }
};

int main() {
    // Example usage:
    // Create a binary tree.
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    // Create a Solution object.
    Solution sol;

    // Find the size of the largest BST subtree.
    int largestBSTSize = sol.largestBst(root);

    // Print the result.
    cout << "Size of the largest BST subtree: " << largestBSTSize << endl;

    return 0;
}
