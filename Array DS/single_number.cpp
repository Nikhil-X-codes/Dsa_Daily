#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = s.singleNumber(nums);
    cout << "The single number is: " << result << endl;
    return 0;
}
