#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int sum = 0;

        while (i < j) {
            int w = j - i;
            int h = min(height[i], height[j]);
            int area = w * h;
            sum = max(area, sum);

            if (height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(height) << endl; 
}
