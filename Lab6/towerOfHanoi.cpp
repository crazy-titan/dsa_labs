#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char helper, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, helper);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, helper, source, destination);
}

int main() {
    int userInput;
    cout << "Enter number of disks: ";
    cin >> userInput;

    towerOfHanoi(userInput, 'A', 'B', 'C');
    return 0;
}
