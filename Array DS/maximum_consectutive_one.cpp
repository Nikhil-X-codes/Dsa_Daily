#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            count = (nums[i] == 1) ? count + 1 : 0;
            maxi = max(count, maxi);
        }
        return maxi;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int result = s.findMaxConsecutiveOnes(nums);
    cout << "Maximum consecutive ones: " << result << endl;
    return 0;
}
