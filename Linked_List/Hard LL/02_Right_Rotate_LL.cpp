//  Right Rotate Linked List by k steps

//  Sample Input 1 :
//  6
//  1 2 3 4 5 6
//  2
//  Sample Output 1 :
//  5 6 1 2 3 4


#include <iostream>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Function to rotate the linked list k times to the right
Node *rotate(Node *head, int k) {
    if (!head || !head->next) return head;  // If the list is empty or has one node, return the head

    int len = 0;
    Node *tail = head, *end = head;

    // Calculate the length of the list
    while (end) {
        end = end->next;
        len++;
    }

    k = k % len;  // If k is greater than the length of the list, take modulus
    if (k == 0) return head;  // If k is 0, the list remains unchanged

    end = head;

    // Move tail k nodes ahead
    while (k--) 
        tail = tail->next;

    // Move both pointers until tail reaches the last node
    while (tail->next) {
        tail = tail->next;
        end = end->next;
    }

    // Rotate the list
    Node *temp = head;
    head = end->next;
    end->next = nullptr;
    tail->next = temp;

    return head;
}

// Helper function to print the linked list
void printList(Node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to demonstrate the rotate function
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;  // Number of rotations

    cout << "Original list: ";
    printList(head);

    // Rotating the list
    head = rotate(head, k);

    cout << "List after " << k << " rotations: ";
    printList(head);

    // Cleaning up memory
    while (head) {
        Node *node = head;
        head = head->next;
        delete node;
    }

    return 0;
}
