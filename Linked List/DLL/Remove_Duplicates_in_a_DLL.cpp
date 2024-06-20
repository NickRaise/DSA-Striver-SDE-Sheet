//  Remove duplicates from a sorted Doubly Linked List


/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

Node *removeDuplicates(Node *head) {
    // If the list is empty or has only one node, return the head as there are no duplicates to remove
    if (!head || !head->next) return head;

    // Initialize a temporary pointer starting from the second node
    Node *temp = head->next, *node;

    // Traverse through the list
    while (temp) {
        // Check if the current node's data is equal to the previous node's data
        if (temp->data == temp->prev->data) {
            // Store the duplicate node
            node = temp;
            // Adjust the pointers to bypass the duplicate node
            temp->prev->next = temp->next;
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            // Move to the next node
            temp = temp->next;
            // Delete the duplicate node
            delete node;
        } else {
            // Move to the next node if no duplicate is found
            temp = temp->next;
        }
    }

    // Return the modified list head
    return head;
}

int main() {
    // Create a sample doubly linked list: 1 <-> 2 <-> 2 <-> 3 <-> 4 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    // Remove duplicates from the list
    head = removeDuplicates(head);

    // Print the modified list
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Clean up memory
    while (head) {
        Node* node = head;
        head = head->next;
        delete node;
    }

    return 0;
}
