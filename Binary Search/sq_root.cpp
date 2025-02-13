#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int start = 1, end = x;
        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (mid == x / mid) {
                return mid;
            } 
            
            else if (mid < x / mid) {
                start = mid + 1;
            } 
            
            else {
                end = mid - 1;
            }
        }
        return end;
    }
};

int main() {
    Solution sol;
    int x = 8;
    cout << sol.mySqrt(x) << endl;

    return 0;
}
