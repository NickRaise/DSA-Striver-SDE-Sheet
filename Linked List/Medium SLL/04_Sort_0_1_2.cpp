//  Sort linked list of 0s 1s 2s

// Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. 
// You need to sort the linked list in non-decreasing order and the return the head of the sorted list.

// Example:
// Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
// The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.




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

Node* sortList(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* zero = new Node(-1);
    Node* one = new Node(-1);
    Node* two = new Node(-1);
    Node* zeroEnd = zero;
    Node* oneEnd = one;
    Node* twoEnd = two;
    Node* curr = head;

    while (curr != nullptr) {
        int val = curr->data;
        if (val == 0) {
            zeroEnd->next = curr;
            zeroEnd = curr;
        } else if (val == 1) {
            oneEnd->next = curr;
            oneEnd = curr;
        } else {
            twoEnd->next = curr;
            twoEnd = curr;
        }
        curr = curr->next;
    }

    zeroEnd->next = (one->next) ? (one->next) : (two->next);
    oneEnd->next = two->next;
    twoEnd->next = nullptr;

    Node* newHead = zero->next;

    delete zero;
    delete one;
    delete two;

    return newHead;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating sample linked list: 2 -> 1 -> 0 -> 1 -> 2 -> 0
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    cout << "Original list: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
