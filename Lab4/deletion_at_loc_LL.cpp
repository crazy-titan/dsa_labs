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

        void deletionAtPostion(int position){
            if(position == 1){
                Node *temp = head;
                head = head->next;
                delete(temp);
            }
            else{
                Node *t = head;
                while((position - 2) != 0 && t->next != NULL){
                    position--;
                    t = t->next;
                }
                Node *temp = t->next;
                t->next = temp->next;
                delete(temp);
                
            }
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
    LinkedList LL_Loc;
    LL_Loc.insertAtBeg(10);
    LL_Loc.insertAtBeg(20);
    LL_Loc.insertAtBeg(30);
    LL_Loc.insertAtBeg(40);
    LL_Loc.deletionAtPostion(3);
    LL_Loc.printLL();
    return 0;
}