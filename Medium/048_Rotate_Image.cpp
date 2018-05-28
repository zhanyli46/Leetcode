#include <vector>

using namespace std;

class Solution {
public:
    /* Time: O(n^2), space: O(1) */
    /* Runtime: 4ms */
    void rotate(vector<vector<int>>& matrix)
        rotate(matrix, matrix.size(), 0);
    }

private:
    void rotate(vector<vector<int>>& matrix, int n, int start) {
        if (n < 2) return;
        for (int i = 0; i < n - 1; ++i) {
            int temp = matrix[start][start + i];
            matrix[start][start + i] = matrix[start + n - i - 1][start];
            matrix[start + n - i - 1][start] = matrix[start + n - 1][start + n - i - 1];
            matrix[start + n - 1][start + n - i - 1] = matrix[start + i][start + n - 1];
            matrix[start + i][start + n - 1] = temp;
        }
        rotate(matrix, n - 2, start + 1);
    }
};
