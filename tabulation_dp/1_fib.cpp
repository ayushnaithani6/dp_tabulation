#include <bits/stdc++.h>
using namespace std;

long long fib(int n) {
    vector<long long> table(n+1, 0);
    table[1] = 1ll;
    for(int i=0; i<=n; ++i) {
        // also check for bounds
        // 0, 1, 2, 3, 4, 5, 6 ---> n = 6, table size = 7
        // to check bounds
        if(i+1 <= n) table[i+1] += table[i];
        if(i+2 <= n) table[i+2] += table[i];
    }

    return table[n];
}

int main() {
    cout << fib(6) << endl;
    cout << fib(7) << endl;
    cout << fib(8) << endl;
    cout << fib(50) << endl;
    return 0;
}