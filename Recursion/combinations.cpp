#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& output, vector<int>& res, int index, int n, int k) {
        if (res.size() == k) {
            output.push_back(res);
            return;
        }

        for (int i = index; i <= n; i++) {
            res.push_back(i);
            solve(output, res, i + 1, n, k);
            res.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        vector<int> res;
        int index = 1;

        solve(output, res, index, n, k);
        return output;
    }
};

int main() {
    Solution solution;
    int n = 4, k = 2;
    vector<vector<int>> result = solution.combine(n, k);

    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
