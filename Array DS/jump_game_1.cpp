#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReachable) return false;
            maxReachable = max(maxReachable, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << (solution.canJump(nums) ? "Can reach the end" : "Cannot reach the end") << endl;
    return 0;
}
