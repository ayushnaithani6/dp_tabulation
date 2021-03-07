#include <bits/stdc++.h>
using namespace std;

int canSum(int targetSum, vector<int> nums) {
    int tableLen = targetSum+1;
    vector<int> table(tableLen, 0);
    table[0] = 1;
    for(int i=0; i<=targetSum; ++i) {
        for(int j=0; j<nums.size(); ++j) {
            // only update table if make demomition of
            // i is possible if that is possible i+nums[j]
            // is possible where 0 <= j < nums.size()
            if(table[i] && i+nums[j] <= targetSum) {
                table[i+nums[j]] = 1;
            }
        }
    }

    // for(int i=0; i<targetSum; ++i) {
    //     cout << table[i] << " ";
    // }
    return table[targetSum];
}

int main() {
    cout << canSum(7, {5, 3, 4}) << endl;
    cout << canSum(7, {5, 3, 4, 7}) << endl;
    cout << canSum(7, {2, 4}) << endl;
    cout << canSum(8, {2, 3, 5}) << endl;
    cout << canSum(300, {7, 14}) << endl;
    return 0;
}