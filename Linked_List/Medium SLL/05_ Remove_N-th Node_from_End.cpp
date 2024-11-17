// Remove N-th node from the end of a Linked List

// Input Format: 1->2->3->4->5, N=3

// Result: 1->2->4->5

// Explanation: The 3rd node from the end is 3, therefore, we remove 3 from the linked list.


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

Node* removeKthNode(Node* head, int K) {
    Node* slow = head;
    Node* fast = head;
    while (K--)
        fast = fast->next;

    if (fast == nullptr) {
        Node* node = slow->next;
        delete head;
        return node;
    }

    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* node = slow->next;
    slow->next = node->next;
    delete node;
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
    // Creating sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int K = 2; // Remove the 2nd node from the end

    cout << "Original list: ";
    printList(head);

    head = removeKthNode(head, K);

    cout << "List after removing " << K << "th node from the end: ";
    printList(head);

    return 0;
}
