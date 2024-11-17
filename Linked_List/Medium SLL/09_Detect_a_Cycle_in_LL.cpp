// Detect a Cycle in a Linked List



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

// Function to detect a cycle in a linked list
bool detectCycle(Node *head) {
    // Initialize two pointers, slow and fast, both starting at the head of the list
    Node *slow = head, *fast = head;

    // Traverse the list with two pointers
    // - 'slow' moves one step at a time
    // - 'fast' moves two steps at a time
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;   // Move fast pointer by two nodes
        slow = slow->next;         // Move slow pointer by one node

        // If slow and fast pointers meet, there is a cycle
        if (slow == fast) return true;
    }

    // If we reach the end of the list, there is no cycle
    return false;
}

// Helper function to create a linked list with a cycle for testing
Node* createCycleList() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; // Creating a cycle

    return head;
}

// Helper function to create a linked list without a cycle for testing
Node* createNoCycleList() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    return head;
}

// Main function to test the detectCycle function
int main() {
    // Creating a linked list with a cycle
    Node* cycleList = createCycleList();
    // Creating a linked list without a cycle
    Node* noCycleList = createNoCycleList();

    // Testing detectCycle function
    cout << "Cycle List: " << (detectCycle(cycleList) ? "Cycle detected" : "No cycle detected") << endl;
    cout << "No Cycle List: " << (detectCycle(noCycleList) ? "Cycle detected" : "No cycle detected") << endl;

    return 0;
}
