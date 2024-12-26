#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
};

int main() {
    
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << sol.searchInsert(nums, target) << endl;

    return 0;
}
