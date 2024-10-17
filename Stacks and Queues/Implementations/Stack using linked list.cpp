#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node {
    public:
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
};

// Stack class using linked list
class Stack {
    private:
        Node* top;  // Pointer to the top element of the stack

    public:
        // Constructor to initialize an empty stack
        Stack() {
            top = nullptr;  // Set top to nullptr (empty stack)
        }

        // Push method to add an element to the stack
        void push(int value) {
            Node* newNode = new Node(value);  // Create a new node with the value
            newNode->next = top;              // Link the new node to the current top
            top = newNode;                    // Update top to point to the new node
        }

        // Pop method to remove the top element from the stack
        int pop() {
            if (isEmpty()) {
                cout << "Stack underflow!" << endl;
                return -1;                    // Return -1 if the stack is empty
            } else {
                int poppedValue = top->data;  // Get the value from the top node
                Node* temp = top;             // Temporarily store the top node
                top = top->next;              // Update top to the next node
                delete temp;                  // Delete the old top node
                return poppedValue;           // Return the popped value
            }
        }

        // Peek method to view the top element without removing it
        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty!" << endl;
                return -1;
            } else {
                return top->data;             // Return the top element's value
            }
        }

        // Method to check if the stack is empty
        bool isEmpty() {
            return top == nullptr;
        }

        // Destructor to clean up dynamically allocated memory
        ~Stack() {
            while (!isEmpty()) {
                pop();                        // Pop all elements to free memory
            }
        }
};

int main() {
    Stack myStack;  // Create a stack
    
    // Test pushing elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Test peeking the top element
    cout << "Top element: " << myStack.peek() << endl;

    // Test popping elements
    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    // Check if the stack is empty
    if (myStack.isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    return 0;
}
