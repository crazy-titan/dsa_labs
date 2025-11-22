#include <iostream>
using namespace std;

class PriorityQueueArray {
    int arr[100];
    int size;

public:
    PriorityQueueArray() {
        size = 0;
    }

    void insert(int value) {
        arr[size++] = value;
    }

    int getMax() {
        if (size == 0) {
            cout << "Priority Queue empty\n";
            return -1;
        }

        int maxVal = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] > maxVal)
                maxVal = arr[i];

        return maxVal;
    }

    int deleteMax() {
        if (size == 0) {
            cout << "Priority Queue empty\n";
            return -1;
        }

        // find index of maximum
        int maxIndex = 0;
        for (int i = 1; i < size; i++)
            if (arr[i] > arr[maxIndex])
                maxIndex = i;

        int maxVal = arr[maxIndex];

        // shift elements left
        for (int i = maxIndex; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
        return maxVal;
    }

    void display() {
        if (size == 0) {
            cout << "Queue empty\n";
            return;
        }

        cout << "Priority Queue (Array): ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueueArray pq;
    pq.insert(15);
    pq.insert(5);
    pq.insert(30);
    pq.insert(20);

    pq.display();

    cout << "Max = " << pq.getMax() << endl;

    cout << "Deleted Max = " << pq.deleteMax() << endl;
    pq.display();

    return 0;
}
