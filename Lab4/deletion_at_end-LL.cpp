#include<iostream>

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

    void deletionAtEnd(){
            if(head == NULL){
                cout << "Nothing to delete.."<< endl;
            }else if(head->next == NULL){
                delete(head);
                head = NULL;
            }else{
                Node *t = head;
                while(t->next->next != NULL){
                    t = t->next;
                }
                delete(t->next);
                t->next = NULL;
            }
        }
    
    void printLL(){
            if(head == NULL){
                cout << "Linked List is empty..." << endl;
            }else{
                Node *t = head;
                while( t != NULL){
                    cout << t->data << "->";
                    t = t->next;
                }
            }
        }
};

int main(){
    LinkedList deletion;
    deletion.insertAtBeg(21);
    deletion.insertAtBeg(42);
    deletion.insertAtBeg(25);
    deletion.deletionAtEnd();
    deletion.printLL();
}