#include <iostream>
using namespace std;

/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
    };

************************************************************/

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        this->data = val;
        next = NULL;
        prev = NULL;
    }
};

void deleteNode(Node* node) {
    // Write your code here
    if (node->next == nullptr) {
        node->prev->next = nullptr;
        delete node;
        return;
    }
    Node *temp = node;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

int main() {
    // Sample usage of the deleteNode function
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    
    cout << "Original List: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Delete the node with value 2
    cout << "After deleting node with value 2: ";
    deleteNode(head->next);
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
