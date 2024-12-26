
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string ans = "";
        string first = strs[0];
        string last = strs[strs.size() - 1];

        for (int i = 0; i < first.size(); i++) {
            if (first[i] != last[i]) break;
            ans += first[i];
        }
        
        return ans;
    }
};

int main() {
    Solution solution;

    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(strs1) << endl;

    return 0;
}
