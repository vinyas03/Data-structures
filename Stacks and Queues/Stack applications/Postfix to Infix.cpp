#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If the character is an operand, push it onto the stack
        if (isalnum(c)) {
            string operand(1, c);  // Convert char to string
            st.push(operand);
        }
        // If the character is an operator, pop the top two operands
        else if (isOperator(c)) {
            string operand1 = st.top(); st.pop();
            string operand2 = st.top(); st.pop();

            // Create the infix expression by combining operand2, operator, and operand1
            string infix = "(" + operand2 + c + operand1 + ")";

            // Push the resulting sub-expression back onto the stack
            st.push(infix);
        }
    }

    // The remaining item in the stack is the final infix expression
    return st.top();
}

int main() {
    string postfix = "AB+C*";
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;

    return 0;
}
