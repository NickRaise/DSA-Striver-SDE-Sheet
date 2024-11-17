//  Delete Middle Node in LL

// Sample Input 1 :
// 5
// 1 2 3 4 5
// Sample Output 1 :
// 1 2 4 5 

// Input:
// LinkedList: 2->4->6->7->5->1
// Output: 
// 2 4 6 5 1




#include <iostream>
using namespace std;

// Definition of the Node class
class Node {
public:
    int data;
    Node *next;

    // Default constructor
    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    // Constructor to initialize a Node with data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // Constructor to initialize a Node with data and next pointer
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Function to delete the middle node of the linked list
Node* deleteMiddle(Node* head) {
    // If the list is empty or has only one node, return nullptr
    if (!head || !head->next) return nullptr;

    Node *slow = head, *fast = head, *prev = nullptr;

    // Use two pointers to find the middle of the list
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node
    prev->next = slow->next;
    delete slow;
    return head;
}

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node(data);
    return newNode;
}

// Helper function to print the list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the deleteMiddle function
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Delete the middle node
    head = deleteMiddle(head);

    // Print the list after deleting the middle node
    cout << "List after deleting the middle node: ";
    printList(head);

    return 0;
}
