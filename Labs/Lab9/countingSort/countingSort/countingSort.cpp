// countingSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

vector<vector<long>> EmptyBucket(vector<vector<long>> B) {
    for (long i = 0; i < B.size(); i++) {
        for (long j = 0; j < B[i].size(); j++) {
            B[i].pop_back();
        }
    }
    return B;
}
/*
void RadixSort(long data[], const long n) {
    vector<vector<long>> Bucket;
    vector<long> section1, section2, section3, section4, section5, section6, section7, section8, section9, section0;
    Bucket.push_back(section0);
    Bucket.push_back(section1);
    Bucket.push_back(section2);
    Bucket.push_back(section3);
    Bucket.push_back(section4);
    Bucket.push_back(section5);
    Bucket.push_back(section6);
    Bucket.push_back(section7);
    Bucket.push_back(section8);
    Bucket.push_back(section9);

    // Least significant digit Bucket
    for (long i = 0; i < n; i++) {
        Bucket[data[n] % 10].push_back(data[n]);
    }
    long count = 0;
    for (int i = 0; i < 10; i++) {
        for (long j = 0; j < Bucket[i].size(); i++) {
            data[count++] = Bucket[i][j];
        }
    }
    Bucket = EmptyBucket(Bucket);

    // Middle digit bucket
    for (long i = 0; i < n; i++) {
        Bucket[(data[n] % 100)/10].push_back(data[n]);
    }
    long count = 0;
    for (int i = 0; i < 10; i++) {
        for (long j = 0; j < Bucket[i].size(); i++) {
            data[count++] = Bucket[i][j];
        }
    }
    Bucket = EmptyBucket(Bucket);

    // Most significant digit bucket
    for (long i = 0; i < n; i++) {
        Bucket[data[n] / 100].push_back(data[n]);
    }
    long count = 0;
    for (int i = 0; i < 10; i++) {
        for (long j = 0; j < Bucket[i].size(); i++) {
            data[count++] = Bucket[i][j];
        }
    }
}
*/

void countingSort(long data[], const long n) {
    long i;
    long largest = data[0];
    long* tmp = new long[n];
    for (i = 1; i < n; i++) {
        if (largest < data[i]) {
            largest = data[i];
        }
    }
    unsigned long* count = new unsigned long[largest + 1];
    for (int i = 0; i <= largest; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[data[i]]++;
    }
    for (int i = 1; i <= largest; i++) {
        count[i] = count[i - 1] + count[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        tmp[count[data[i]]] = data[i];
        count[data[i]]--;
    }
    for (int i = 0; i < n; i++) {
        data[i] = tmp[i];
    }
}

void checkSort(long data[], const long n, long sorted[]) {
    srand(time(0));
    long* tmp = new long[n];
    sort(tmp, tmp + n);
    for (int i = 0; i < n; i++) {
        if (tmp[i] == data[i]) {
            cout << "Wrong!" << endl;
            break;
        }
    }
}


long *CreateArray(const long n) {
    long* arr = new long[n];
    srand(time(0));
    for (long i = 0; i < n; i++) {
        arr[i] = (rand() % 100) + 1;
    }
    return arr;
}

int power(int n, int e) {
    int res = n;
    for (int i = 0; i < (e - 1); i++) {
        res = res * n;
    }
    return res;
}

void CompareRunTime() {
    for (int i = 1; i <= 5; i++) {
        int len = 10 * power(10, i);
        long* array = CreateArray(len);
        time_t start, end;
        time(&start);
        
        countingSort(array, len);

        time(&end);
        double time_taken = double(end - start);
        cout << "Time taken by program is : " << time_taken;
        cout << " sec " << endl;
    }
}


int main()
{
    // Task 1
    long* array = CreateArray(30);
    for (int i = 0; i < 30; i++) {
        cout << array[i] << '\t';
    }
    cout << endl;
    countingSort(array, 30);

     // Task 2
    CompareRunTime();

    return 0;
}
