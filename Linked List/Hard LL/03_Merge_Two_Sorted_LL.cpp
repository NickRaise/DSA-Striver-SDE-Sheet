//  Merge Two Sorted Linked Lists



#include <bits/stdc++.h>
using namespace std;

template <typename T>
    class Node {
    public:
        T data;
        Node* next;

        Node(T data) {
            next = nullptr;
            this->data = data;
        }

        ~Node() {
            if (next != nullptr) {
                delete next;
            }
        }
    };

// Function to merge two sorted linked lists
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    // Create a dummy node to help with the merge process
    Node<int>* dummyNode = new Node<int>(-1);
    Node<int>* prev = dummyNode;

    // Pointers to traverse both lists
    Node<int>* one = first;
    Node<int>* two = second;

    // Traverse both lists and merge them in sorted order
    while (one && two) {
        if (one->data < two->data) {
            prev->next = one;
            prev = one;
            one = one->next;
        } else {
            prev->next = two;
            prev = two;
            two = two->next;
        }
    }

    // If there are remaining elements in either list, append them
    prev->next = (one) ? one : two;

    // Return the head of the merged list
    Node<int>* mergedHead = dummyNode->next;
    delete dummyNode; // Clean up the dummy node
    return mergedHead;
}

// Helper function to print a linked list
template <typename T>
void printList(Node<T>* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector
template <typename T>
Node<T>* createList(const vector<T>& values) {
    if (values.empty()) return nullptr;
    Node<T>* head = new Node<T>(values[0]);
    Node<T>* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node<T>(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create two sorted linked lists
    vector<int> firstList = {1, 3, 5, 7};
    vector<int> secondList = {2, 4, 6, 8};

    Node<int>* first = createList(firstList);
    Node<int>* second = createList(secondList);

    // Print the original lists
    cout << "First List: ";
    printList(first);
    cout << "Second List: ";
    printList(second);

    // Merge the two lists
    Node<int>* merged = sortTwoLists(first, second);

    // Print the merged list
    cout << "Merged List: ";
    printList(merged);

    // Clean up memory
    delete merged;

    return 0;
}
