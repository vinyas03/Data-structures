#include <bits/stdc++.h> // Include standard libraries for various functionalities
using namespace std;

// Define a structure for a Node in a linked list
struct Node {
    int data; // Variable to hold the data of the node
    Node* next = nullptr; // Pointer to the next node, initialized to nullptr

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value; // Set the data of the node
        next = nullptr; // Initialize next pointer to nullptr
    }

    // Constructor to initialize a node with a value and a pointer to the next node
    Node(int value, Node* nextNode) : data(value), next(nextNode) {}
};

int main() {
    
    // Create a new node with the value 4
    Node* newNode = new Node(4);
    cout << newNode->data << endl; // Output the data of the new node (should print 4)

    // Create a node x with the value 77 (stack allocation)
    Node x = Node(77);
    cout << x.data << endl; // Output the data of node x (should print 77)

    return 0; // Return 0 to indicate successful execution
}
