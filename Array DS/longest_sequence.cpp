#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            
            if (s.find(nums[i] - 1) != s.end()) {
                continue;
            } 
            
            else {
                int count = 0;
                int current = nums[i];

                while (s.find(current) != s.end()) {
                    count++;
                    current++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};

int main() {
   
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    Solution solution;
    int result = solution.longestConsecutive(nums);

    cout << "The length of the longest consecutive sequence is: " << result << endl;

    return 0;
}
