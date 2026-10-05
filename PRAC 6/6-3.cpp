#include <iostream>
#include <stack>
using namespace std;

int priority(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main() {
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    stack<char> s;
    string postfix = "";

    for (char c : exp) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else {
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                postfix += s.top();
                s.pop();
            }

            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}