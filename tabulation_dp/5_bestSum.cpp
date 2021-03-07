#include <bits/stdc++.h>
using namespace std;

vector<int> bestSum(int, vector<int>);
void printSum(vector<int>);

int main() {
    printSum(bestSum(8, {2, 3, 5}));
    printSum(bestSum(7, {5, 3, 4, 7}));
    printSum(bestSum(8, {1, 4, 5}));
    printSum(bestSum(100, {1, 2, 5, 25}));
    printSum(bestSum(100, {25, 1, 50, 2}));
    printSum(bestSum(17, {2, 8}));
    return 0;
}

vector<int> bestSum(int targetSum, vector<int> nums) {
    int n = targetSum+1;
    vector<vector<int>> table(n, vector<int>(1, INT_MIN));
    table[0] = {};
    for(int i=0; i<n; ++i) {
        if(table[i] != (vector<int>){INT_MIN}) {
            for(int j=0; j<nums.size(); ++j) {
                // check bounds
                if(i+nums[j] < n) {
                    vector<int> currentCombination = table[i+nums[j]];
                    vector<int> validCombination = table[i];
                    validCombination.push_back(nums[j]);
                    if(currentCombination == (vector<int>){INT_MIN} || currentCombination.size() > validCombination.size()) {
                        table[i+nums[j]] = validCombination;
                    }
                }
            }
        }
    }
    return table[targetSum];
}

void printSum(vector<int> seq) {
    if(seq == (vector<int>){INT_MIN}) {
        cout << "NONE";
    }
    else {
        cout << "[ ";
        for(int i=0; i<seq.size()-1; ++i) {
            cout << seq[i] << ", ";
        }
        cout << seq[seq.size()-1] << " ]";
    }
    cout << endl;
}