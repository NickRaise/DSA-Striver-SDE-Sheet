#include <iostream>
using namespace std;

/********/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev=NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->next= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};
*/

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev=NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->next= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

Node * deleteHead(Node *head) {
    if (head->next == NULL) {
        delete head;
        return nullptr;
    }
    head->next->prev = NULL;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main() {
    // Sample usage of deleteHead function
    Node* head = new Node(1);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);

    cout << "Original list: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    head = deleteHead(head);

    cout << "List after deleting head: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
