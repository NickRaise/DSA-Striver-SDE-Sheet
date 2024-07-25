//  Merge Two BSTs


#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    // Default constructor, initializes the node value to 0 and left, right pointers to nullptr.
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    // Constructor to initialize node with a specific value, and left, right pointers to nullptr.
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    // Constructor to initialize node with a specific value, and given left, right pointers.
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution {
public:
    // Public function to merge two BSTs and return the sorted list as a vector
    vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
        // Convert both BSTs to sorted linked lists
        TreeNode *head1 = nullptr, *head2 = nullptr;
        convertBSTtoSortedLL(root1, head1);
        convertBSTtoSortedLL(root2, head2);

        // Merge the two sorted linked lists into one
        TreeNode *mergedHead = merge2SortedLL(head1, head2);

        // Count the number of nodes in the merged linked list
        int n = countNodes(mergedHead);

        // Convert the sorted linked list back to a balanced BST
        TreeNode *balancedRoot = convertLLtoBST(mergedHead, n);

        // Perform inorder traversal to get sorted values from the balanced BST
        vector<int> result;
        inorderTraversal(balancedRoot, result);
        return result;
    }

private:
    // Helper function to convert a BST to a sorted linked list
    void convertBSTtoSortedLL(TreeNode *root, TreeNode* &head) {
        if (!root) return; // If the node is null, return

        // Recursively process the right subtree first
        convertBSTtoSortedLL(root->right, head);
        
        // Link the current node to the head of the list
        root->right = head; 
        head = root; // Update head to point to the current node

        // Recursively process the left subtree
        convertBSTtoSortedLL(root->left, head);
    }

    // Helper function to merge two sorted linked lists
    TreeNode *merge2SortedLL(TreeNode *root1, TreeNode *root2) {
        // Create a dummy node to simplify merging
        TreeNode *dummyNode = new TreeNode(-1);
        TreeNode *temp = dummyNode;

        // Merge the two lists while both are not empty
        while (root1 && root2) {
            if (root1->data < root2->data) {
                temp->right = root1; // Attach the smaller node
                root1 = root1->right; // Move to the next node in list 1
            } else {
                temp->right = root2; // Attach the smaller node
                root2 = root2->right; // Move to the next node in list 2
            }
            temp = temp->right; // Move to the end of the merged list
        }

        // Attach the remaining nodes from list 1, if any
        while (root1) {
            temp->right = root1;
            root1 = root1->right;
            temp = temp->right;
        }

        // Attach the remaining nodes from list 2, if any
        while (root2) {
            temp->right = root2;
            root2 = root2->right;
            temp = temp->right;
        }

        // Get the merged list, skipping the dummy node
        TreeNode *mergedList = dummyNode->right;
        delete dummyNode; // Clean up dummy node
        return mergedList;
    }

    // Helper function to convert a sorted linked list to a balanced BST
    TreeNode *convertLLtoBST(TreeNode *&head, int n) {
        if (n == 0 || head == nullptr) return nullptr; // Base case

        // Recursively construct the left subtree
        TreeNode *left = convertLLtoBST(head, n / 2);

        // Create the root node for the current subtree
        TreeNode *root = head;
        root->left = left; // Attach the left subtree

        head = head->right; // Move the head to the next node

        // Recursively construct the right subtree
        root->right = convertLLtoBST(head, n - n / 2 - 1);
        return root;
    }

    // Helper function to count the number of nodes in the linked list
    int countNodes(TreeNode *root) {
        int count = 0;
        while (root) {
            count++; // Increment count for each node
            root = root->right; // Move to the next node
        }
        return count;
    }

    // Function to perform inorder traversal of BST and collect values in a vector
    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (!root) return; // If the node is null, return

        inorderTraversal(root->left, result); // Traverse the left subtree
        result.push_back(root->data); // Add the current node's value to the result vector
        inorderTraversal(root->right, result); // Traverse the right subtree
    }
};



// Function to print the values in a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " "; // Print each value
    }
    cout << endl;
}

// Main function to demonstrate usage
int main() {
    // Example usage:
    // Create two example BSTs
    TreeNode* root1 = new TreeNode(1, nullptr, new TreeNode(3));
    TreeNode* root2 = new TreeNode(2, nullptr, new TreeNode(4));

    // Create a Solution object
    Solution sol;
    // Merge the BSTs and get the sorted result as a vector
    vector<int> mergedResult = sol.mergeBST(root1, root2);

    // Print the merged result
    cout << "Merged and balanced BST as sorted vector: ";
    printVector(mergedResult);

    return 0;
}
