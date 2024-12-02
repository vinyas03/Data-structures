#include <bits/stdc++.h>
using namespace std;

// Define a structure for a Node in the linked list
struct Node {
    int data; // Data stored in the node
    Node* next = nullptr; // Pointer to the next node, initialized to nullptr

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value; // Set the data of the node
        next = nullptr; // Initialize next pointer to nullptr
    }

    // Constructor to initialize a node with a value and a pointer to the next node
    Node(int value, Node* nextNode) : data(value), next(nextNode) {}
};

// Function to convert an array to a linked list
Node* arrayToLL(int arr[], int size) {
    // Create the head of the linked list using the first element of the array
    Node* head = new Node(arr[0]);
    Node* p = head; // Pointer to traverse the linked list

    // Loop through the rest of the array to create nodes
    for (int i = 1; i < size; i++) {
        Node* temp = new Node(arr[i]); // Create a new node for each element
        p->next = temp; // Link the current node to the new node
        p = p->next; // Move the pointer to the new node
    }
    return head; // Return the head of the linked list
}

int main() {
    int arr[] = {1, 2, 3, 4}; // Initialize an array

    // Convert the array to a linked list and get the head
    Node* head = arrayToLL(arr, 4);
    
    // Output the data of the third node in the linked list (value 3)
    cout << head->next->next->data; 
    return 0; // Indicate successful completion
}
