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
        void deletionAtPostionAndInsertAtHead(int position){

            if (position < 1) {
                cout << "Error" << endl;
                return;
            }
            
            if (head == NULL) {
                cout << "ErrOR" << endl;
                return;
            }

            Node *nodeToMove = NULL;
            int dataToMove; 

            if(position == 1){
                
                cout << "No move necessary." << endl;
                return;
            }
            else{
                Node *t = head;
                int count = 1;

                while (count < position - 1 && t != NULL) {
                    t = t->next;
                    count++;
                }

                if (t == NULL || t->next == NULL) {
                    cout << " Position out of bounds." << endl;
                    return;
                }
                
                nodeToMove = t->next;
                dataToMove = nodeToMove->data;

                t->next = nodeToMove->next; 

                nodeToMove->next = head; 
                head = nodeToMove;
            }
        }

        void printLL(){
            if(head == NULL){
                cout << "Nothing to print..."<< endl;
            }else{
                Node *t = head;
                while(t != NULL){
                    cout << t->data;
                    if (t->next != NULL) {
                        cout << "->";
                    }
                    t = t->next; 
                }
                cout << endl; 
            }
        }
};

int main(){
    LinkedList operation;
    operation.insertAtBeg(10);
    operation.insertAtBeg(12);
    operation.insertAtBeg(15);
    operation.insertAtBeg(30);
    operation.insertAtBeg(40);
    operation.insertAtBeg(24);
    operation.insertAtBeg(22);
    
    operation.printLL();

    operation.deletionAtPostionAndInsertAtHead(4); 
    operation.printLL(); 
    
    operation.deletionAtPostionAndInsertAtHead(7);
    operation.printLL();
    
    operation.deletionAtPostionAndInsertAtHead(50);
    
    operation.deletionAtPostionAndInsertAtHead(1);

    return 0;
}
