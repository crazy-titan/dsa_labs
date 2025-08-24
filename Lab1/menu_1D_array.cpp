//  Write a program to implement 1D array. 
//  Apply basic operations such as create, insert, delete, and traverse on it.



#include<iostream>
using namespace std;

void traverse(int array[],int size){
    for(int i = 0; i < size; i++){
        
        cout << "Traverse:" << array[i] << " ";
    }
}

void adding(int array[],int size,int &currentSize, int position, int value){
    
    if(position < 1 || position > currentSize + 1 || currentSize >= size){
        cout << "Invalid Inputs:"<< endl;
    }else{
        for(int i = currentSize - 1; i >= position -1; i--){
            array[i+1] = array[i];
        }
        array[position-1] = value;
        currentSize++;

        for(int j = 0; j < currentSize ; j++){
            cout << array[j] << " ";
        }
    }
}

void deletion(int array[],int size, int &currentSize, int position){
    if(position < 1 || position > currentSize || currentSize < 1){
        cout << "Invalid Inputs:"<< endl;
    }else{
        for(int i = position - 1 ; i < currentSize -1 ; i++){   // why -2 ? think
            array[i] = array[i+1];
        }
        currentSize--;

        for(int j = 0; j < currentSize ; j++){
            
            cout << array[j] << " ";
        }
    }
}

void searching(int array[],int &currentSize, int value){
    for(int i = 0; i < currentSize; i++){
        if(array[i] == value){
            cout << "Yes,at position " << (i+1) << " We have "<< value << " in Array." << endl;
            break;
        }else{
            cout << "At position " << (i+1) << " We don't have "<< value << " in Array." << endl;
        }
    } 
}


void choiceFunction(){
    cout<< "\nPick any One Choice:" << endl;
    cout<< "1. Traverse" << endl;
    cout<< "2. Adding" << endl;
    cout<< "3. Deletion" << endl;
    cout<< "4. Search" << endl;
    cout<< "5. Stop" << endl;
    cout << "Enter Your Choice:";
}

int main(){
    int choice;
    int Max_size;
    int LabOne[Max_size];
    int currentSize;
    int insert;
    int value;
    int removed;
    int toSearch;

    
    cout << "What is the length of Array You want to make?" << endl;
    cin >> Max_size;
    cout << "How many values you have currently in your array?" << endl;
    cin >> currentSize;
    for (int i = 0; i < currentSize; i++){
        cout << "Enter your values one by one..."<< endl;
        cin >> LabOne[i];
    }

    // make a seperate fucntion to ask again and again;

    // cout<< "Pick any One Choice:" << endl;
    // cout<< "1. Traverse" << endl;
    // cout<< "2. Adding" << endl;
    // cout<< "3. Deletion" << endl;
    // cout<< "4. Search" << endl;
    // cout<< "5. Stop" << endl;
    // cout << "Enter Your Choice:";

   


    while(true){

        choiceFunction();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Your have selected Traverse: "<< endl;

            traverse(LabOne,currentSize);

            break;
            
            case 2:
            cout << "Your have selected Adding: "<< endl;
            cout << "Enter Your position of Insert: "<< endl;
            cin >> insert;
            cout << "Enter Your Value your want to Insert: "<< endl;
            cin >> value;
            
            adding(LabOne,Max_size,currentSize,insert,value);

            break;
            
            case 3:
            cout << "Your have selected Deletion: "<< endl;
            cout << "Enter Your location of deletion:" << endl;
            cin >> removed;
            
            deletion(LabOne,Max_size,currentSize,removed);

            break;
            
            case 4:
            cout << "Your have selected Search: "<< endl;
            cout << "Enter Your value for Searching."<< endl;
            cin >> toSearch;
            
            searching(LabOne,currentSize,toSearch);
            break;

            default:
            cout << "Invalid Choice." << endl;
            
            break;
        }
    if (choice == 5){
        cout << "Program Ended"<< endl;
        break;
        }
    }
    return 0;
}


// i need some help how to make this user input based in making the array?
// help me with that, i tried but didn't work , may be something more i have to think to build logic.