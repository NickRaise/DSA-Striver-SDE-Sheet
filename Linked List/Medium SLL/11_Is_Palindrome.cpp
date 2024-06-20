//  Check If Linked List Is Palindrome

// A Linked List is a palindrome if it reads the same from left to right and from right to left.

// Sample Input 1:
// 1 2 2 1
// Sample Output 1:
// True



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

// Function to reverse a linked list
Node* reverseList(Node* head) {
    if (!head || !head->next) return head;

    Node* newHead = reverseList(head->next);

    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node *slow = head, *fast = head;

    // Use two pointers to find the middle of the list
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    Node* newHead = reverseList(slow->next);

    Node *first = head, *second = newHead;

    bool flag = false;

    // Compare the first half and the reversed second half
    while (second) {
        if (first->data != second->data) {
            flag = true;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Restore the second half of the list
    reverseList(newHead);

    if (flag) return false;
    return true;
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

// Main function to test the isPalindrome function
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Check if the list is a palindrome
    if (isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    // Print the list after checking (to ensure it is restored)
    cout << "List after palindrome check: ";
    printList(head);

    return 0;
}
