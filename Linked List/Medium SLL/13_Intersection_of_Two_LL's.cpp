// Find intersection of Two Linked Lists

// Example 1:
// Input:
// List 1 = [1,3,1,2,4], List 2 = [3,2,4]
// Output:
// 2
// Explanation: Here, both lists intersecting nodes start from node 2.


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

// Function to find the intersection point of two linked lists
Node* findIntersection(Node *firstHead, Node *secondHead) {
    Node *first = firstHead, *second = secondHead;

    // Traverse both lists. When one list reaches the end, switch to the other list's head.
    // If there's an intersection, the two pointers will meet at the intersection node.
    while (first != second) {
        first = (first == nullptr) ? secondHead : first->next;
        second = (second == nullptr) ? firstHead : second->next;
    }

    // Return the intersection node or nullptr if there's no intersection
    return first;
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

// Main function to test the findIntersection function
int main() {
    // Creating two linked lists:
    // List 1: 1 -> 2 -> 3
    // List 2: 4 -> 5
    // Intersection: 6 -> 7
    Node* intersectingNode = createNode(6);
    intersectingNode->next = createNode(7);

    Node* firstHead = createNode(1);
    firstHead->next = createNode(2);
    firstHead->next->next = createNode(3);
    firstHead->next->next->next = intersectingNode;

    Node* secondHead = createNode(4);
    secondHead->next = createNode(5);
    secondHead->next->next = intersectingNode;

    // Print the lists
    cout << "First list: ";
    printList(firstHead);

    cout << "Second list: ";
    printList(secondHead);

    // Find the intersection point
    Node* intersection = findIntersection(firstHead, secondHead);

    // Print the result
    if (intersection) {
        cout << "Intersection point: " << intersection->data << endl;
    } else {
        cout << "No intersection point found." << endl;
    }

    return 0;
}
