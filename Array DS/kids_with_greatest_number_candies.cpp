#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxi = *max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxi) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> candies = {2, 3, 5, 1, 3}; 
    int extraCandies = 3;

    vector<bool> result = s.kidsWithCandies(candies, extraCandies);

    for (bool can : result) {
        cout << (can ? "true" : "false") << " ";
    }

    return 0;
}
