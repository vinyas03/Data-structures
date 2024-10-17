#include <iostream>
using namespace std;

class Stack {
    private:
        int* s;    // Pointer to dynamically allocate array
        int size;  // Member variable to store size
        int top;   // To keep track of the top element
    public:
        // Constructor to initialize the stack with a given size
        Stack(int size) {
            this->size = size;      // Set the member variable
            s = new int[size];      // Dynamically allocate array of 'size'
            top = -1;               // Initialize top to -1 (empty stack)
        }
        
        // Destructor to free dynamically allocated memory
        ~Stack() {
            delete[] s;
        }

        // Push method to add an element to the stack
        void push(int value) {
            if (top == size - 1) {
                cout << "Stack overflow!" << endl;
            } else {
                s[++top] = value;   // Increment top and add value
            }
        }

        // Pop method to remove the top element from the stack
        int pop() {
            if (top == -1) {
                cout << "Stack underflow!" << endl;
                return -1;          // Return -1 if the stack is empty
            } else {
                return s[top--];    // Return the top element and decrement top
            }
        }

        // Peek method to view the top element without removing it
        int peek() {
            if (top == -1) {
                cout << "Stack is empty!" << endl;
                return -1;
            } else {
                return s[top];      // Return the top element
            }
        }

        // Method to check if the stack is empty
        bool isEmpty() {
            return top == -1;
        }
};

int main() {
    Stack myStack(5);  // Create a stack of size 5
    
    // Test pushing elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Test peeking the top element
    cout << "Top element: " << myStack.peek() << endl;

    // Test popping elements
    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    // Check if stack is empty
    if (myStack.isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    return 0;
}
