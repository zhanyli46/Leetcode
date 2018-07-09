#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /* Time: O(log(mn)), space: O(1) */
        /* Runtime: 8ms */
        int m = matrix.size();
        int n = m > 0 ? matrix[0].size() : 0;
        int l = 0, r = m * n - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] < target)
                l = mid + 1;
            else if (matrix[row][col] > target)
                r = mid - 1;
            else
                return true;
        }
        return false;
    }
};
