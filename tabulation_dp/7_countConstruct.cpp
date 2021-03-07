#include <bits/stdc++.h>
using namespace std;

int countConstruct(string target, vector<string> wordBank) {
    int m = target.size()+1;
    vector<int> table(m, 0);
    table[0] = 1;
    for(int i=0; i<m; ++i) {
        if(table[i]) {
            for(string word: wordBank) {
                int len = word.size();
                if(target.substr(i, len) == word) {
                    table[i+len] += table[i];
                }
            }
        }
    }
    return table[m-1];
}

int main() {
    cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}) << endl;                           // 2
    cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;                            // 1 
    cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;            // 0
    cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;          // 4 
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}); // 0
    return 0;
}