//  Merge k sorted lists

// First list is: 4 -> 6 -> 8 -> NULL
// Second list is: 2 -> 5 -> 7 -> NULL
// Third list is: 1 -> 9 -> NULL
// The final list would be: 1 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a node in a singly linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

// Function to merge k sorted linked lists.
Node* mergeKLists(vector<Node*> &listArray) {
    // Create a min-heap (priority queue) to store the nodes.
    // The min-heap will store pairs of (node data, node pointer).
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;

    // Push the first node of each list into the min-heap.
    for (auto it : listArray) {
        if (it) {
            pq.push({it->data, it});
        }
    }

    // Create a dummy node to act as the head of the merged list.
    Node* dummyNode = new Node(-1);
    Node* prev = dummyNode;

    // Process the min-heap until it's empty.
    while (!pq.empty()) {
        // Extract the node with the smallest data value from the min-heap.
        pair<int, Node*> st = pq.top();
        pq.pop();

        // Add this node to the merged list.
        prev->next = st.second;

        // If there is a next node in the list, push it into the min-heap.
        if (st.second->next) {
            pq.push({st.second->next->data, st.second->next});
        }

        // Move the prev pointer to the next node in the merged list.
        prev = prev->next;
    }

    // Return the head of the merged list, which is next to the dummy node.
    return dummyNode->next;
}

// Function to print the linked list.
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create k sorted linked lists for demonstration.
    Node* l1 = new Node(1, new Node(4, new Node(5)));
    Node* l2 = new Node(1, new Node(3, new Node(4)));
    Node* l3 = new Node(2, new Node(6));

    // Store the lists in a vector.
    vector<Node*> listArray = {l1, l2, l3};

    // Merge the k sorted linked lists.
    Node* mergedHead = mergeKLists(listArray);

    // Print the merged list.
    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}
