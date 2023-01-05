// Lab10_towerofhanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

void MoveDisk(stack<int> ) {

}

void MovetowerOfHanoi(int disk, stack<int> dest, stack<int> spare, stack<int> src) {
    if (disk == 1) {
        MoveDisk(src, dest);
    }
}

int main()
{
    stack<int> destination;
    stack<int> spare;
    stack<int> source;
    int disks;
    cout << "Enter the number of disks: ";
    cin >> disks;

    for (int i = disks; i > 0; i--) {
        source.push(i);
    }

    cout << "Towers:" << endl << '\t';
    cout << "Tower 1" << '\t' << "Tower 2" << '\t' << "Tower 3";

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
