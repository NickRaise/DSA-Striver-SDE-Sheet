// Insertion In A Singly Linked List

// You are given a Singly Linked List of ‘N’ positive integers. Your task is to add a node having the value ‘VAL’ at position ‘POS’ in the linked list.

// Note:
// Assume that the Indexing for the linked list starts from 0.
// EXAMPLE:
// Input: ‘N’ = 5, 'LIST' = [1, 1, 2, 3, 4, -1], ‘VAL’ = 2, ‘POS’ = 1.

// Output: 1 -> 2 -> 1 -> 2 -> 3 -> 4 


/************************************************************
    Following is the LinkedList class structure:
************************************************************/

class Node {
public:
    int data;
    Node *next;

    // Constructor to initialize the node with given data.
    Node(int val) {
        this->data = val;
        next = nullptr;
    }

    // Destructor to delete the node and its subsequent nodes.
    ~Node() {
        if (next != nullptr) {
            delete next;
        }
    }
};

// Function to insert a node with value 'val' at position 'pos' in the linked list.
Node *insert(Node *head, int n, int pos, int val) {
    // If position is 0, insert at the beginning.
    if (pos == 0) {
        Node *node = new Node(val);
        node->next = head;
        return node;
    }

    // Traverse the linked list until the desired position.
    Node *temp = head;
    int idx = 1;
    while (temp != nullptr) {
        // If the current index matches the desired position, insert the node here.
        if (idx == pos) {
            Node *node = new Node(val);
            node->next = temp->next;
            temp->next = node;
            break;
        }
        temp = temp->next;
        idx++;
    } 
    return head;
}
