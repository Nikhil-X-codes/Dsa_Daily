#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0, high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int mid_value = matrix[mid / cols][mid % cols]; 
        if (mid_value == target) {
            return true;
        }
        else if (mid_value < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 56;

    if (searchMatrix(matrix, target)) {
        std::cout << "Element found!" << std::endl;
    } else {
        std::cout << "Element not found!" << std::endl;
    }

    return 0;
}
