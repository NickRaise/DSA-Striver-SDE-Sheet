// Tree Traversals

// You have been given a Binary Tree of 'N' nodes, where the nodes have integer values.
// Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.





#include <iostream>
#include <vector>

using namespace std;

// Definition of the TreeNode structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform the tree traversals
void solve(TreeNode *root, vector<int> &In, vector<int> &pre, vector<int> &post) {
    if(root == nullptr) return;

    // Pre-order traversal (Root, Left, Right)
    pre.push_back(root->data);
    solve(root->left, In, pre, post);
    
    // In-order traversal (Left, Root, Right)
    In.push_back(root->data);
    solve(root->right, In, pre, post);

    // Post-order traversal (Left, Right, Root)
    post.push_back(root->data);
}

// Function to get all tree traversals
vector<vector<int>> getTreeTraversal(TreeNode *root) {
    vector<vector<int>> ans;

    vector<int> In, pre, post;

    solve(root, In, pre, post);

    ans.push_back(In);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}

// Main function to demonstrate the tree traversal
int main() {
    // Constructing a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Get tree traversals
    vector<vector<int>> traversals = getTreeTraversal(root);

    // Print In-order traversal
    cout << "In-order Traversal: ";
    for(int val : traversals[0]) {
        cout << val << " ";
    }
    cout << endl;

    // Print Pre-order traversal
    cout << "Pre-order Traversal: ";
    for(int val : traversals[1]) {
        cout << val << " ";
    }
    cout << endl;

    // Print Post-order traversal
    cout << "Post-order Traversal: ";
    for(int val : traversals[2]) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
