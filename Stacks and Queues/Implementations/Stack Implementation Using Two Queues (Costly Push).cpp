#include <iostream>
#include <queue>
using namespace std;

class Stack {
    private:
        queue<int> q1, q2;  // Two queues to implement the stack

    public:
        // Push operation (costly)
        void push(int value) {
            // Move all elements from q1 to q2
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            // Push the new element into q1
            q1.push(value);

            // Move all elements back to q1 from q2
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }

        // Pop operation (efficient)
        void pop() {
            if (q1.empty()) {
                cout << "Stack underflow!" << endl;
            } else {
                q1.pop();  // Remove the front element (top of the stack)
            }
        }

        // Peek method to get the top element
        int top() {
            if (q1.empty()) {
                cout << "Stack is empty!" << endl;
                return -1;
            } else {
                return q1.front();  // Return the front element, which is the top of the stack
            }
        }

        // Method to check if the stack is empty
        bool isEmpty() {
            return q1.empty();
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
