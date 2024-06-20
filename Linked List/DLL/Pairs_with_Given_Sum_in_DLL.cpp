//  Find pairs with given sum in doubly linked list


#include <iostream>
#include <vector>
#include <utility>

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

/**
 * Function to find all pairs of elements in a sorted doubly linked list that sum up to a given value k.
 * 
 * @param head: Pointer to the head node of the doubly linked list.
 * @param k: The target sum value.
 * @return A vector of pairs of integers where each pair represents the data values of two nodes whose sum equals k.
 */
vector<pair<int, int>> findPairs(Node* head, int k) {
    // If the list is empty or has only one element, return an empty vector as no pairs can be formed
    if (!head || !head->next) return {};

    vector<pair<int, int>> ans;  // Vector to store the pairs that sum up to k

    // Initialize two pointers, left starting at the head and right starting at the end of the list
    Node *left = head, *right = head;
    while (right->next) 
        right = right->next;

    int sum;
    // Traverse the list with the two pointers until they meet or cross each other
    while (left->data < right->data) {
        sum = left->data + right->data;  // Calculate the sum of the values pointed by left and right
        if (sum == k) {
            // If the sum equals k, store the pair in the answer vector and move both pointers
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if (sum < k) {
            // If the sum is less than k, move the left pointer to the right to increase the sum
            left = left->next;
        } else {
            // If the sum is greater than k, move the right pointer to the left to decrease the sum
            right = right->prev;
        }
    }

    // Return the vector of pairs
    return ans;
}

int main() {
    // Create a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    int k = 5;  // Target sum value

    // Find all pairs with the given sum
    vector<pair<int, int>> pairs = findPairs(head, k);

    // Print the pairs
    cout << "Pairs with sum " << k << ":" << endl;
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    // Clean up memory
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
