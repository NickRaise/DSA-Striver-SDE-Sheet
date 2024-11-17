//  Design Browser History



#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data; // Stores the URL or page data
    Node* next;  // Pointer to the next node (next page)
    Node* prev;  // Pointer to the previous node (previous page)
    
    // Default constructor
    Node() : data(""), next(nullptr), prev(nullptr) {}
    
    // Constructor with data
    Node(string s) : data(s), next(nullptr), prev(nullptr) {}
};

class Browser {
public:
    Node* current; // Pointer to the current node (current page)

    // Constructor to initialize the browser with a homepage
    Browser(string &homepage) {
        current = new Node(homepage); // Create a new node for the homepage
    }

    // Method to visit a new URL
    void visit(string &url) {
        Node* node = new Node(url);  // Create a new node for the new URL
        node->prev = current;        // Set the previous pointer of the new node to the current node
        current->next = node;        // Set the next pointer of the current node to the new node
        current = current->next;     // Move the current pointer to the new node
    }

    // Method to go back a certain number of steps
    string back(int steps) {
        // Move the current pointer back by the given number of steps
        while (steps--) {
            if (current->prev)       // Check if there is a previous node
                current = current->prev;
            else
                break;               // Break if there is no previous node
        }
        return current->data;        // Return the data of the current node
    }

    // Method to go forward a certain number of steps
    string forward(int steps) {
        // Move the current pointer forward by the given number of steps
        while (steps--) {
            if (current->next)       // Check if there is a next node
                current = current->next;
            else
                break;               // Break if there is no next node
        }
        return current->data;        // Return the data of the current node
    }
};

// Example usage
int main() {
    string homepage = "www.homepage.com";
    Browser browser(homepage);

    string url1 = "www.page1.com";
    string url2 = "www.page2.com";
    string url3 = "www.page3.com";

    browser.visit(url1);
    browser.visit(url2);
    browser.visit(url3);

    cout << "Current page: " << browser.current->data << endl; // Outputs www.page3.com

    cout << "Go back 1 step: " << browser.back(1) << endl; // Outputs www.page2.com
    cout << "Go back 1 step: " << browser.back(1) << endl; // Outputs www.page1.com
    cout << "Go forward 1 step: " << browser.forward(1) << endl; // Outputs www.page2.com

    return 0;
}
