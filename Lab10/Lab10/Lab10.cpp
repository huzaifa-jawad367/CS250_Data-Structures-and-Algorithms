// Lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Task3 {
public:
    int num;
    string s;
};

vector<int> Count(vector<int> arr) {
    vector<int> freq;
    for (int i = 0; i < 100; i++) {
        freq.push_back(0);
    }
    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }
    return freq;
}

vector<int> Sort(vector<int> arr, vector<int> freq) {
    for (int i = 1; i < freq.size(); i++) {
        freq[i] = freq[i] + freq[i - 1];
    }
    vector<int> sortedArr;
    for (int i = 0; i < arr.size(); i++) {
        sortedArr.push_back(0);
    }
    for (int i = arr.size()-1; i >= 0; i--) {
        sortedArr[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }
    return sortedArr;
}

void sortStr(Task3* collection, int n) {
    int* freq = new int[100];
    Task3* sorted = new Task3[n];
    for (int i = 0; i < 100; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        freq[collection[i].num]++;
    }
    for (int i = 1; i < 100; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        sorted[freq[collection[i].num]-1] = collection[i];
        freq[collection[i].num]--;
    }
    for (int i = 0; i < n; i++) {
        cout << sorted[i].s << endl;
    }
}

int main()
{
    /*Task3* A = new Task3[5];
    A[0].num = 10;
    A[0].s = "aaa";
    A[1].num = 8;
    A[1].s = "bbb";
    A[2].num = 16;
    A[2].s = "ccc";
    A[3].num = 5;
    A[3].s = "ddd";
    A[4].num = 2;
    A[4].s = "eee";
    
    sortStr(A, 5);*/

    srand(time(0));
    vector<int> array;
    for (int i = 0; i < 100; i++) {
        array.push_back(rand() % 100);
    }
    // Prints the frequency array
    cout << "Frequency Array:" << endl;
    vector<int> f = Count(array);
    for (int i = 0; i < f.size(); i++) {
        cout << f[i] << ' ';
    }
    cout << endl << endl << "Sorted Array: " << endl << endl;
    // Prints the sorted array
    vector<int> s = Sort(array, f);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << ' ';
    }

    return 0;
}
