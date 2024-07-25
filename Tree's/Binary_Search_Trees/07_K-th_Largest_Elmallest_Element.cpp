// Kth largest element in BST

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize node with a specific value, and left, right pointers to nullptr.
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Function to find the Kth largest element in the BST using Morris traversal.
int kthLargest(Node *root, int K) {
    int ans = -1; // Variable to store the Kth largest element.
    Node *current = root; // Start with the root node.
    int count = 0; // Counter to keep track of the number of nodes visited.

    while (current) {
        // If there is no right child, process the current node.
        if (!current->right) {
            count++;
            // If the current count matches K, store the current node's value as the answer.
            if (count == K) ans = current->data;
            // Move to the left child.
            current = current->left;
        } else {
            // Find the inorder predecessor of the current node.
            Node *succ = current->right;
            // Traverse to the leftmost node in the right subtree.
            while (succ->left && succ->left != current)
                succ = succ->left;
            
            // If the left child of the predecessor is null, establish a temporary link to the current node.
            if (succ->left == nullptr) {
                succ->left = current;
                current = current->right;
            } else {
                // If the left child of the predecessor points to the current node, remove the temporary link.
                succ->left = nullptr;
                count++;
                // If the current count matches K, store the current node's value as the answer.
                if (count == K) ans = current->data;
                // Move to the left child.
                current = current->left;
            }
        }
    }
    return ans; // Return the Kth largest element.
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

// Helper function to perform inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
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
    root = insertNode(root, 5);
    root = insertNode(root, 6);

    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    int K = 3;
    int kthLargestValue = kthLargest(root, K);

    cout << "The " << K << "rd largest value in the BST is: " << kthLargestValue << endl;

    return 0;
}

