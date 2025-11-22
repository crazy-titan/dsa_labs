#include <iostream>
using namespace std;

class MaxHeap {
    int heap[100];   // fixed-size array
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int value) {
        heap[++size] = value;
        int i = size;

        // Percolate up
        while (i > 1 && heap[i/2] < heap[i]) {
            swap(heap[i], heap[i/2]);
            i = i/2;
        }
    }

    int getMax() {
        if (size == 0) {
            cout << "Priority Queue empty\n";
            return -1;
        }
        return heap[1];
    }

    int deleteMax() {
        if (size == 0) {
            cout << "Priority Queue empty\n";
            return -1;
        }

        int maxVal = heap[1];
        heap[1] = heap[size--];

        // Percolate down
        int i = 1;
        while (true) {
            int left = 2*i;
            int right = 2*i + 1;
            int largest = i;

            if (left <= size && heap[left] > heap[largest])
                largest = left;
            if (right <= size && heap[right] > heap[largest])
                largest = right;

            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }

        return maxVal;
    }

    void display() {
        if (size == 0) {
            cout << "Queue empty\n";
            return;
        }
        cout << "Priority Queue (Max-Heap): ";
        for (int i = 1; i <= size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;
    pq.insert(10);
    pq.insert(40);
    pq.insert(30);
    pq.insert(25);
    pq.insert(5);

    pq.display();

    cout << "Max = " << pq.getMax() << endl;

    cout << "Deleted Max = " << pq.deleteMax() << endl;
    pq.display();

    return 0;
}
