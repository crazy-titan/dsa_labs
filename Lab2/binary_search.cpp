#include <iostream>
using namespace std;

int BinarySearch(const int numbers[], int arraySize, int targetValue) {
    int leftIndex = 0;
    int rightIndex = arraySize - 1;

    while (leftIndex <= rightIndex) {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

        if (numbers[midIndex] == targetValue) {
            return midIndex; 
        } else if (numbers[midIndex] < targetValue) {
            leftIndex = midIndex + 1; 
        } else {
            rightIndex = midIndex - 1; 
        }
    }

    return -1; 
}

int main() {
    int sortedNumbers[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int numberOfElements = sizeof(sortedNumbers) / sizeof(sortedNumbers[0]);
    int numberToFind = 23;

    int resultIndex = BinarySearch(sortedNumbers, numberOfElements, numberToFind);

    if (resultIndex != -1) {
        cout << "The number " << numberToFind << " was found at index " << resultIndex << "." << endl;
    } else {
        cout << "The number " << numberToFind << " was not found in the array." << endl;
    }

    return 0;
}
