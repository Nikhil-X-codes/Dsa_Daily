#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(2, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = abs(grid[i][j]) - 1;
                int row = val / n;
                int col = val % n;

                if (grid[row][col] < 0) {
                    res[0] = abs(grid[i][j]);
                } else {
                    grid[row][col] = -grid[row][col];
                }
            }
        }
  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    res[1] = (i * n) + (j + 1);
                    break;
                }
            }
        }
       
        return res;
    }
};

int main() {
 
    vector<vector<int>> grid = {
        {1, 2},
        {3, 3}
    };

    Solution solution;
    vector<int> result = solution.findMissingAndRepeatedValues(grid);

    cout << "Repeated Value: " << result[0] << endl;
    cout << "Missing Value: " << result[1] << endl;

    return 0;
}
