// Serialize and Deserialize Binary Tree

// Design an algorithm to serialize and deserialize a binary tree. 
// There is no restriction on how your serialization/deserialization algorithm should work. 
// You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Sample Input :
// 1 2 3 -1 4 5 -1 -1 -1 -1 -1
// Sample Output :
// 1 2 3 -1 4 5 -1 -1 -1 -1 -1
// Explanation For Sample Input :
// The given tree looks as follows:
//                 1
//                / \
//               2   3
//               \   / 
//                4 5

// The level order traversal of the given tree will be “1 2 3 -1 4 5 -1 -1 -1 -1 -1" where -1 denotes the null nodes.




#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string data = "";

        // Start with the root node value
        data = data + to_string(root->val);

        // Use a queue for level-order traversal
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            for(int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();

                // Process left child
                if(node->left) {
                    data = data + " " + to_string(node->left->val);
                    q.push(node->left);
                } else {
                    data = data + " N";
                }

                // Process right child
                if(node->right) {
                    data = data + " " + to_string(node->right->val);
                    q.push(node->right);
                } else {
                    data = data + " N";
                }
            }
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        stringstream str(data);
        string token;

        // Get the root value
        getline(str, token, ' ');
        TreeNode *head = new TreeNode(stoi(token));

        // Use a queue for level-order construction
        queue<TreeNode *> q;
        q.push(head);

        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            // Process left child
            getline(str, token, ' ');
            if(token != "N") {
                TreeNode *leftNode = new TreeNode(stoi(token));
                node->left = leftNode;
                q.push(leftNode);
            } else {
                node->left = nullptr;
            }

            // Process right child
            getline(str, token, ' ');
            if(token != "N") {
                TreeNode *rightNode = new TreeNode(stoi(token));
                node->right = rightNode;
                q.push(rightNode);
            } else {
                node->right = nullptr;
            }
        }

        return head;
    }
};

// Function to print the tree in level order
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "N ";
        }
    }
    cout << endl;
}

int main() {
    Codec ser, deser;

    // Construct the initial tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serializedTree = ser.serialize(root);
    cout << "Serialized tree: " << serializedTree << endl;

    // Deserialize the string back to a tree
    TreeNode* deserializedTree = deser.deserialize(serializedTree);

    // Print the deserialized tree in level order to verify
    cout << "Deserialized tree (level order): ";
    printLevelOrder(deserializedTree);

    // Clean up memory
    // Proper memory management should be implemented to avoid memory leaks

    return 0;
}
