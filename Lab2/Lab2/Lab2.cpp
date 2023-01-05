// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<sstream>
#include<fstream>

using namespace std;

class CSVRow {
public:
    vector<string> data;

    size_t size() const {
        return data.size();
    }
    void readNextRow(istream& str) {
        string line;
        getline(str, line);
        stringstream lineStream(line);
        string cell;
        data.clear();
        while (getline(lineStream, cell, ',')) {
            data.push_back(cell);
        }
    }
};

int main() {
    ifstream myFile;
    string fileName;
    cout << "Enter the file name: ";
    getline(cin, fileName);

    myFile.open(fileName);
    CSVRow csv;
    string str;

    // here Write the code for data printing using loop
    csv.readNextRow(myFile);

    for (int a = 0; a < csv.size(); a++) {
        cout << csv.data[a] << endl;
    }
    return 0;
}
