#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int i = 0, j = 1, n = nums.size();
        vector<int> res(n, 0);

        for (int k = 0; k < n; k++) {
            if (nums[k] > 0) {
                res[i] = nums[k];
                i += 2;
            } 
            
            else {
                res[j] = nums[k];
                j += 2;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    Solution solution;
    vector<int> result = solution.rearrangeArray(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
