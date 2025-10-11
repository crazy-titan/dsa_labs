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

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == NULL) { 
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to queue." << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty, cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        cout << front->data << " dequeued from queue." << endl;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void print() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements:-> ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};


int main(){

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();



    return 0;
}