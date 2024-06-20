#include <iostream>
using namespace std;

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

struct Node {
    int value;
    Node *prev;
    Node *next;
    Node() : value(0), prev(nullptr), next(nullptr) {}
    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
};

Node* insertAtTail(Node* head, int k) {
    Node* node = new Node(k);
    if (head == nullptr) {
        return node;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    node->next = nullptr;
    node->prev = temp;
    temp->next = node;
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2, head, nullptr);
    head->next->next = new Node(3, head->next, nullptr);
    head->next->next->next = new Node(4, head->next->next, nullptr);
    head->next->next->next->next = new Node(5, head->next->next->next, nullptr);

    cout << "Original list: ";
    printList(head);

    // Inserting a new node with value 6 at the tail
    head = insertAtTail(head, 6);

    cout << "List after inserting 6 at the tail: ";
    printList(head);

    return 0;
}
