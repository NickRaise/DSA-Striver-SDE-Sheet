// Reverse a Linked List

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

Node* reverseLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* curr = head;
    Node* prev = nullptr;
    Node* next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    head = reverseLinkedList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
