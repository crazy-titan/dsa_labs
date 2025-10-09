#include <iostream>
using namespace std;

int fibonacci(int value){
    if(value == 0){
        return 0;
    }if(value == 1){
        return 1;
    }
    return fibonacci(value - 1) + fibonacci(value - 2);
}

int main(){
    int userInput;
    cout << "Enter the number upto which you want to find the Fibonacci" << endl;
    cin >> userInput;

    int answer = fibonacci(userInput);
    cout << "The fibonacci series of " << userInput<< " is " << answer << endl;
    return 0;
}