#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0;
        int maxsum = 0;

        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        maxsum = lsum;

        for (int i = 0; i < k; i++) {
            lsum -= cardPoints[k - 1 - i];
            rsum += cardPoints[cardPoints.size() - 1 - i];
            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};

int main() {
    Solution s;

    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << "Max score" << s.maxScore(cardPoints, k) << endl;

    return 0;
}
