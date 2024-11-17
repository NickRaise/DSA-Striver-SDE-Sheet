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

Node* insertAtFront(Node *head, int k) {
    Node *temp = new Node(k);
    temp->prev = nullptr;
    temp->next = head;
    head = temp;
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
    // Creating an empty doubly linked list
    Node* head = nullptr;

    // Inserting elements at the front of the list
    head = insertAtFront(head, 5);
    head = insertAtFront(head, 4);
    head = insertAtFront(head, 3);
    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);

    // Printing the list
    cout << "Doubly linked list after insertion at front: ";
    printList(head);

    return 0;
}
