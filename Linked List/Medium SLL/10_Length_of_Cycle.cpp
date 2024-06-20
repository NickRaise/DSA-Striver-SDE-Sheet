// Find length of Loop

// Input: Linked List: 4 -> 10 -> 3 -> 5 -> 10(at position 2)
// Output: Length of cycle = 3
// Explanation: The cycle is 10, 3, 5.



#include <iostream>
using namespace std;

// Definition of linked list Node
class Node {
public:
    int data;
    Node *next;

    // Constructor to initialize a Node with data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to find the length of a loop in a linked list
int lengthOfLoop(Node *head) {

    if(!head || !head->next) return 0;
    
    Node *slow = head, *fast = head;

    // Traverse the list with two pointers
    // - 'slow' moves one step at a time
    // - 'fast' moves two steps at a time
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        // If slow and fast pointers meet, there is a cycle
        if (slow == fast)
            break;
    }

    // If no cycle is detected
    if (fast != slow)
        return 0;

    int length = 1;
    fast = fast->next;

    // Count the number of nodes in the loop
    while (slow != fast) {
        fast = fast->next;
        length++;
    }

    return length;
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

// Main function to test the lengthOfLoop function
int main() {
    // Creating a linked list with a cycle
    Node* cycleList = createCycleList();
    // Creating a linked list without a cycle
    Node* noCycleList = createNoCycleList();

    // Testing lengthOfLoop function
    int cycleLength = lengthOfLoop(cycleList);
    int noCycleLength = lengthOfLoop(noCycleList);

    if (cycleLength > 0) {
        cout << "Length of loop in cycle list: " << cycleLength << endl;
    } else {
        cout << "No cycle detected in cycle list" << endl;
    }

    if (noCycleLength > 0) {
        cout << "Length of loop in no cycle list: " << noCycleLength << endl;
    } else {
        cout << "No cycle detected in no cycle list" << endl;
    }

    return 0;
}
