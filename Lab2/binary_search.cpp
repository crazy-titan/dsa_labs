# include <iostream>
using namespace std;


// Assuming the array provided by the user is already sorted...



// binary searching

void binarySearch(int array[],int size,int value){
    int left = 0;
    int right = size - 1;

    int middle = left + ((left + right)/2);

    while(left < right){
        
    }
}



int main(){

    int size,userChoice;
    cout << "Enter Your size of Array" << endl;
    cin >> size;

    int array[size];
    for(int i = 0; i < size; i++){
        cout << "Enter your array elements one by one" << endl;
        cin >> array[i];
    }
    cout << "You want to do Binary Search...(1 for Yes, 0 for No)" << endl;
    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        cout << "What you want to seach...ENTER A VALUE" << endl;
        binarySearch(array,size,value);
        break;
    
    default:
        break;
    }




    return 0;
}