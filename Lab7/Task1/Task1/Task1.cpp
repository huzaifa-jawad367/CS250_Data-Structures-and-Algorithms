// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class stack {
    char *arr = new char[100];
    int top = 0;
public:
    void push(char x) {
        arr[top++] = x;
    }
    char pop() {
        char res = arr[--top];
        return res;
    }

    bool isEmpty() {
        if (top == 0) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (top == 100) {
            return true;
        }
        return false;
    }

    void Clear() {
        delete [] arr;
    }

    void peek() {
        cout << arr[top - 1] << endl;
    }

    void display() {
        for (int i = 0; i < top; i++) {
            cout << arr[i] << '\t';
        }
    }
};

void CheckExpression(string exp) {
    stack s;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' or exp[i] == '[' or exp[i] == '{') {
            s.push(exp[i]);
        } 
        if (exp[i] == ')' or exp[i] == ']' or exp[i] == '}') {
            // cout << "Iteration" << i << endl;
            char c = s.pop();
            // cout << c << '\t' << exp[i] << '\t' << abs(c - exp[i]) << endl;
            if (abs(c - exp[i]) > 5) {
                cout << "The expression is incorrect!" << endl;
                return;
            }
        }
    }
    if (s.isEmpty()) {
        cout << "The expression is correct!" << endl;
        return;
    }
    cout << "The expression is incorrect!" << endl;
    return;
}

int main()
{
    string expression;

    cout << "enter the expression that you want to check: ";
    getline(cin, expression);
    //cin.ignore();

    CheckExpression(expression);


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
