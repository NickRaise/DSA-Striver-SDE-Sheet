// Top View of Binary Tree

// Given below is a binary tree. The task is to print the top view of binary tree. 
// Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. 
// For the given below tree

//        1
//     /     \
//    2      3
//   /  \   / \
// 4     5 6   7

// Top view will be: 4 2 1 3 7



#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int data; // The value of the node
    Node *left; // Pointer to the left child
    Node *right; // Pointer to the right child
    // Default constructor
    Node() : data(0), left(nullptr), right(nullptr) {}
    // Constructor with value initialization
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    // Constructor with value and children initialization
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans; // Vector to store the top view nodes
        if (!root) return ans; // If the tree is empty, return an empty vector

        // Map to store the first node at each horizontal distance (HD)
        map<int, Node*> mp;
        // Queue for BFS, storing pairs of HD and Node*
        queue<pair<int, Node*>> q;
        q.push({0, root}); // Push the root node with HD = 0

        while (!q.empty()) {
            auto temp = q.front(); // Get the front element from the queue
            q.pop(); // Remove the front element from the queue

            int HD = temp.first; // Horizontal Distance of the current node
            Node *node = temp.second; // Current node

            // If no node has been added at this HD, add the current node
            if (mp.find(HD) == mp.end())
                mp[HD] = node;

            // If the left child exists, push it to the queue with HD - 1
            if (node->left)
                q.push({HD - 1, node->left});
            // If the right child exists, push it to the queue with HD + 1
            if (node->right)
                q.push({HD + 1, node->right});
        }

        // Traverse the map to construct the answer
        for (auto ele : mp) {
            ans.push_back(ele.second->data);
        }

        return ans; // Return the top view nodes
    }
};

// Function to create a sample tree and call the topView function
int main() {
    // Create nodes of the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.topView(root);

    // Print the top view of the binary tree
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

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
