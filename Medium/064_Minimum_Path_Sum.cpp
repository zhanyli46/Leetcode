#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /* !! Parameter 'grid' is modified !!*/
        /* Time: O(mn), space: O(1) */
        /* Runtime: 4ms */
        int m = grid.size();
        int n = m > 0 ? grid[0].size() : 0;
        for (int i = n - 2; i >= 0; --i) {
            grid[m - 1][i] += grid[m - 1][i + 1];
        }
        for (int i = m - 2; i >= 0; --i) {
            grid[i][n - 1] += grid[i + 1][n - 1];
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                grid[i][j] += min(grid[i][j + 1], grid[i + 1][j]);
            }
        }
        return grid[0][0];
    }
};
