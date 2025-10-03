#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(){
            next = NULL;
            prev = NULL;
        }
};

class DoublyLinkedList{
    Node *head;
    public:
        DoublyLinkedList(){
            head = NULL;
        }

        void insertAtBeg(int value){
            Node *temp = new Node();
            temp->data = value;
            if(head == NULL){
                head = temp;
            }else{
                temp->next = head;
                head->prev = temp;
                head=temp;
            }
        }
        void printDLL(){
            if(head == NULL){
                cout << "Doubly Linked List is empty..." << endl;
            }else{
                Node *t = head;
                while( t != NULL){
                    cout << t->data << "-";
                    t = t->next;
                }
            }
        }
};

int main(){

    DoublyLinkedList DDL;
    DDL.insertAtBeg(20);
    DDL.insertAtBeg(30);
    DDL.insertAtBeg(10);
    DDL.insertAtBeg(50);
    DDL.printDLL();

    return 0;
}