#include <iostream>
#include <stack>
using namespace std;

class Queue {
    private:
        stack<int> stack1, stack2;  // Two stacks for implementing the queue

    public:
        // Enqueue operation (push an element to the back of the queue)
        void enqueue(int value) {
            // Move all elements from stack1 to stack2 to reverse the order
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }

            // Push the new element onto stack1
            stack1.push(value);

            // Move all elements back from stack2 to stack1 to restore the order
            while (!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }

        // Dequeue operation (remove an element from the front of the queue)
        void dequeue() {
            if (stack1.empty()) {
                cout << "Queue underflow!" << endl;
            } else {
                stack1.pop();  // Remove the front element (which is on top of stack1)
            }
        }

        // Peek operation (get the front element of the queue)
        int front() {
            if (stack1.empty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            return stack1.top();  // The front element is on top of stack1
        }

        // Method to check if the queue is empty
        bool isEmpty() {
            return stack1.empty();  // Queue is empty if stack1 is empty
        }
};

int main() {
    Queue myQueue;

    // Enqueue elements into the queue
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Peek at the front element
    cout << "Front element: " << myQueue.front() << endl;  // Should be 10

    // Dequeue an element from the queue
    myQueue.dequeue();
    cout << "After dequeue, front element: " << myQueue.front() << endl;  // Should be 20

    // Enqueue another element
    myQueue.enqueue(40);
    cout << "Front element: " << myQueue.front() << endl;  // Should still be 20

    return 0;
}
