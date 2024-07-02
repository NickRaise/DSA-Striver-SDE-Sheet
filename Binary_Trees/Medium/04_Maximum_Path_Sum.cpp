// Maximum path sum from any node

// Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

// Example 1:
// Input:
//      10
//     /  \
//    2   -25
//   / \  /  \
//  20 1  3  4

// Output: 32
// Explanation: Path in the given tree goes
// like 10 , 2 , 20 which gives the max
// sum as 32.


#include <iostream>
#include <climits> // for INT_MIN
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
    // Function to calculate the maximum path sum in the binary tree
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN; // Initialize sum to the smallest possible value
        maxSum(root, sum); // Call the helper function to calculate the height and update the sum
        return sum; // Return the maximum path sum
    }

private:
    // Helper function to calculate the height of the tree and update the maximum path sum
    int maxSum(TreeNode* root, int &sum) {
        if (!root) return 0; // Base case: if the node is null, the height is 0

        // Recursively calculate the maximum path sum of the left and right subtrees
        // We take the maximum of 0 and the recursive result to ensure that we do not consider negative sums
        // This is because a negative sum would decrease the overall path sum, so we ignore such paths by taking max with 0
        int leftSum = max(0, maxSum(root->left, sum));
        int rightSum = max(0, maxSum(root->right, sum));

        // Update the maximum path sum with the maximum value of the current sum and the sum of the current node's value and its left and right subtrees
        sum = max(sum, leftSum + rightSum + root->val);

        // Return the height of the tree rooted at this node
        return root->val + max(leftSum, rightSum);
    }
};

// Function to create a sample tree and call the maxPathSum function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    int maxPathSum = sol.maxPathSum(root);
    cout << "Maximum path sum of the binary tree: " << maxPathSum << endl;

    // Clean up dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
