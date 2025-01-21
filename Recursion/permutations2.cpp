#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& nums, int index) {
        if (index >= nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> seen;

        for (int i = index; i < nums.size(); i++) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);

            swap(nums[index], nums[i]);
            solve(res, nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int index = 0;
        solve(res, nums, index);
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2,1};
    vector<vector<int>> result = solution.permuteUnique(nums);

    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
