#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(int k, int n, vector<vector<int>>& output, vector<int>& res, int sum, int index) {
        if (res.size() == k) {
            if (sum == n) {
                output.push_back(res);
            }
            return;
        }
        for (int i = index; i <= 9; i++) {
            if (sum + i > n) {
                break;
            }
            res.push_back(i);
            solve(k, n, output, res, sum + i, i + 1);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> res;
        solve(k, n, output, res, 0, 1);
        return output;
    }
};

int main() {
    Solution solution;
    int k = 3, n = 7;
    vector<vector<int>> result = solution.combinationSum3(k, n);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
