#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert prefix to infix
string prefixToInfix(string prefix) {
    stack<string> st;

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // If the character is an operand, push it onto the stack
        if (isalnum(c)) {
            string operand(1, c);  // Convert char to string
            st.push(operand);
        }
        // If the character is an operator, pop the top two operands
        else if (isOperator(c)) {
            string operand1 = st.top(); st.pop();
            string operand2 = st.top(); st.pop();

            // Create the infix expression by combining operand1, operator, and operand2
            string infix = "(" + operand1 + c + operand2 + ")";

            // Push the resulting sub-expression back onto the stack
            st.push(infix);
        }
    }

    // The remaining item in the stack is the final infix expression
    return st.top();
}

int main() {
    string prefix = "*+ABC";
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;

    return 0;
}
