#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Function to convert infix expression to postfix
//
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        // If the current character is an operand, append it to the postfix expression
        if (isdigit(infix[i]))
            postfix += infix[i];

        // If the current character is an open parenthesis, push it onto the stack
        else if (infix[i] == '(')
            s.push(infix[i]);

        // If the current character is a closing parenthesis,
        // pop all the operators from the stack until the matching open parenthesis is found
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
            else
                return "Invalid expression"; // Return an error if the closing parenthesis is not preceded by an open parenthesis
        }
        else
        {
            // If the current character is an operator, pop all the operators from the stack that have higher or equal precedence
            // and append them to the postfix expression
            while (!s.empty() && s.top() != '(' && (infix[i] == '*' || infix[i] == '/') && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-'))
            {
                postfix += s.top();
                s.pop();
            }

            // Push the current operator onto the stack
            s.push(infix[i]);
        }
    }

    // Pop all the remaining operators from the stack and append them to the postfix expression
    while (!s.empty())
    {
        if (s.top() == '(')
            return "Invalid expression"; // Return an error if there are any unbalanced parentheses

        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix)
{
    stack<int> s;

    for (int i = 0; i < postfix.length(); i++)
    {
        // If the current character is an operand, push it onto the stack
        if (isdigit(postfix[i]))
            s.push(postfix[i] - '0');

        // If the current character is an operator, pop the top two operands from the stack,
        // perform the operation, and push the result back onto the stack
        else
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            int result;
        }
     }
}
int main()
{
    string infix = "5*231";
    string postfix = infixToPostfix(infix);
    cout << "The postfix expression is: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "The result of the expression is: " << result << endl;

    return 0;
}