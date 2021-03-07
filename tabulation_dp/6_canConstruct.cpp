#include <bits/stdc++.h>
using namespace std;

int canConstruct(string target, vector<string> wordBank) {
    int n = target.size()+1;
    vector<int> table(n, 0);
    table[0] = 1;
    for(int i=0; i<n; ++i) {
        if(table[i]) {
            for(string word: wordBank) {
                int len = word.size();
                if(target.substr(i, len) == word) {
                    table[i+len] = 1;
                }
            }
        }
    }
    return table[n-1];
}

int main() {
    cout << canConstruct("abcdef", {"ab", "abc", "cd", "ef", "abcd"}) << endl;                            // 1 (1 is true)
    cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;            // 0 (0 is false)
    cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;          // 1 
    cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}); // 0
    return 0;
}