#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /* Time: O(mn), space: O(mn) */
        /* Runtime: 0ms */
        int m = obstacleGrid.size();
        int n = m != 0 ? obstacleGrid[0].size() : 0;
        vector<int> v(n, 0);
        vector<vector<int>> grid(m, v);
        grid[m - 1][n - 1] = obstacleGrid[m - 1][n - 1] ? 0 : 1;
        for (int i = n - 2; i >= 0; --i) {
            grid[m - 1][i] = obstacleGrid[m - 1][i] ? 0 : grid[m - 1][i + 1];
        }
        for (int i = m - 2; i >= 0; --i) {
            grid[i][n - 1] = obstacleGrid[i][n - 1] ? 0 : grid[i + 1][n - 1];
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                grid[i][j] = obstacleGrid[i][j] ? 0 : grid[i][j + 1] + grid[i + 1][j];
            }
        }
        return grid[0][0];
    }
};
