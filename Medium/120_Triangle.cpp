#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Time: O(n^2), space: O(n)
        // Runtime: 12ms
        if (triangle.empty())
            return 0;
        int n = triangle.size();
        vector<int> minSum(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                if (j == 0)
                    minSum[j] += triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    minSum[j] = minSum[j - 1] + triangle[i][j];
                else
                    minSum[j] = min(minSum[j - 1], minSum[j]) + triangle[i][j];
            }
        }
        return *min_element(minSum.begin(), minSum.end());
    }
};
