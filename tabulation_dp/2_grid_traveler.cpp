#include <bits/stdc++.h>
using namespace std;

long long gridTraveler(int m, int n) {
    // 2-D matrix in c++ initilizing with 0
    vector<vector<long long>> table(m+1, vector<long long>(n+1, 0));

    table[1][1] = 1;
    for(int i=0; i<=m; ++i) {
        for(int j=0; j<=n; ++j) {
            int current = table[i][j];
            if(i+1 <= m) table[i+1][j] += current;
            if(j+1 <= n) table[i][j+1] += current;
        }
    }

    // checking table for visualization
    // for(int i=0; i<=m; ++i) {
    //     for(int j=0; j<=n; ++j) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // } 
    return table[m][n];
}

int main() {
    cout << gridTraveler(1, 1) << endl;
    cout << gridTraveler(2, 3) << endl;
    cout << gridTraveler(3, 2) << endl;
    cout << gridTraveler(3, 3) << endl;
    cout << gridTraveler(18, 18);
    return 0;
}