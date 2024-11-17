// Add two numbers represented as Linked Lists

// Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// Input Format: 
// (Pointer/Access to the head of the two linked lists)

// num1  = 243, num2 = 564

// l1 = [2,4,3]
// l2 = [5,6,4]

// Result: sum = 807; L = [7,0,8]

// Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the original number and then add them as → 342 + 465 = 807.



#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;

        ListNode *head = new ListNode(sum % 10);
        int carry = sum / 10;
        l1 = l1->next, l2 = l2->next;
        ListNode *temp = head;
        ListNode *node;
        while (l1 != nullptr || l2 != nullptr) {
            sum = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + carry;
            node = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = node;
            temp = node;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (carry > 0) {
            node = new ListNode(carry);
            temp->next = node;
        }
        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating sample linked lists: 2 -> 4 -> 3 and 5 -> 6 -> 4
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Sum of the two numbers: ";
    printList(result);

    return 0;
}

