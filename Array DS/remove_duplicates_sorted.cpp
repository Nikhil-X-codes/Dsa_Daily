#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;

        while (j < nums.size()) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }

        return i + 1;
    }
};

int main() {
    
    vector<int> nums = {1, 1, 2, 2, 3, 4, 5};
    Solution s;
    int res = s.removeDuplicates(nums);

    for (int i = 0; i < res; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
