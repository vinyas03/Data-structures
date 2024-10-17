#include <iostream>
#include <queue>
using namespace std;

class Stack {
    private:
        queue<int> q1, q2;  // Two queues to implement the stack

    public:
        // Push operation (efficient)
        void push(int value) {
            q1.push(value);  // Simply enqueue the new element into q1
        }

        // Pop operation (costly)
        void pop() {
            if (q1.empty()) {
                cout << "Stack underflow!" << endl;
                return;
            }

            // Move all elements except the last one to q2
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }

            // Remove the last element from q1 (which is the top of the stack)
            q1.pop();

            // Swap the queues
            swap(q1, q2);  // q1 becomes q2 and vice versa
        }

        // Peek method to get the top element
        int top() {
            if (q1.empty()) {
                cout << "Stack is empty!" << endl;
                return -1;
            }

            // Move all elements except the last one to q2
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }

            // Get the last element, which is the top of the stack
            int topElement = q1.front();

            // Move the last element to q2 and swap the queues
            q2.push(topElement);
            q1.pop();
            swap(q1, q2);

            return topElement;
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
