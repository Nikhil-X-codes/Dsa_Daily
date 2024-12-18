#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxisum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxisum = max(sum, maxisum);

            if (sum < 0)
                sum = 0;
        }
        return maxisum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = solution.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
