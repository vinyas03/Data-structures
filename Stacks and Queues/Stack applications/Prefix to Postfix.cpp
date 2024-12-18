#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert prefix to postfix
string prefixToPostfix(string prefix) {
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

            // Create the postfix expression by combining operand1, operand2, and the operator
            string postfix = operand1 + operand2 + c;

            // Push the resulting postfix expression back onto the stack
            st.push(postfix);
        }
    }

    // The remaining item in the stack is the final postfix expression
    return st.top();
}

int main() {
    string prefix = "*+ABC";
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;

    return 0;
}
