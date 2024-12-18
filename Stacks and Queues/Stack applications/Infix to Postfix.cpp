#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to perform infix to postfix conversion
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (char c : infix) {
        // If character is an operand, add it to the postfix expression
        if (isalnum(c)) {
            postfix += c;
        }
        // If character is '(', push it to the stack
        else if (c == '(') {
            st.push(c);
        }
        // If character is ')', pop and output from the stack until '(' is encountered
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Pop the '('
        }
        // If an operator is encountered
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    // Pop all the operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    
    return postfix;
}

int main() {
    string infix = "A+B*(C^D-E)^(F+G*H)-I";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
