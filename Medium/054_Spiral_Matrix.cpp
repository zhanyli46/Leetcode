#include <vector>

using namespace std;

class Solution {
public:
    /* Time: O(n^2), space: O(1) */
    /* Runtime: 3ms */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int r = matrix.size(), c = matrix[0].size();
        vector<int> spiral;
        spiralOrder(matrix, spiral, 0, r, c);
        return spiral;
    }

private:
    void spiralOrder(vector<vector<int>>& matrix, vector<int>& spiral, int start, int r, int c) {
        if (r == 0 || c == 0) return;
        if (r == 1) {
            for (int i = 0; i < c; ++i)
                spiral.push_back(matrix[start][start + i]);
            return;
        }
        if (c == 1) {
            for (int i = 0; i < r; ++i)
                spiral.push_back(matrix[start + i][start]);
            return;
        }
        for (int i = 0; i < c; ++i)
            spiral.push_back(matrix[start][start + i]);
        for (int i = 0; i < r - 2; ++i)
            spiral.push_back(matrix[start + i + 1][start + c - 1]);
        for (int i = 0; i < c; ++i)
            spiral.push_back(matrix[start + r - 1][start + c - 1 - i]);
        for (int i = 0; i < r - 2; ++i)
            spiral.push_back(matrix[start + r - 2 - i][start]);
        spiralOrder(matrix, spiral, start + 1, r - 2, c - 2);
    }
};
