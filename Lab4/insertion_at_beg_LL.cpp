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

        void insertAtBeg(int value){
            Node *temp = new Node();
            temp->data = value;
            
            temp->next = head;
            head = temp;
        }

        void printLL(){
            if(head == NULL){
                cout << "Linked List is empty..." << endl;
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
    LinkedList LLBeg;
    LLBeg.insertAtBeg(10);
    LLBeg.insertAtBeg(20);
    LLBeg.insertAtBeg(30);
    LLBeg.insertAtBeg(40);
    LLBeg.printLL();
    return 0;
}