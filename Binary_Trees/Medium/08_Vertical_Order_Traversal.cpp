// Vertical Order Traversal of Binary Tree

// Problem Statement: Given a Binary Tree, return the Vertical Order Traversal of it starting from the Leftmost level to the Rightmost level. 
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

// Input:
//            1
//          /   \
//        2       3
//      /   \   /   \
//    4      5 6      7
//               \      \
//                8      9           
// Output: 
// 4 2 1 5 6 3 8 7 9 




#include <iostream>
#include <vector>
#include <map>
#include <set>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; // Resultant vector of vectors to store vertical order traversal
        if (!root) return ans; // If the tree is empty, return an empty vector

        // Map to store nodes based on horizontal distance (HD) and level
        map<int, map<int, multiset<int>>> mp;
        // Queue for BFS, storing pairs of TreeNode* and its HD and level
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); // Push the root node with HD = 0 and level = 0

        while (!q.empty()) {
            auto temp = q.front(); // Get the front element from the queue
            TreeNode *node = temp.first; // Current node
            int HD = temp.second.first; // Horizontal Distance of the current node
            int level = temp.second.second; // Level of the current node
            q.pop(); // Remove the front element from the queue

            // Insert the node value into the map based on its HD and level
            mp[HD][level].insert(node->val);

            // If the left child exists, push it to the queue with HD - 1 and level + 1
            if (node->left)
                q.push({node->left, {HD - 1, level + 1}});
            // If the right child exists, push it to the queue with HD + 1 and level + 1
            if (node->right)
                q.push({node->right, {HD + 1, level + 1}});
        }

        // Traverse the map to construct the answer
        for (auto singleElement : mp) {
            vector<int> temp;
            for (auto levelAndData : singleElement.second) {
                // Insert all elements of the current level into the temporary vector
                temp.insert(temp.end(), levelAndData.second.begin(), levelAndData.second.end());
            }
            // Add the temporary vector to the answer
            ans.push_back(temp);
        }

        return ans; // Return the vertical order traversal
    }
};

// Function to create a sample tree and call the verticalTraversal function
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
    vector<vector<int>> result = sol.verticalTraversal(root);

    // Print the vertical order traversal
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
