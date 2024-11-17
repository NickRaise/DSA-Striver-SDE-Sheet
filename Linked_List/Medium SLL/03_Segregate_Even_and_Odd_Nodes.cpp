// Segregate even and odd nodes in a Linked List

// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. 
// The order of appearance of numbers within each segregation should be same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one.

// Input: 
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9

// Explaination: 8,2,4,6 are the even numbers 
// so they appear first and 17,15,9 are odd 
// numbers that appear later.


#include <iostream>
using namespace std;

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *      int data;
 *      Node *next;
 *      Node() : data(0), next(nullptr) {};
 *      Node(int x) : data(x), next(nullptr) {}
 *      Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node* segregateEvenOdd(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node *curr = head, *evenStart = nullptr, *evenEnd = nullptr, *oddStart = nullptr, *oddEnd = nullptr;
    int val;
    while (curr != nullptr) {
        val = curr->data;
        if (val % 2 == 0) {
            if (evenStart == nullptr) {
                evenStart = curr;
                evenEnd = curr;
            } else {
                evenEnd->next = curr;
                evenEnd = curr;
            }
        } else {
            if (oddStart == nullptr) {
                oddStart = curr;
                oddEnd = curr;
            } else {
                oddEnd->next = curr;
                oddEnd = curr;
            }
        }
        curr = curr->next;
    }

    if (evenStart == nullptr || oddStart == nullptr) return head;

    evenEnd->next = oddStart;
    oddEnd->next = nullptr;

    return evenStart;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    head = segregateEvenOdd(head);

    cout << "List after segregating even and odd nodes: ";
    printList(head);

    return 0;
}
