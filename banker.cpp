// Wil Nahra
// 11/14/2025

#include<iostream>
#include<fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in;
    in.open("input.txt");
    if(!in) {
        cerr << "File not found" << endl;
        exit(1);
    }

    int n = 5;
    int m = 3;

    vector<int> available(m);

    // Read available
    for(int i = 0; i < m; ++i) {
        in >> available[i];
    }

    vector<vector<int>> max(n, vector<int>(m));
    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));

    // Read allocation matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            in >> allocation[i][j];
        }
    }

    // Read max matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            in >> max[i][j];
        }
    }

    // Calculate need = max - allocation
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    //Safe Algorithm
    vector<int> work = available;
    vector<bool> finish(n, false);
    vector<int> safeSequence;
    
    for(int k = 0; k < n; ++k) {
        bool found = false;
        for(int i = 0; i < n; ++i) {
            if(!finish[i]){
                bool safe = true;
                for(int j = 0; j < m; ++j){
                    if(need[i][j] > work[j]) {
                        safe = false;
                        break;
                    }
                }
    
                if(safe) {
                    for(int j = 0; j < m; ++j) {
                        work[j] += allocation[i][j];
                    }
    
                    finish[i] = true;
                    safeSequence.push_back(i);
                    found = true;
                }
            }
        }
        if (!found) break; // exit if no safe process was found this round
    }
    
    bool safe = true;
    for(int i = 0; i < n; ++i) {
        if(!finish[i]) {
            safe = false;
            cout << "Not in Safe State" << endl;
            break;
        } 
    }
    
    if(safe) {
        cout << "The system is in Safe State \nThe Safe Sequence is: \n";
        for(size_t i = 0; i < safeSequence.size(); ++i) {
            cout << "P" << safeSequence[i];
            if (i != safeSequence.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
    

    in.close();
    return 0;
}