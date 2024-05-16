// Convert an array into LinkedList


#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* constructLL(vector<int>& arr) {
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i = 1; i < arr.size(); i++) {
        Node *node =  new Node(arr[i]);
        temp->next = node;
        temp = node;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = constructLL(arr);
    cout << "Linked List: ";
    printLinkedList(head);
    return 0;
}
