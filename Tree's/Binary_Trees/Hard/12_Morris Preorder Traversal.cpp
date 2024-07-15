// Morris Preorder Traversal of a Binary Tree

// Problem Statement: Given a Binary Tree, implement Morris Preorder Traversal and return the array containing its preorder sequence.



#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int x) : value(x), left(nullptr), right(nullptr) {}
};

// Function to perform Morris Preorder Traversal on a binary tree
void Morris(Node* root) {
    // If the tree is empty, there is nothing to traverse
    if (root == nullptr)
        return;

    Node* current = root; // Initialize the current node to the root of the tree

    // Iterate through the tree until all nodes are visited
    while (current) {
        // If the current node has a left child
        if (current->left) {
            // Find the inorder predecessor of the current node
            Node* prev = current->left;
            while (prev->right && prev->right != current)
                prev = prev->right;

            // If the right child of the inorder predecessor is NULL
            if (prev->right == nullptr) {
                // Make the current node the right child of the inorder predecessor
                prev->right = current;
                // Output the value of the current node (preorder traversal)
                cout << current->value << " ";
                // Move to the left child of the current node
                current = current->left;
            } else {
                // Revert the changes made (fix the right child of the inorder predecessor)
                prev->right = nullptr;
                // Move to the right child of the current node
                current = current->right;
            }
        } else {
            // If the current node does not have a left child
            // Output the value of the current node (preorder traversal)
            cout << current->value << " ";
            // Move to the right child of the current node
            current = current->right;
        }
    }
}

// Function to insert nodes in the binary tree for testing purposes
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value); // If the tree is empty, create a new node as the root
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value); // Insert in the left subtree if value is less than root's value
    } else {
        root->right = insertNode(root->right, value); // Insert in the right subtree if value is greater than root's value
    }
    return root; // Return the root node
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Output the preorder traversal of the binary tree using Morris Traversal
    cout << "Morris Preorder Traversal of the binary tree: ";
    Morris(root);

    return 0;
}
