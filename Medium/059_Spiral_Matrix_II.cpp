#include <vector>

using namespace std;

class Solution {
public:
    /* Time: O(n^2), space: O(1) */
    /* Runtime: 5ms */
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n, 0);
        vector<vector<int>> matrix(n, row);
        fillMatrix(matrix, n, 0, 1);
        return matrix;
    }

private:
    void fillMatrix(vector<vector<int>> &matrix, int n, int start, int cur) {
        if (n <= 0) return;
        for (int i = 0; i < n; ++i)
            matrix[start][start + i] = cur++;
        if (n == 1) return;
        for (int i = 0; i < n - 2; ++i)
            matrix[start + i + 1][start + n - 1] = cur++;
        for (int i = 0; i < n; ++i)
            matrix[start + n - 1][start + n - 1 - i] = cur++;
        for (int i = 0; i < n - 2; ++i)
            matrix[start + n - 1 - i - 1][start] = cur++;
        fillMatrix(matrix, n - 2, start + 1, cur);
    }
};
