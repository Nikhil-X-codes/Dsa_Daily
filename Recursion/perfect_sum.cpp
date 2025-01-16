#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void solve(vector<int>& arr, int target, int sum, int index, int &count) {
        if(index >= arr.size()){
            if(sum == target){
              count++;
            }
            return;
        }
        
        solve(arr, target, sum + arr[index], index + 1, count);
        solve(arr, target, sum, index + 1, count);
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int count = 0;
        int sum = 0;
        int index = 0;
        solve(arr, target, sum, index, count);
        return count;
    }
};

int main() {
    vector<int> arr = {1, 2, 3};  
    int target = 3;  
    
    Solution solution;
    cout << solution.perfectSum(arr, target) << endl;

    return 0;
}
