#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix to prefix
string postfixToPrefix(string postfix) {
    stack<string> st;

    // Traverse the postfix expression from left to right
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

            // Create the prefix expression by combining operator, operand2, and operand1
            string prefix = c + operand2 + operand1;

            // Push the resulting prefix expression back onto the stack
            st.push(prefix);
        }
    }

    // The remaining item in the stack is the final prefix expression
    return st.top();
}

int main() {
    string postfix = "AB+C*";
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;

    return 0;
}
