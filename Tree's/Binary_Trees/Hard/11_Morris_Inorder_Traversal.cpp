// Morris Inorder Traversal of a Binary Tree

// Problem Statement: Given a Binary Tree, implement Morris Inorder Traversal and return the array containing its preorder sequence.

// Time -> O(N)   Space -> O(1)





#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int x) : value(x), left(nullptr), right(nullptr) {}
};

void Morris(Node* root) {
    if (root == nullptr)
        return;

    Node* current = root;

    while (current) {
        if (current->left) {
            // Find the inorder predecessor of current
            Node* prev = current->left;
            while (prev->right && prev->right != current)
                prev = prev->right;

            // Make current as right child of its inorder predecessor
            if (prev->right == nullptr) {
                prev->right = current;
                current = current->left;
            }
            // Revert the changes made in the 'if' part to restore the original tree
            else {
                prev->right = nullptr;
                cout << current->value << " ";
                current = current->right;
            }
        } else {
            // If there is no left child, print the current node and move to the right child
            cout << current->value << " ";
            current = current->right;
        }
    }
}

// Function to insert nodes in the binary tree for testing purposes
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
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

    cout << "Morris Inorder Traversal of the binary tree: ";
    Morris(root);

    return 0;
}
