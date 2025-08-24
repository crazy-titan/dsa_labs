// Write a program for matrix multiplication of size 3x3.

#include <iostream>
using namespace std;

int main(){

    int rowsA,colsA,rowsB,colsB;
    
    cout << "Enter No. of rows for your Matrix A..."<<endl;
    cin >> rowsA;
    cout << "Enter No. of cols for your Matrix A..."<<endl;
    cin >> colsA;
    cout << "Enter Your elements of Matrix A." << endl;
    
    int arrayA[rowsA][colsA];

    // building matrix A
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsA; j++){
            cin >> arrayA[i][j];
        }
    }
    

    cout << "Enter No. of rows for your Matrix B..."<<endl;
    cin >> rowsB;

    if(rowsB != colsA){
        cout << "Invalid Inputs."<< endl;
        //
    }

    cout << "Enter No. of cols for your Matrix B..."<<endl;
    cin >> colsB;
    cout << "Enter Your elements of Matrix B." << endl;

    int arrayB[rowsB][colsB];

    // building matrix B
    for(int i = 0; i < rowsB; i++){
        for(int j = 0; j < colsB; j++){
            cin >> arrayB[i][j];
        }
    }
    
    
    int arrayC[rowsA][colsB];

    for(int i = 0 ; i < rowsA; i++){
        for(int j = 0; j < colsB; j++){
            arrayC[i][j] = 0;
            for(int k = 0; k < colsA; k++){
                // arrayC[i][j] = arrayC[i][j] + (arrayA[i][k] * arrayB[k][j]) ;
                arrayC[i][j] += (arrayA[i][k] * arrayB[k][j]) ;
            }
        }
    }
    cout << "Final matrix after multiplying..."<<endl;
    for(int i = 0; i < rowsA; i++){
        for(int j = 0; j < colsB; j++){
            cout << arrayC[i][j]<< "\t";   
        }
        cout << endl;
    }
    return 0;
}