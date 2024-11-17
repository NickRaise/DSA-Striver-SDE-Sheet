//  Reverse Linked List in groups of Size K

//  Problem Statement: Given the head of a singly linked list of `n` nodes and an integer `k`, where k is less than or equal to `n`. 
//  Your task is to reverse the order of each group of `k` consecutive nodes, if `n` is not divisible by `k`, then the last group of remaining nodes should remain unchanged.

//  Input Format:
//  LL: 1  2  3  4  5  6  7  8  9  10
//  K = 3

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Helper function to get the k-th node from the given node
Node* getKthNode(Node* head, int k) {
    Node *temp = head;
    while(--k) { // Iterate k-1 times to reach the k-th node
        if(!temp) return nullptr; // If temp is null, return null indicating fewer than k nodes remain
        temp = temp->next; // Move to the next node
    }
    return temp; // Return the k-th node
}

// Helper function to reverse a linked list
Node* reverseList(Node *head) {
    if(!head || !head->next) return head; // Base case: if list is empty or has one node, return head

    Node *newHead = reverseList(head->next); // Recursively reverse the rest of the list

    head->next->next = head; // Reverse the current node's next pointer
    head->next = nullptr; // Set current node's next pointer to null

    return newHead; // Return the new head of the reversed list
}

// Function to reverse nodes of a linked list in groups of k
Node* kReverse(Node* head, int k) {
    if(!head || !head->next) return head; // If the list is empty or has one node, return head

    Node *start, *end, *nextNode = head, *prevEnd = nullptr; // Initialize pointers

    while(nextNode) { // While there are nodes to process
        start = nextNode; // Set start to the current node
        end = getKthNode(start, k); // Get the k-th node from start

        if(!end) { // If fewer than k nodes remain
            if(prevEnd) // If this is not the first group
                prevEnd->next = start; // Connect the previous end to the remaining nodes
            else
                head = start; // Update the head if this is the first group
            break; // Exit the loop
        }

        nextNode = end->next; // Save the next node to process
        end->next = nullptr; // Temporarily break the link to reverse the current k nodes

        if(prevEnd) // If this is not the first group
            prevEnd->next = reverseList(start); // Reverse the current k nodes and connect to previous end
        else
            head = reverseList(start); // Reverse the first k nodes and update the head
            
        prevEnd = start; // Update prevEnd to the new end of the reversed group
    }

    return head; // Return the new head of the modified list
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    int k = 3; // Group size for reversal

    // Calling kReverse to reverse nodes in groups of k
    head = kReverse(head, k);

    // Printing the modified linked list
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Cleaning up memory
    while (head) {
        Node* node = head;
        head = head->next;
        delete node;
    }

    return 0;
}
