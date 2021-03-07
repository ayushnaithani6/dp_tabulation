#include <bits/stdc++.h>
using namespace std;

vector<int> howSum(int targetSum, vector<int> nums) {
    vector<vector<int>> table(targetSum+1, vector<int>(1, {INT_MIN}));

    table[0] = {};
    for(int i=0; i<=targetSum; ++i) {
        if(table[i] != (vector<int>){INT_MIN}) {
            for(int j=0; j<nums.size(); ++j) {
                if(i+nums[j] <= targetSum) {
                    // copying array atmost targetSum
                    table[i+nums[j]] = table[i];
                    table[i+nums[j]].push_back(nums[j]);
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

int main() {
    printSum(howSum(7, {2, 3}));
    printSum(howSum(7, {5, 3, 4, 7}));
    printSum(howSum(7, {2, 4}));
    printSum(howSum(8, {2, 3, 5}));
    printSum(howSum(300, {7, 14}));
    return 0;
}