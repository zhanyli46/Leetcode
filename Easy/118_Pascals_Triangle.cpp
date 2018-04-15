#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /* DP */
        /* Time: O(n^2), space: O(n^2) */
        /* Runtime: 3ms */
        vector<vector<int>> v;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++)
                row.push_back(binomialCoef(i, j));
            v.push_back(row);
        }
        return v;
    }

private:
    unsigned binomialCoef(int n, int k) {
        int M[n+1][k+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= min(i, k); j++) {
                if (j == 0 || j == i)
                    M[i][j] = 1;
                else
                    M[i][j] = M[i-1][j-1] + M[i-1][j];
            }
        }
        return M[n][k];
    }
};
