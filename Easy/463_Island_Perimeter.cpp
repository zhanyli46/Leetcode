#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // Time: O(n^2), space: O(1)
        // Runtime: 96ms
        int perim = 0;
        int m = grid.size();
        int n = m > 0 ? grid[0].size() : 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    perim += 4;
                    if (i != 0 && grid[i - 1][j] == 1)
                        perim -= 2;
                    if (j != 0 && grid[i][j - 1] == 1)
                        perim -= 2;
                }
            }
        }
        return perim;
    }
};
