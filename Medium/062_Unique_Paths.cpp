#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        /* Time: O(mn), space: O(mn) */
        /* Runtime: 0ms */
        vector<int> v(n, 1);
        vector<vector<int>> grid(m, v);
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                grid[i][j] = grid[i][j + 1] + grid[i + 1][j];
            }
        }
        return grid[0][0];
    }
};
