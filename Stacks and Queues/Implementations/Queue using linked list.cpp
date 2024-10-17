#include <iostream>
using namespace std;

// Node class to represent each element in the queue
class Node {
    public:
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
};

// Queue class using a linked list
class Queue {
    private:
        Node* front;  // Pointer to the front of the queue
        Node* rear;   // Pointer to the rear of the queue

    public:
        // Constructor to initialize an empty queue
        Queue() {
            front = nullptr;  // Front points to nullptr when queue is empty
            rear = nullptr;   // Rear points to nullptr when queue is empty
        }

        // Enqueue method to add an element to the rear of the queue
        void enqueue(int value) {
            Node* newNode = new Node(value);  // Create a new node with the value
            if (rear == nullptr) {            // If the queue is empty
                front = rear = newNode;       // Both front and rear point to the new node
            } else {
                rear->next = newNode;         // Link the new node at the end of the queue
                rear = newNode;               // Update rear to point to the new node
            }
        }

        // Dequeue method to remove the front element from the queue
        int dequeue() {
            if (isEmpty()) {
                cout << "Queue underflow!" << endl;
                return -1;                    // Return -1 if the queue is empty
            } else {
                Node* temp = front;           // Temporarily store the front node
                int dequeuedValue = front->data;  // Get the value of the front node
                front = front->next;          // Move front to the next node
                if (front == nullptr) {       // If the queue becomes empty after dequeue
                    rear = nullptr;           // Set rear to nullptr as well
                }
                delete temp;                  // Free the memory of the dequeued node
                return dequeuedValue;         // Return the dequeued value
            }
        }

        // Peek method to view the front element without removing it
        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            } else {
                return front->data;           // Return the front element's value
            }
        }

        // Method to check if the queue is empty
        bool isEmpty() {
            return front == nullptr;
        }

        // Destructor to clean up dynamically allocated memory
        ~Queue() {
            while (!isEmpty()) {
                dequeue();                    // Dequeue all elements to free memory
            }
        }
};

int main() {
    Queue myQueue;  // Create an empty queue
    
    // Test enqueuing elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Peek at the front element
    cout << "Front element: " << myQueue.peek() << endl;

    // Test dequeuing elements
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;

    // Check if the queue is empty
    if (myQueue.isEmpty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    // Enqueue more elements
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Peek at the new front element
    cout << "Front element: " << myQueue.peek() << endl;

    return 0;
}
