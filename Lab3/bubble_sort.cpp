#include<iostream>
using namespace std;

void bubbleSort(int array[],int size){
    for(int i = 0; i < size-1 ; i++){
        for(int j = 0; j < size - i - 1;j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
}



int main(){
    int size,choice, currentSize;
    cout << "Enter your Length of Array..." << endl;
    cin >> size;
    

    int array[size];
    for(int i = 0; i < size; i++){
        cout << "Enter your values one by one..." << endl;
        cin >> array[i];
    }

    cout << "Want to do bubble sort? (1 for 'Yes' 0 for 'No')" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        bubbleSort(array,size);
        for(int i = 0; i < size; i++){
            cout << array[i] << " - ";
        }

        break;
    
    case 0:
        cout << "Nothing to Sort..." << endl;
    default:
        break;
    }

    
    return 0;
}