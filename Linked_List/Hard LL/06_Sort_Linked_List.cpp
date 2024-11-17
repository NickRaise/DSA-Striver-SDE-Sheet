//  Sort Linked List


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


// Function to find the middle of a linked list
Node *findMiddle(Node *head) {
    // Use two pointers, slow and fast
    Node *slow = head, *fast = head;

    // Move fast pointer two steps and slow pointer one step
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow pointer will be at the middle of the list
    return slow;
}

// Function to merge two sorted linked lists
Node *merge2Sorted(Node *first, Node *second) {
    // Create a dummy node to start the merged list
    Node *dummyNode = new Node(-1), *prev = dummyNode;

    // Compare nodes from both lists and attach the smaller node to the merged list
    while (first && second) {
        if (first->data < second->data) {
            prev->next = first;
            prev = first;
            first = first->next;
        } else {
            prev->next = second;
            prev = second;
            second = second->next;
        }
    }

    // Attach remaining nodes from either list
    prev->next = first ? first : second;

    // Return the merged list, skipping the dummy node
    return dummyNode->next;
}

// Function to perform merge sort on a linked list
Node *mergeSort(Node *left) {
    // Base case: if the list is empty or has one element, it's already sorted
    if (!left || !left->next) return left;

    // Find the middle of the list
    Node *mid = findMiddle(left), *right;
    Node *midNext = mid->next;
    mid->next = nullptr;

    // Recursively sort the left and right halves
    left = mergeSort(left);
    right = mergeSort(midNext);

    // Merge the two sorted halves
    left = merge2Sorted(left, right);

    return left;
}

// Function to sort a linked list
Node *sortLL(Node *head) {
    head = mergeSort(head);
    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the sorting of a linked list
int main() {
    // Create an unsorted linked list for demonstration
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    // Print the original list
    cout << "Original List: ";
    printList(head);

    // Sort the list
    head = sortLL(head);

    // Print the sorted list
    cout << "Sorted List: ";
    printList(head);

    return 0;
}
