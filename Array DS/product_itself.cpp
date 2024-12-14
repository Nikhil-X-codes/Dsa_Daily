#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            output[i] = prefix[i] * suffix[i];
        }

        return output;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    vector<int> result = s.productExceptSelf(nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
