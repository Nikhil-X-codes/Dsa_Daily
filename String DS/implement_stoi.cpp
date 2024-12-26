
#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) return 0;

        int sign = 1;
        long ans = 0;
        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            if (sign * ans < INT_MIN) return INT_MIN;
            if (sign * ans > INT_MAX) return INT_MAX;
            i++;
        }

        return sign * ans;
    }
};

int main() {
    Solution solution;
    string input = " -42"; 

    int result = solution.myAtoi(input);

    cout << "Converted integer: " << result << endl;

    return 0;
}
