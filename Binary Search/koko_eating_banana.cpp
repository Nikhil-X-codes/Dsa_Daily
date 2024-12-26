
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool ispossible(vector<int>& piles, int mid, int h) {

        int actualhour = 0;
        for (int p : piles) {
            actualhour += ceil((double)p / mid);
        }
        return actualhour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {

            int mid = l + (r - l) / 2;
            
            if (ispossible(piles, mid, h)) {
                r = mid;
            } 
            
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {

    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}
