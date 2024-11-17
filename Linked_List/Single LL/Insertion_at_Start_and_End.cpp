// Insert element at beginening and end of single linked list

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to insert a node at the beginning of the linked list.
Node *insertAtBeginning(Node *head, int x) {
    Node *node = new Node(x);
    node->next = head;
    return node;
}

// Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x) {
    Node *node = new Node(x);
    if(head == nullptr) 
        return node;
    Node *temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

// Function to print the linked list.
void printList(Node *head) {
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating an empty linked list.
    Node *head = nullptr;

    // Inserting elements into the linked list.
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    // Printing the linked list.
    cout << "Linked list: ";
    printList(head);

    return 0;
}
