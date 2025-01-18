#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& output, vector<int>& res, int index, int sum) {
        if (sum == target) {
            output.push_back(res);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            res.push_back(candidates[i]);
            solve(candidates, target, output, res, i + 1, sum + candidates[i]);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, output, res, 0, 0);
        return output;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = solution.combinationSum2(candidates, target);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
