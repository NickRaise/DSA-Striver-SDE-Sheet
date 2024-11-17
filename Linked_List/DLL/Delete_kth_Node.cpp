#include <iostream>
using namespace std;

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *      int val;
 *      Node *next;
 *      Node *prev;
 *      Node() : val(0), next(nullptr), prev(nullptr) {};
 *      Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *      Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
 * };
 */

class Node {
public:
    int val;
    Node *next;
    Node *prev;
    Node() : val(0), next(nullptr), prev(nullptr) {};
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
};

Node* deleteNode(Node *head, int k) {
    if (head == nullptr) return nullptr;

    Node *temp = head;
    int pos = 1;
    while (temp->next != nullptr && pos < k) {
        temp = temp->next;
        pos++;
    }

    // Required node is head
    if (temp->prev == nullptr) {
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
        return head;
    }

    // Required node is last node
    if (temp->next == nullptr) {
        temp->prev->next = nullptr;
        delete temp;
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
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

    int k;
    cout << "Enter the position of the node to delete: ";
    cin >> k;

    head = deleteNode(head, k);

    cout << "List after deleting node at position " << k << ": ";
    printList(head);

    return 0;
}
