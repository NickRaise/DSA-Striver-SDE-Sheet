//  Flattening a Linked List

//  Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:

//  ‘Next’ points to the next node in the list
//  ‘Child’ pointer to a linked list where the current node is the head
//  Each of these child linked lists is in sorted order and connected by a 'child' pointer. 
//  Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.

#include <iostream>
using namespace std;

// Definition for a node in a linked list.
class Node {
public:
    int data;
    Node *next;
    Node *bottom;
    Node() : data(0), next(nullptr), bottom(nullptr) {}
    Node(int x) : data(x), next(nullptr), bottom(nullptr) {}
    Node(int x, Node *next, Node *bottom) : data(x), next(next), bottom(bottom) {}
};

// Function to merge two sorted linked lists.
Node* sortTwoLists(Node* one, Node* two) {
    // Create a dummy node to act as the start of the merged list.
    Node *dummyNode = new Node(-1);
    Node *prev = dummyNode;

    // Traverse both lists and merge them in sorted order.
    while(one && two) {
        if(one->data < two->data) {
            prev->bottom = one;
            prev = one;
            one = one->bottom;
        }
        else {
            prev->bottom = two;
            prev = two;
            two = two->bottom;
        }
        // Ensure the 'next' pointers are null to maintain 'bottom' linkage.
        prev->next = nullptr;
    }

    // Attach the remaining nodes from either list.
    prev->bottom = (one) ? one : two;

    // Ensure the 'bottom' chain's 'next' pointer is null.
    prev->bottom->next = nullptr;

    // Return the head of the merged list, skipping the dummy node.
    return dummyNode->bottom;
}

// Function to flatten a linked list where each node may have a bottom list.
Node* flatten(Node* head) {
    // Base cases: if the list is empty or has only one node, return the head.
    if(!head || !head->next) return head;

    // Recursively flatten the rest of the list.
    Node *mergedHead = flatten(head->next);

    // Merge the current list (head) with the flattened list.
    return sortTwoLists(head, mergedHead);
}

// Helper function to print the flattened linked list.
void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

// Main function to demonstrate the functionality.
int main() {
    // Creating a sample linked list for demonstration.
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    // Flattening the list.
    head = flatten(head);

    // Printing the flattened list.
    cout << "Flattened list: ";
    printList(head);

    // Cleaning up memory (for demonstration purposes).
    while(head) {
        Node* temp = head;
        head = head->bottom;
        delete temp;
    }

    return 0;
}
