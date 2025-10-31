#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        next = NULL;
    }
};

class usingStackProperties {
    Node* top;
public:
    usingStackProperties() {
        top = NULL;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(char value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = top;
        top = temp;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Nothing to delete" << endl;
            return '\0';
        } else {
            Node* temp = top;
            char value = top->data;
            top = top->next;
            delete temp;
            return value;
        }
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        } else {
            return top->data;
        }
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    string userExpression;
    cout << "Enter your Infix Expression: ";
    cin >> userExpression;

    usingStackProperties prefixStack; // for operators
    string postfix = "";              // for final postfix output

    for (int i = 0; i < userExpression.length(); i++) {
        char ch = userExpression[i];

        // If operand (number or alphabet)
        if (isalnum(ch)) {
            postfix += ch;
        }

        // If '(' push to stack
        else if (ch == '(') {
            prefixStack.push(ch);
        }

        // If ')' pop until '('
        else if (ch == ')') {
            while (!prefixStack.isEmpty() && prefixStack.peek() != '(') {
                postfix += prefixStack.pop();
            }
            prefixStack.pop(); // remove '('
        }

        // If operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!prefixStack.isEmpty() &&
                    precedence(prefixStack.peek()) >= precedence(ch)) {
                    postfix += prefixStack.pop();
                }
            prefixStack.push(ch);
        }
    }

    // Pop remaining operators
    while (!prefixStack.isEmpty()) {
        postfix += prefixStack.pop();
    }
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
