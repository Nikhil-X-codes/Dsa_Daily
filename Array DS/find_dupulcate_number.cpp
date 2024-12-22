#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = abs(nums[i]);
            if (nums[num] < 0) {
                return num;
            }
            nums[num] = -nums[num];
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {3, 1, 3, 4, 2};
    Solution solution;
    int duplicate = solution.findDuplicate(nums);
    cout << "Duplicate number: " << duplicate << endl;
    return 0;
}
