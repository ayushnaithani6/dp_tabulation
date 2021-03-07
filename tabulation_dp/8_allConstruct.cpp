#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> allConstruct(string target, vector<string> wordBank) {
    int m = target.size()+1;
    vector<vector<vector<string>>> table(m);
    for(int i=0; i<m; ++i) {
        table[i] = {};
    }
    table[0].push_back({});

    for(int i=0; i<m; ++i) {
        if(table[i].size()) {
            for(string word: wordBank) {
                int len = word.size();
                if(target.substr(i, len) == word) {
                    for(int j=0; j<table[i].size(); ++j) {
                        vector<string> newCombination = table[i][j];
                        newCombination.push_back(word);
                        table[i+len].push_back(newCombination);
                    }
                }
            }
        }
    }
    return table[m-1];
}

void printAns(vector<vector<string>> allCombination) {
    cout << "[" << endl;
    for(int i=0; i<allCombination.size(); ++i) {
        cout << "  [";
        for(int j=0; j<allCombination[i].size(); ++j) {
            cout << allCombination[i][j] << "  ";
        }
        cout << "]";
        cout << endl;
    }
    cout << "]";
    cout << endl << endl << endl;
}

int main() {
    printAns(allConstruct("purple", {"purp", "p", "ur", "le", "purpl"}));  
        // [
        //     [purp, le]
        //     [p, ur, p, le]
        // ]       

    printAns(allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"})); 
        // [
        //     [abc, def]
        // ]

    printAns(allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}));    
        //     []


    printAns(allConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}));        
        // [
        //     [enter, a, p, ot, ent, p, ot]
        //     [enter, a, p, ot, ent, p, o, t]
        //     [enter, a, p, o, t, ent, p, ot]
        //     [enter, a, p, o, t, ent, p, o, t]
        // ]

    printAns(allConstruct("eeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"}));
        //     []
    
    return 0;
}