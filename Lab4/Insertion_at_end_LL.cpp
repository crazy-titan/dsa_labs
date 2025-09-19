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

        void insert_at_end(int value){
    
        Node *temp = new Node();
        temp->data = value;
        if(head == NULL){
            head = temp;   
            }
        else{
        Node *t = head;
            while(t->next != NULL){
                t = t->next;
            }
            t->next = temp;
        }
    } 

     void print_LL(){
            if(head == NULL){
                cout << "LINKEDLIST is Empty." << endl;
            }else{
                Node *p = head;
                while(p != NULL){
                    cout << p->data << "->";
                    p = p->next;
                }
            }
        }
};



int main(){

    LinkedList LL;
    LL.insert_at_end(20);
    LL.insert_at_end(30);
    LL.insert_at_end(10);
    LL.insert_at_end(110);
    LL.print_LL();

    return 0;
}