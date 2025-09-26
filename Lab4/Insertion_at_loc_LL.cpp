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

        void insert_at_loc(int value,int position){
            Node *temp = new Node();
            temp->data = value;

            if(position == 1){
                temp->next = head;
                head = temp;
            }else{
                Node *t = head;
                while((position-2) != 0 && t->next != NULL){
                    position--;
                    t = t->next;
                }
                temp->next = t->next;
                t->next = temp;
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
};
int main(){
    LinkedList atPosition;
    atPosition.insertAtBeg(10);
    atPosition.insertAtBeg(340);
    atPosition.insertAtBeg(210);
    atPosition.insertAtBeg(60);
    atPosition.insertAtBeg(110);
    atPosition.insert_at_loc(40,4);
    atPosition.print_LL();
    return 0;
}