#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int index) {
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        solve(nums, ans, output, index + 1);
        output.push_back(nums[index]);
        
        solve(nums, ans, output, index + 1);
        output.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, ans, output, index);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);

    cout << "Subsets: \n";
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
