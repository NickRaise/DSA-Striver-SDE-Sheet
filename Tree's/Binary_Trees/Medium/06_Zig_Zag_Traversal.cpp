// Zig Zag Traversal Of Binary Tree


// Input:
//         1
//       /   \
//      2     3
//     / \   / \
//    4   5 6   7
   
// Output:
// 1 3 2 4 5 6 7
// Explanation:
// For level 1 going left to right, we get traversal as {1}.
// For level 2 going right to left, we get traversal as {3,2}.
// For level 3 going left to right, we get traversal as {4,5,6,7}.
// Merging all this traversals in single array we get {1,3,2,4,5,6,7}



#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans; // Resultant vector of vectors to store each level's nodes
        if (!root) return ans; // If the tree is empty, return an empty vector

        queue<TreeNode*> q; // Queue for BFS
        q.push(root); // Push the root node to the queue
        bool rev = false; // Flag to indicate whether to reverse the order of nodes at the current level

        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            vector<int> level(size); // Vector to store the current level's nodes

            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front(); // Get the front node from the queue
                q.pop(); // Remove the node from the queue

                // Push the left and right children of the current node to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                // Add the current node's value to the level vector
                // If rev is true, insert the value in reverse order
                if (rev)
                    level[size - i - 1] = node->val;
                else
                    level[i] = node->val;
            }
            ans.push_back(level); // Add the current level's nodes to the result
            rev = !rev; // Toggle the rev flag for the next level
        }

        return ans; // Return the zigzag level order traversal
    }
};

// Function to create a sample tree and call the zigzagLevelOrder function
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
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    
    // Print the zigzag level order traversal
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

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
