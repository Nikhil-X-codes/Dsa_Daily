#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        vector<int> res;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] >= maxi) {
                res.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> result = solution.leaders(arr);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
