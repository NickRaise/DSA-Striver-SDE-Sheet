// Delete all occurrences of a given key in a doubly linked list

// Sample Input 1:
// 7
// 10 4 10 3 5 20 10
// 10

// Sample Output 1:
// 4 3 5 20



#include <iostream>
using namespace std;

/**
 * Definition of doubly linked list:
 */
class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node() {
        this->data = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    Node(int data, Node *next, Node *prev) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

// Function to delete all occurrences of a given integer k from a doubly linked list
Node *deleteAllOccurrences(Node *head, int k) {
    // If the list is empty, return nullptr
    if (!head) return nullptr;

    Node *temp = head, *node;

    // Traverse the list
    while (temp) {
        // Check if current node's data is equal to k
        if (temp->data == k) {
            node = temp;

            // If the node to be deleted is the head node
            if (temp == head)
                head = head->next;

            // Update the previous node's next pointer if it exists
            if (temp->prev)
                temp->prev->next = temp->next;

            // Update the next node's prev pointer if it exists
            if (temp->next)
                temp->next->prev = temp->prev;

            // Move to the next node
            temp = temp->next;

            // Delete the current node
            delete node;
        } else {
            // Move to the next node if current node's data is not equal to k
            temp = temp->next;
        }
    }

    // Return the updated head of the list
    return head;
}

// Helper function to create a new node
Node* createNode(int data) {
    return new Node(data);
}

// Helper function to print the list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to demonstrate the deleteAllOccurrences function
int main() {
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 2 <-> 4 <-> 2
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = createNode(2);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Delete all occurrences of 2
    head = deleteAllOccurrences(head, 2);

    // Print the list after deleting all occurrences of 2
    cout << "List after deleting all occurrences of 2: ";
    printList(head);

    return 0;
}
