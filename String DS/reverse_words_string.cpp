#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int l = 0, r = 0;
        int i = 0;

        while (i < n) {

            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }

            if (l < r) {
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                l = ++r;
            }
            
            i++;
        }

        s = s.substr(0, r - 1);
        return s;
    }
};

int main() {
    Solution solution;
    string s = "  the sky is blue  ";
    cout << solution.reverseWords(s) << endl;
    return 0;
}
