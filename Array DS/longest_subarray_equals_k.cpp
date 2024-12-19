#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lenOfLongestSubarr(vector<int>& arr, int k) {
    int prefixsum = 0;
    int max_length = 0;
    unordered_map<int, int> mp;

    mp[0] = -1;

    for (int i = 0; i < arr.size(); i++) {
        prefixsum += arr[i];

        if (mp.find(prefixsum - k) != mp.end()) {
            max_length = max(max_length, i - mp[prefixsum - k]);
        }

        if (mp.find(prefixsum) == mp.end()) {
            mp[prefixsum] = i;
        }
    }

    return max_length;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << lenOfLongestSubarr(arr, k) << endl;
    return 0;
}
