// Floor in a Binary Search Tree

// Problem Statement: Given a Binary Search Tree and a key, return the floor of the given key in the Binary Search Tree.
//     ->Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key.
//     ->If the floor node does not exist, return nullptr.

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left, *right;
    // Default constructor, initializes the node value to 0 and left, right pointers to nullptr.
    Node() : data(0), left(nullptr), right(nullptr) {}
    // Constructor to initialize node with a specific value, and left, right pointers to nullptr.
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    // Constructor to initialize node with a specific value, and given left, right pointers.
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

// Function to find the floor value in BST for the given input.
int floor(Node* root, int x) {
    // If the tree is empty, return -1.
    if (!root) return -1;

    int ans = -1;
    
    // Traverse the tree starting from the root.
    while (root) {
        // If the current node's value is equal to the input, return the current node's value.
        if (root->data == x) return root->data;
        
        // If the current node's value is greater than the input, move to the left subtree.
        if (root->data > x) root = root->left;
        else {
            // Otherwise, update the answer and move to the right subtree.
            ans = root->data;
            root = root->right;
        }
    }
    
    // Return the floor value found.
    return ans;
}

// Helper function to insert a new value in the BST
Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}

int main() {
    // Create the root of the tree
    Node* root = nullptr;
    // Insert values into the BST
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 3);

    int input = 5;
    int floorValue = floor(root, input);

    if (floorValue == -1) {
        cout << "No floor found for " << input << " in the BST" << endl;
    } else {
        cout << "The floor value for " << input << " in the BST is: " << floorValue << endl;
    }

    return 0;
}
