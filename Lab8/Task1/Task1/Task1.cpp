// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

void merge(int Arr[],int n1,int mid,int n2) {
    int a = n1;
    int b = mid;
    int c = n1;
    int* B = new int[n2];
    while (a <= mid && b <= n2) {
        if (Arr[a] < Arr[b]) {
            B[c++] = Arr[a++];
        }
        else {
            B[c++] = Arr[b++];
        }
    }
    while (a < mid) {
        B[c++] = Arr[a++];
    }
    while (b < n2) {
        B[c++] = Arr[b++];
    }
    for (int i = 0; i < n2; i++) {
        cout << B[i] << '\t';
        Arr[i] = B[i];
    }
    cout << endl;

}

void mergeSort(int Arr[], int first, int last) {
    if (first < last) {
        int midpoint = floor((first + last) / 2);
        mergeSort(Arr, first, midpoint);
        mergeSort(Arr, midpoint + 1, last);
        merge(Arr, first, midpoint + 1, last);
    }
}

int main()
{
    int* array = new int[12];
    
    for (int j = 0; j < 12; j++) {
        array[j] = 20 -j;
    }
    for (int j = 0; j < 12; j++) {
        cout << array[j] << '\t';
    }
    cout << endl;
    mergeSort(array, 0, 12);
    for (int j = 0; j < 12; j++) {
        cout << array[j] << '\t';
    }
}
