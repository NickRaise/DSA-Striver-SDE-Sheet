// Root to Leaf Paths

// Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

// Input:
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output: 
// 10 20 40 
// 10 20 60 
// 10 30 


#include <iostream>
#include <vector>

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
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<int> currentPath;
        pathFinder(root, ans, currentPath);
        return ans;
    }

private:
    void pathFinder(Node* root, vector<vector<int>> &ans, vector<int> &currentPath) {
        if (!root) return;

        // Add the current node's value to the path
        currentPath.push_back(root->data);

        // If it's a leaf node, add the current path to the result
        if (!root->left && !root->right) {
            ans.push_back(currentPath);
        }

        // Traverse the left subtree
        pathFinder(root->left, ans, currentPath);

        // Traverse the right subtree
        pathFinder(root->right, ans, currentPath);

        // Backtrack: remove the current node's value from the path
        currentPath.pop_back();
    }
};

// Function to create a sample tree and call the Paths function
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
    vector<vector<int>> paths = sol.Paths(root);

    // Print all root-to-leaf paths
    cout << "Root-to-leaf paths:" << endl;
    for (const auto& path : paths) {
        for (int val : path) {
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
