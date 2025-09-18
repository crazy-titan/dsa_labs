#include<iostream>
using namespace std;


void selectionSort(int array[],int size){
    for(int i = 0; i < size ;i++ ){
        int min = i;
        for(int j =0; j < size -1;j++){
            if(array[j] > array[min]){
                min = j;
            }
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
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
        selectionSort(array,size);
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