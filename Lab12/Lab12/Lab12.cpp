// Lab12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

/* A = [0, 1, 1]
       [1, 0, 1]
       [1, 1, 0]

square matrix of dimension m x m
To add another vertex we expand the array to (m+1) x (m+1)
A = [0, 1, 1, 0]
    [1, 0, 1, 0]
    [1, 1, 0, 0]
    [0, 0, 0, 0]*/

class Graph {
public:
    vector<vector<int>> graph; // representation of graph
    vector<int> input_connection; // 

    vector<vector<int>> GetConnections() {
        int x;
        int direction;
        int magnitude;
        vector<vector<int>> input;
        cout << "What vertices do you want to connect to your new vertex? (Enter the vertex number for each vertex you want to connect. Enter -1 to stop." << endl;
        do {
            cout << "Enter a vertex" << endl;
            cin >> x;
            if (x != -1) {
                cout << "Enter Magnitude: " << endl;
                cin >> magnitude;
                cout << "Specify the direction:" << endl << "1. Bi-directional, Enter 1" << endl << "2. " << x << " to new vertex, Enter 2" << endl << "3. New vertex to " << x << " ,Enter 3" << endl;
                cin >> direction;
                input.push_back({ x, direction, magnitude});
            }
        } while (x != -1);
        return input;
    }

    void AddNode() {
        if (!graph.empty()) {
            vector<vector<int>> inp = GetConnections();
            vector<int> newV = {0};
            for (int i = 0; i < graph.size(); i++) {
                graph[i].push_back(0);
                newV.push_back(0);
            }
        }

    }
};

int main()
{
    std::cout << "Hello World!\n";
}

