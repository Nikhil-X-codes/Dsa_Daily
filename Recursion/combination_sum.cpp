#include <iostream>
#include <vector>
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
            res.push_back(candidates[i]);
            solve(candidates, target, output, res, i, sum + candidates[i]);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> res;
        int index = 0;
        int sum = 0;
        solve(candidates, target, output, res, index, sum);
        return output;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = solution.combinationSum(candidates, target);
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
