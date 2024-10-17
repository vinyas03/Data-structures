#include <iostream>
using namespace std;

class Queue {
    private:
        int* q;    // Pointer to dynamically allocate the queue array
        int front; // Index of the front element
        int rear;  // Index of the rear element
        int size;  // Maximum size of the queue
        int count; // To keep track of the number of elements in the queue

    public:
        // Constructor to initialize the queue with a given size
        Queue(int size) {
            this->size = size;
            q = new int[size];  // Dynamically allocate memory for the queue
            front = 0;          // Front is initially at 0
            rear = -1;          // Rear is initially at -1 (no elements in the queue)
            count = 0;          // No elements in the queue initially
        }
        
        // Destructor to free dynamically allocated memory
        ~Queue() {
            delete[] q;
        }

        // Enqueue method to add an element at the rear of the queue
        void enqueue(int value) {
            if (count == size) {
                cout << "Queue overflow!" << endl;  // Check if the queue is full
            } else {
                rear = (rear + 1) % size;           // Move rear in a circular manner
                q[rear] = value;                   // Insert value at the rear
                count++;                           // Increment the number of elements
            }
        }

        // Dequeue method to remove the front element from the queue
        int dequeue() {
            if (isEmpty()) {
                cout << "Queue underflow!" << endl;
                return -1;                         // Return -1 if the queue is empty
            } else {
                int value = q[front];              // Get the value from the front
                front = (front + 1) % size;        // Move front in a circular manner
                count--;                           // Decrement the number of elements
                return value;                      // Return the dequeued element
            }
        }

        // Peek method to view the front element without removing it
        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            } else {
                return q[front];                   // Return the front element
            }
        }

        // Method to check if the queue is empty
        bool isEmpty() {
            return count == 0;
        }

        // Method to check if the queue is full
        bool isFull() {
            return count == size;
        }

        // Method to get the current number of elements in the queue
        int sizeOfQueue() {
            return count;
        }
};

int main() {
    Queue myQueue(5);  // Create a queue of size 5
    
    // Test enqueuing elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Check if the queue is full
    if (myQueue.isFull()) {
        cout << "Queue is full!" << endl;
    }

    // Test dequeuing elements
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;

    // Peek the front element
    cout << "Front element: " << myQueue.peek() << endl;

    // Enqueue more elements
    myQueue.enqueue(60);

    // Check current size of the queue
    cout << "Current size of queue: " << myQueue.sizeOfQueue() << endl;

    return 0;
}
