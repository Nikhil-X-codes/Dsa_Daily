
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();

         for (int i = 0; i < n; i++) {
             for (int j = i + 1; j < n; j++) {
                 swap(matrix[i][j], matrix[j][i]);
             }
         }

         for (int i = 0; i < n; i++) {
             reverse(matrix[i].begin(), matrix[i].end());
         }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    Solution sol;
    sol.rotate(matrix);

    cout << "\nRotated matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}