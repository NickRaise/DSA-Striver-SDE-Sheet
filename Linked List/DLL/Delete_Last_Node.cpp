#include <iostream>
using namespace std;

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

struct Node {
    int data;
    Node *prev;
    Node *next;
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
};

Node * deleteLastNode(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
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
    head->next = new Node(2, head, nullptr);
    head->next->next = new Node(3, head->next, nullptr);
    head->next->next->next = new Node(4, head->next->next, nullptr);
    head->next->next->next->next = new Node(5, head->next->next->next, nullptr);

    cout << "Original list: ";
    printList(head);

    head = deleteLastNode(head);

    cout << "List after deleting last node: ";
    printList(head);

    return 0;
}
