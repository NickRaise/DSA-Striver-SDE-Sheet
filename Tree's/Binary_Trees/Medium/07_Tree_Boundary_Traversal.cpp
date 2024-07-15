// Tree Boundary Traversal

// The boundary nodes of a binary tree include the nodes from the left and right boundaries and the leaf nodes, 
// each node considered once.


// Input:
//         1 
//       /   \
//      2     3  
//     / \   / \ 
//    4   5 6   7
//       / \
//      8   9
   
// Output: 1 2 4 8 9 6 7 3


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
    vector<int> boundary(Node *root) {
        vector<int> ans; // Vector to store the boundary nodes
        if (!root) return ans; // If the tree is empty, return an empty vector

        // Add the root node if it is not a leaf node
        if (!isLeaf(root))
            ans.push_back(root->data);

        // Add left boundary nodes
        addLeftNodes(root->left, ans);
        // Add leaf nodes
        addChildNodes(root, ans);
        // Add right boundary nodes
        addRightNodes(root->right, ans);

        return ans; // Return the boundary nodes
    }

private:
    // Function to check if a node is a leaf node
    bool isLeaf(Node *node) {
        return !node->left && !node->right;
    }

    // Function to add left boundary nodes
    void addLeftNodes(Node *root, vector<int> &ans) {
        if (!root) return;

        // Add the current node if it is not a leaf node
        if (!isLeaf(root))
            ans.push_back(root->data);

        // Recursively add the left boundary nodes
        if (root->left)
            addLeftNodes(root->left, ans);
        else    
            addLeftNodes(root->right, ans);
    }

    // Function to add leaf nodes
    void addChildNodes(Node *root, vector<int> &ans) {
        if (!root) return;

        // Recursively add the leaf nodes from left and right subtrees
        addChildNodes(root->left, ans);
        addChildNodes(root->right, ans);

        // Add the current node if it is a leaf node
        if (isLeaf(root)) 
            ans.push_back(root->data);
    }

    // Function to add right boundary nodes
    void addRightNodes(Node *root, vector<int> &ans) {
        if (!root) return;

        // Recursively add the right boundary nodes
        if (root->right)
            addRightNodes(root->right, ans);
        else
            addRightNodes(root->left, ans);

        // Add the current node if it is not a leaf node
        if (!isLeaf(root))
            ans.push_back(root->data);
    }
};

// Function to create a sample tree and call the boundary function
int main() {
    // Create nodes of the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);

    Solution sol;
    vector<int> result = sol.boundary(root);

    // Print the boundary traversal
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}