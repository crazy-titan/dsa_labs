#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(){
            next = NULL;
        }
};
class LinkedList{
    Node *head;
    public:
        LinkedList(){
            head = NULL;
        }

        void insert(int value) {
            Node *newNode = new Node();
            newNode->data = value;

            if (head == NULL || value < head->data) {
                newNode->next = head;
                head = newNode;
                return;
            } 
            
            Node* current = head;
            while (current->next != NULL && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        void deleteNode(int value) {
        if (head == NULL) {
            cout << "empty" << endl;
            return;
        }
         if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << endl;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }
        if (current->next != NULL) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Deleted " << value << endl;
        } else {
            cout << value << " not found in the list." << endl;
        }
    }
    bool search(int value) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            if (current->data > value) {
                return false;
            }
            current = current->next;
        }
        return false;
    }
    void display() {
        Node* current = head;
        if (current == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

};
int main(){

    LinkedList sortedList;
    sortedList.insert(15);
    sortedList.insert(5);
    sortedList.insert(25);
    sortedList.insert(10);
    sortedList.insert(20);
    sortedList.display();



    cout << "\nSearching for 15:" << endl;
    if (sortedList.search(15)) {
        cout << "15 found in the list." << endl;
    } else {
        cout << "15 not found in the list." << std::endl;
    }

    cout << "\nSearching for 30:" << endl;
    if (sortedList.search(30)) {
        cout << "30 found in the list." << endl;
    } else {
        cout << "30 not found in the list." << endl;
    }


    cout << "\nDeleting 15 from the list:" << endl;
    sortedList.deleteNode(15);
    sortedList.display(); 

    cout << "\nDeleting 5 (the head node):" <<endl;
    sortedList.deleteNode(5);
    sortedList.display();

    cout << "\n delete a value (99):" <<endl;
    sortedList.deleteNode(99);
    sortedList.display();

    cout << "\nFinal list:" << endl;
    sortedList.display();
    return 0;
}