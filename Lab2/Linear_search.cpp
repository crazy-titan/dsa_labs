#include <iostream>
#include <string>
using namespace std;


void searching(int array[],int currentSize, int value){
    for(int i = 0; i < currentSize; i++){
        if(array[i] == value){
            cout << "Yes, we have " << value << " inside the given array at position "<<i+1<< endl;
            break;
        }else{
            cout << "No, we don't have "<< value<<" inside the given array at postion "<< i+1 << endl;
        }
    }
}

int main(){

    int size;
    int choice;
    int userInput;
    cout << "Enter the size of your Array." << endl;
    cin >> size;

    int array[size];

    for(int i = 0; i < size;i++){
        cout << "Enter your values..." << endl;
        cin >> array[i];
    }

    cout << "You want to seach any element? (1 for Yes and 0 for No)" << endl;
    cin >> choice;

   switch (choice)
   {
   case 1:
        cout << "What value you want to search?"<<endl;
        cin >> userInput;
        searching(array,size,userInput);
        break;

    case 0:
        cout << "Nothing to search." << endl;
        break;
   
   default:
        cout << "Enter a Valid input..." << endl;
        break;
   }

    return 0;
}