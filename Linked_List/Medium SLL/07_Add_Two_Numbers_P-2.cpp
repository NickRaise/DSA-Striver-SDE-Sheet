// Add two numbers represented by linked lists

// You have been given two singly Linked Lists, where each of them represents a positive number without any leading zeros.

// The two numbers represented by these two lists are 12345 and 45, respectively. 
// So, adding these two numbers gives 12390. 



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

// Function to reverse a linked list
Node* reverseList(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    // Recursively reverse the rest of the list
    Node* newHead = reverseList(head->next);

    // Adjust the pointers
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

// Function to add two numbers represented by linked lists
Node* addTwoLists(Node* firstHead, Node* secondHead) {
    // If one of the lists is empty, return the other list
    if (!firstHead) return secondHead;
    if (!secondHead) return firstHead;

    // Reverse both lists
    firstHead = reverseList(firstHead);
    secondHead = reverseList(secondHead);

    Node* first = firstHead;
    Node* second = secondHead;

    // Initialize sum and carry
    int sum = first->data + second->data;
    int carry = sum / 10;
    int val = sum % 10;

    // Create the head of the result list
    Node* head = new Node(val);
    Node* curr = head;

    first = first->next;
    second = second->next;

    // Loop through both lists until the end
    while (first || second) {
        int val1 = (first) ? first->data : 0;
        int val2 = (second) ? second->data : 0;
        sum = val1 + val2 + carry;
        val = sum % 10;
        carry = sum / 10;

        // Create a new node with the calculated value
        Node* node = new Node(val);
        curr->next = node;
        curr = node;

        if (first) first = first->next;
        if (second) second = second->next;
    }

    // If there's a carry left, add a new node with the carry value
    if (carry > 0) {
        Node* node = new Node(carry);
        curr->next = node;
    }

    // Reverse the result list to get the final answer
    head = reverseList(head);
    
    // Remove any leading zeros (if any)
    while (head->data == 0 && head->next != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the addTwoLists function
int main() {
    // Creating two sample linked lists: 123 and 456
    Node* firstHead = new Node(3);
    firstHead->next = new Node(2);
    firstHead->next->next = new Node(1);

    Node* secondHead = new Node(6);
    secondHead->next = new Node(5);
    secondHead->next->next = new Node(4);

    cout << "First list: ";
    printList(firstHead);
    cout << "Second list: ";
    printList(secondHead);

    // Adding the two lists
    Node* resultHead = addTwoLists(firstHead, secondHead);

    cout << "Result list: ";
    printList(resultHead);

    return 0;
}
