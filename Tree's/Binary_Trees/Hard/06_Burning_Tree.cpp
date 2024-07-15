// Burning Tree

// Given a binary tree and a node data called target. 
// Find the minimum time required to burn the complete binary tree if the target is set on fire. 
// It is known that in 1 second all nodes connected to a given node get burned. 
// That is its left child, right child, and parent.

// Input:      
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10
// Target Node = 8
// Output: 7
// Explanation: If leaf with the value 
// 8 is set on fire. 
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree.



#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;              // Value of the node
    Node *left;            // Pointer to the left child
    Node *right;           // Pointer to the right child

    // Constructor initializing value and setting children to nullptr
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the minimum time to burn the entire binary tree from the target node
    int minTime(Node* root, int target) 
    {
        if (!root) return 0;

        unordered_map<Node*, Node*> parent_nodes; // Map to store parent nodes
        mapParentNode(root, parent_nodes); // Fill the parent_nodes map

        Node* targetNode; // Pointer to the target node
        findTargetNode(root, target, targetNode); // Find the target node

        int time = -1; // Initialize time to -1

        unordered_map<Node*, bool> visited; // Map to track visited nodes
        queue<Node*> q; // Queue for level order traversal
        q.push(targetNode); // Push the target node into the queue
        visited[targetNode] = true; // Mark the target node as visited

        while (!q.empty()) {
            time++; // Increment the time
            int size = q.size(); // Number of nodes at the current level

            for (int i = 0; i < size; i++) {
                Node* node = q.front(); // Get the front node
                q.pop(); // Remove the front node from the queue

                // If the current node has a left child and it has not been visited
                if (node->left && !visited[node->left]) {
                    q.push(node->left); // Push the left child into the queue
                    visited[node->left] = true; // Mark the left child as visited
                }
                // If the current node has a right child and it has not been visited
                if (node->right && !visited[node->right]) {
                    q.push(node->right); // Push the right child into the queue
                    visited[node->right] = true; // Mark the right child as visited
                }
                // If the parent of the current node exists and it has not been visited
                if (parent_nodes[node] && !visited[parent_nodes[node]]) {
                    q.push(parent_nodes[node]); // Push the parent node into the queue
                    visited[parent_nodes[node]] = true; // Mark the parent node as visited
                }
            }
        }

        return time; // Return the time
    }

private:
    // Function to map each node to its parent node
    void mapParentNode(Node* root, unordered_map<Node*, Node*>& parent_nodes) {
        queue<Node*> q; // Queue for level order traversal
        q.push(root); // Push the root node into the queue
        parent_nodes[root] = nullptr; // Root node has no parent

        while (!q.empty()) {
            Node* node = q.front(); // Get the front node
            q.pop(); // Remove the front node from the queue

            // If the current node has a left child
            if (node->left) {
                q.push(node->left); // Push the left child into the queue
                parent_nodes[node->left] = node; // Map the left child to its parent
            }

            // If the current node has a right child
            if (node->right) {
                q.push(node->right); // Push the right child into the queue
                parent_nodes[node->right] = node; // Map the right child to its parent
            }
        }
    }

    // Function to find the target node in the tree
    void findTargetNode(Node* root, int target, Node*& targetNode) {
        if (!root) return;

        // If the current node has the target value, set targetNode to the current node
        if (target == root->data) {
            targetNode = root;
            return;
        }

        // Recur for the left subtree
        if (root->left)
            findTargetNode(root->left, target, targetNode);

        // Recur for the right subtree
        if (root->right)
            findTargetNode(root->right, target, targetNode);
    }
};

// Function to create a sample binary tree and test the minTime function
int main() {
    // Create nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Create Solution object
    Solution sol;

    // Target value
    int target = 5;

    // Find the minimum time to burn the tree from the target node
    int result = sol.minTime(root, target);

    // Print the result
    cout << "Minimum time to burn the tree from target node " << target << " is: " << result << " units of time." << endl;

    return 0;
}
