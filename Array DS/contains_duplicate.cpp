#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
            if (countMap[num] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 1};
    cout << (solution.containsDuplicate(nums) ? "Contains duplicates" : "No duplicates") << endl;
    return 0;
}
