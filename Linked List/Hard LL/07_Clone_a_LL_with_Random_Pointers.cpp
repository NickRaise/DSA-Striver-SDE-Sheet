//  Clone a Linked List with random pointers
//  Problem Statement: Given a linked list where every node in the linked list contains two pointers:
//     ‘next’ which points to the next node in the list.
//     ‘random’ which points to a random node in the list or ‘null’.
//  Create a ‘deep copy’ of the given linked list and return it.

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
     int data;
     Node *next;
     Node *random;
     Node() : data(0), next(nullptr), random(nullptr){};
     Node(int x) : data(x), next(nullptr), random(nullptr) {}
     Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
};
 

// Function to clone a linked list with next and random pointers
Node *cloneLL(Node *head) {
    // Step 1: Create a new node for each existing node and insert it right after the original node
    Node *temp = head, *node;

    while (temp) {
        node = new Node(temp->data); // Create a new node with the same data
        node->next = temp->next;     // Link the new node to the next node
        temp->next = node;           // Link the original node to the new node
        temp = node->next;           // Move to the next original node
    }

    // Step 2: Update the random pointers for the new nodes
    temp = head;
    while (temp) {
        node = temp->next; // Get the new node
        if (temp->random) {
            node->random = temp->random->next; // Set the random pointer of the new node
        }
        temp = node->next; // Move to the next original node
    }

    // Step 3: Separate the original list and the cloned list
    temp = head;
    Node *dummyNode = new Node(-1), *prev = dummyNode;

    while (temp) {
        prev->next = temp->next; // Link the previous node to the new node
        prev = prev->next;       // Move the previous node pointer
        temp->next = prev->next; // Restore the original list
        prev->next = nullptr;    // Unlink the new node from the original list
        temp = temp->next;       // Move to the next original node
    }

    return dummyNode->next; // Return the head of the cloned list
}

// Helper function to print the linked list for testing
void printList(Node* head) {
    while (head) {
        cout << "Data: " << head->data;
        if (head->random) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Create a linked list for testing
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next; // 1's random points to 3
    head->next->random = head;       // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2

    cout << "Original List:" << endl;
    printList(head);

    Node* clonedHead = cloneLL(head);

    cout << "Cloned List:" << endl;
    printList(clonedHead);

    return 0;
}
