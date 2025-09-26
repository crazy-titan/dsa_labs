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

        void deletionAtBeg(){
            if(head == NULL){
                cout << "Nothing to delete" << endl;
            }else{
                Node *temp = head;
                head = head->next;
                delete(temp);
            }
        }
        void print_LL(){
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
        void insertAtBeg(int value){
            Node *temp = new Node();
            temp->data = value;
            
            temp->next = head;
            head = temp;
        }
};
int main(){
    LinkedList deletion;
    deletion.insertAtBeg(10);
    deletion.insertAtBeg(30);
    deletion.insertAtBeg(60);
    deletion.insertAtBeg(40);
    deletion.deletionAtBeg(); // 40 will be removed
    deletion.print_LL();
    return 0;
}