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


class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }


    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }


    void printNthFromEnd(int n) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* first = head;
        Node* second = head;


        for (int i = 0; i < n; i++) {
            if (first == NULL) {
                cout << "n is greater than the number of nodes." << endl;
                return;
            }
            first = first->next;
        }


        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        cout << "The " << n << "th node from the end is: " << second->data << endl;
    }


    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    list.display();
    list.printNthFromEnd(2);

    return 0;
}
