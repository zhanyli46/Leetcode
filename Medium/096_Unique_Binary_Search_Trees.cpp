class Solution {
public:
    int numTrees(int n) {
        // Time: O(n), space: O(n)
        // Runtime: 0ms
        int M[n + 1] = {0};
        M[0] = M[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j)
                M[i] += M[j - 1] * M[i - j];
        }
        return M[n];
    }
};
