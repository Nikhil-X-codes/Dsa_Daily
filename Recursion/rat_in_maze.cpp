#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& mat, vector<string>& ans, int r, int c, string path) {
        int m = mat.size();
        int n = mat[0].size();

        if (r == m - 1 && c == n - 1) {
            ans.push_back(path);
            return;
        }

        mat[r][c] = -1;

        if (r + 1 < m && mat[r + 1][c] == 1) {
            solve(mat, ans, r + 1, c, path + 'D');
        }

        if (c - 1 >= 0 && mat[r][c - 1] == 1) {
            solve(mat, ans, r, c - 1, path + 'L');
        }

        if (c + 1 < n && mat[r][c + 1] == 1) {
            solve(mat, ans, r, c + 1, path + 'R');
        }

        if (r - 1 >= 0 && mat[r - 1][c] == 1) {
            solve(mat, ans, r - 1, c, path + 'U');
        }

        mat[r][c] = 1;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> ans;

        int m = mat.size();
        int n = mat[0].size();

        if (mat[0][0] == 0 || mat[m - 1][n - 1] == 0) {
            return ans;
        }

        solve(mat, ans, 0, 0, "");
        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };

    Solution obj;
    vector<string> result = obj.findPath(mat);
    sort(result.begin(), result.end());

    if (result.empty())
        cout << "[]";
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;

    return 0;
}
