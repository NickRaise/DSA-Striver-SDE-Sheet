#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data, Node* next, Node* prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node* reverseDLL(Node* head)
{
    if (!head) return nullptr;  // Handle the case when the list is empty
    while (head->next != nullptr) {
        swap(head->next, head->prev);
        head = head->prev;
    }
    swap(head->next, head->prev);
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);
    head->next->next->next = new Node(4, nullptr, head->next->next);
    head->next->next->next->next = new Node(5, nullptr, head->next->next->next);

    cout << "Original list: ";
    printList(head);

    head = reverseDLL(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
