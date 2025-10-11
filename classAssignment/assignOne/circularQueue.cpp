// Write and implement program for the Circular Queue.

#include <iostream>

using namespace std;

class circularQueue{
    const int size = 10;
    int CQ[10];
    int front,rear;

    public:
        circularQueue(){
            front = -1;
            rear = -1;
        }

        bool isFull(){
            if(((rear+1)%size)== front){
                return true;
            }else return false;
        }
        
        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }else return false;
        }
        
        void enque(int value){
            if(isEmpty()){
                rear = (rear+1) % size;
                front = (front+1) % size;
                CQ[front] = value;
            }
            else if(isFull()){
                cout << "Queue Overflow" <<endl;
                return;
            }
            else{
                rear = (rear+1)%size;
                CQ[rear] = value;
            }
        }

        void deque(){
            if(isEmpty()){
                cout << "Queue Underflow" << endl;
                return;
            }
            int deleteNumber = CQ[front];
            cout << "The Deleted Number is " << deleteNumber << endl;

            if(front == rear){
                front = -1;
                rear = -1;
            }else{
                front = (front+1)%size;
            }
        }

        void printCQ() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return;
            }

            cout << "Queue Elements are: ";
            int i = front;
           
            if (front <= rear) {
                while (i <= rear) {
                    cout << CQ[i] << " ";
                    i++;
                }
            } else {
                while (i < size) {
                    cout << CQ[i] << " ";
                    i++;
                }
                i = 0;
                while (i <= rear) {
                    cout << CQ[i] << " ";
                    i++;
                }
            }
            cout << endl;
        }
};

int main(){

    circularQueue *cq = new circularQueue();
    cq->enque(5);
    cq->enque(15);
    cq->enque(35);
    cq->printCQ();

   
    return 0;
}