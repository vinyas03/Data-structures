#include <iostream>
#include <queue>
using namespace std;

class Stack {
    private:
        queue<int> q;  // Single queue to implement the stack

    public:
        // Push operation
        void push(int value) {
            int size = q.size();  // Get the current size of the queue
            
            // Enqueue the new element into the queue
            q.push(value);

            // Rotate the queue to move the new element to the front
            for (int i = 0; i < size; i++) {
                // Move the front element to the back
                q.push(q.front());
                q.pop();
            }
        }

        // Pop operation
        void pop() {
            if (q.empty()) {
                cout << "Stack underflow!" << endl;
            } else {
                q.pop();  // Remove the front element, which is the top of the stack
            }
        }

        // Peek method to get the top element
        int top() {
            if (q.empty()) {
                cout << "Stack is empty!" << endl;
                return -1;
            }
            return q.front();  // Front element is the top of the stack
        }

        // Method to check if the stack is empty
        bool isEmpty() {
            return q.empty();
        }
};

int main() {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Peek at the top element
    cout << "Top element: " << myStack.top() << endl;

    // Pop an element from the stack
    myStack.pop();
    cout << "After pop, top element: " << myStack.top() << endl;

    // Push another element
    myStack.push(40);
    cout << "Top element: " << myStack.top() << endl;

    return 0;
}
