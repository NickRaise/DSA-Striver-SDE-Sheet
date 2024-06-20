// Find middle element in a Linked List

// Input: LL: 1  2  3  4  5 
// Output: 3
// Explanation: Node with value 3 is the middle node of this linked list.

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

// Function to find the middle of a linked list
Node* findMiddle(Node* head) {
    // Initialize two pointers, slow and fast, both starting at the head of the list
    Node* slow = head;
    Node* fast = head;

    // Traverse the list with two pointers
    // - 'slow' moves one step at a time
    // - 'fast' moves two steps at a time
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // Move slow pointer by one node
        fast = fast->next->next;   // Move fast pointer by two nodes
    }

    // When 'fast' reaches the end of the list, 'slow' will be at the middle node
    return slow;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the findMiddle function
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    // Finding the middle node
    Node* middle = findMiddle(head);

    // Printing the data of the middle node
    if (middle != nullptr) {
        cout << "Middle node data: " << middle->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
