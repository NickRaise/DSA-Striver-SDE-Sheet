// All Nodes at Distance K in Binary Tree

// Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. 
// No parent pointers are available.

// Input:      
//           20
//         /    \
//       8       22 
//     /   \
//    4    12 
//        /   \
//       10    14
// Target Node = 8
// K = 2
// Output: 10 14 22
// Explanation: The three nodes at distance 2
// from node 8 are 10, 14, 22.


#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;               // Value of the node
    TreeNode *left;        // Pointer to the left child
    TreeNode *right;       // Pointer to the right child

    // Constructor initializing value and setting children to nullptr
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to map each node to its parent node
    void mapParents(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent_nodes) {
        queue<TreeNode*> q;  // Queue for level order traversal
        q.push(root);        // Push the root node into the queue
        parent_nodes[root] = nullptr;  // Root node has no parent

        while (!q.empty()) {
			TreeNode *current = q.front();  // Get the front node
			q.pop();  // Remove the front node from the queue

			// If the current node has a left child
			if (current->left) {
				parent_nodes[current->left] = current;  // Map the left child to its parent
				q.push(current->left);  // Push the left child into the queue
			}
			// If the current node has a right child
			if (current->right) {
				parent_nodes[current->right] = current;  // Map the right child to its parent
				q.push(current->right);  // Push the right child into the queue
			}
            
        } 
    }

    // Function to find all nodes at distance k from the target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return vector<int>();  // If the root is null, return an empty vector

        unordered_map<TreeNode* , TreeNode*> parent_nodes;  // Map to store parent nodes
        mapParents(root, parent_nodes);  // Call mapParents to fill the parent_nodes map

        unordered_map<TreeNode*, bool> visited;  // Map to track visited nodes
        queue<TreeNode*> q;  // Queue for level order traversal
        q.push(target);  // Push the target node into the queue
        visited[target] = true;  // Mark the target node as visited
        int distance = 0;  // Initialize the distance to 0

        while (!q.empty()) {
            if (distance == k) break;  // If the current distance equals k, break the loop
            distance++;  // Increment the distance

            int size = q.size();  // Number of nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();  // Get the front node
                q.pop();  // Remove the front node from the queue

                // If the current node has a left child and it has not been visited
                if (node->left && !visited[node->left]) {
                    q.push(node->left);  // Push the left child into the queue
                    visited[node->left] = true;  // Mark the left child as visited
                }
                // If the current node has a right child and it has not been visited
                if (node->right && !visited[node->right]) {
                    q.push(node->right);  // Push the right child into the queue
                    visited[node->right] = true;  // Mark the right child as visited
                }
                // If the parent of the current node exists and it has not been visited
                if (parent_nodes[node] && !visited[parent_nodes[node]]) {
                    q.push(parent_nodes[node]);  // Push the parent node into the queue
                    visited[parent_nodes[node]] = true;  // Mark the parent node as visited
                }
            }
        }

        vector<int> ans;  // Vector to store the answer
        // Collect all the nodes at distance k
        while (!q.empty()) {
            ans.push_back(q.front()->val);  // Add the value of the front node to the answer
            q.pop();  // Remove the front node from the queue
        }
        return ans;  // Return the answer
    }
};

// Function to create a sample binary tree and test the distanceK function
int main() {
    // Create nodes
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Create Solution object
    Solution sol;

    // Target node and distance k
    TreeNode* target = root->left; // Node with value 5
    int k = 2;

    // Find nodes at distance k from target
    vector<int> result = sol.distanceK(root, target, k);

    // Print the result
    cout << "Nodes at distance " << k << " from target node " << target->val << " are: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
