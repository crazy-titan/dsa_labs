#include <iostream>

using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class linkedListWithStack{
   
    Node* top;
    public:
        linkedListWithStack() {
            top = NULL;
        }

        bool isEmpty() {
            if (top == NULL)
                return true;
            else
                return false;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top; 
            top = newNode;
            cout << value << " pushed into stack." << endl;
        }

        void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = top;
        cout << "Popped element: " << temp->data << endl;
        top = top->next;
        delete temp;
    }

        void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
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
int main(){

    linkedListWithStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.printStack();

    s.peek();

    s.pop();
    s.printStack();

    return 0;
}