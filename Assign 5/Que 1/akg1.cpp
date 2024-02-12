#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& matrix, int row, int col, int rows, int cols) {
    if (row < 0 || col < 0 || row >= rows || col >= cols || matrix[row][col] == 0)
        return 0;

    matrix[row][col] = 0;

    int size = 1;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            size += dfs(matrix, row + i, col + j, rows, cols);
        }
    }
    return size;
}

int largestRegionSize(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxRegionSize = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                int regionSize = dfs(matrix, i, j, rows, cols);
                maxRegionSize = max(maxRegionSize, regionSize);
            }
        }
    }
    return maxRegionSize;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {1, 0, 0, 0, 1}
    };

    int largestSize = largestRegionSize(matrix);
    cout << "Size of the largest region: " << largestSize << endl;

    return 0;
}

// time complexity: O(rows * cols)
// space complexity: O(rows * cols)