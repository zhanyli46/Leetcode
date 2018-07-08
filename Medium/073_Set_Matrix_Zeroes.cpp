#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /* Time: O(n^2), space: O(m + n) */
        /* Runtime: 32ms */
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        int zero_row[m] = {0};
        int zero_col[n] = {0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zero_row[i] = 1;
                    zero_col[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (zero_row[i] || zero_col[j])
                    matrix[i][j] = 0;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        /* Time: O(n^2), space: O(1) */
        /* Runtime: 32ms */
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        int col0 = 1;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};
