// Postorder Traversal (Iteration method)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
    Binary Tree Node structure:
*/
class TreeNode {
public:
    int data;
    TreeNode *left, *right;

    // Constructors
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;

    if (!root) return ans; // If the root is null, return an empty vector

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();

        // Check if the current node is a leaf node or has been visited
        if ((!node->left && !node->right) ||
            (ans.size() > 0 && ans.back() == node->data)) {
            ans.push_back(node->data);
            st.pop();
        } else {
            // Push right child first, then left child (to be processed in reverse order)
            if (node->right) {
                st.push(node->right);
                node->right = nullptr; // Mark as visited
            }
            if (node->left) {
                st.push(node->left);
                node->left = nullptr; // Mark as visited
            }
        }
    }

    return ans;
}

// Function to create a sample tree and call the postorder traversal function
int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = postorderTraversal(root);

    // Print the postorder traversal result
    cout<<"Postorder -> ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
