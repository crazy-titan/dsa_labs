#include <iostream>
using namespace std;

int factorial(int value){
    if(value == 0){
        return 1;
    }
    return value*factorial(value-1);
}

int main(){

    int userInput;
    cout<< "Enter the value you want to find factorial?"<<endl;
    cin >> userInput;

    int answer = factorial(userInput);
    cout << "The value of Factorial "<< userInput<< " is "<< answer << endl;
    return 0;
}