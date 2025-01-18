#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& output, vector<int>& res, int index) {
        output.push_back(res);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;

            res.push_back(nums[i]);
            solve(nums, output, res, i + 1);
            res.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> res;
        int index = 0;

        sort(nums.begin(), nums.end());
        solve(nums, output, res, index);

        return output;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2}; 

    vector<vector<int>> subsets = solution.subsetsWithDup(nums);

    cout << "Subsets with duplicates handled are: \n";
    for (const auto& subset : subsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
