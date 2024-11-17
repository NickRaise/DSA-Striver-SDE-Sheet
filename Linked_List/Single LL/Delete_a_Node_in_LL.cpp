// Delete Node in a Linked List

// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. You will not be given access to the first node of head.

// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

// -> The value of the given node should not exist in the linked list.
// -> The number of nodes in the linked list should decrease by one.
// -> All the values before node should be in the same order.
// -> All the values after node should be in the same order.

// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.



#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int val) {
        this->val = val;
        next = nullptr;
    }
};

// Function to delete the given node from the linked list.
void deleteNode(ListNode* node) {
    // Copy the value of the next node to the current node.
    node->val = node->next->val;
    // Point the current node's next pointer to the node after the next node.
    node->next = node->next->next;
}

// Function to print the linked list.
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create the linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Given node to be deleted: node = 5
    ListNode* nodeToDelete = head->next;

    // Output the original linked list
    cout << "Original linked list: ";
    printList(head);

    // Delete the node
    deleteNode(nodeToDelete);

    // Output the linked list after deletion
    cout << "Linked list after deleting node with value 5: ";
    printList(head);

    return 0;
}

