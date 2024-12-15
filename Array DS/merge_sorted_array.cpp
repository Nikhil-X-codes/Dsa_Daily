#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged;

        int i = 0, j = 0;
        
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            merged.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            merged.push_back(nums2[j]);
            j++;
        }

        for (int k = 0; k < merged.size(); k++) {
            nums1[k] = merged[k];
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    for (int num : nums1) {
        cout << num << " ";
    }

    return 0;
}
