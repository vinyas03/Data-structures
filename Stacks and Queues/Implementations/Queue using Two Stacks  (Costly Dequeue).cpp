#include <iostream>
#include <stack>
using namespace std;

class Queue {
    private:
        stack<int> s1, s2;  // Two stacks to implement the queue

    public:
        // Enqueue an item to the queue
        void enqueue(int value) {
            // Push the element onto stack s1
            s1.push(value);
        }

        // Dequeue an item from the queue
        int dequeue() {
            // If both stacks are empty, the queue is empty
            if (s1.empty() && s2.empty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }

            // If s2 is empty, transfer elements from s1 to s2
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            // Pop the top item from s2 (the front of the queue)
            int x = s2.top();
            s2.pop();
            return x;
        }

        // Peek the front element of the queue
        int front() {
            // If both stacks are empty, the queue is empty
            if (s1.empty() && s2.empty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }

            // If s2 is empty, transfer elements from s1 to s2
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            // Return the top item from s2 (the front of the queue)
            return s2.top();
        }

        // Check if the queue is empty
        bool isEmpty() {
            return s1.empty() && s2.empty();
        }
};

int main() {
    Queue q;

    // Enqueue elements into the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Dequeue and print elements from the queue
    cout << "Dequeued: " << q.dequeue() << endl;  // 10
    cout << "Dequeued: " << q.dequeue() << endl;  // 20

    // Peek the front element
    cout << "Front element: " << q.front() << endl;  // 30

    // Enqueue another element
    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl;  // 30

    return 0;
}
