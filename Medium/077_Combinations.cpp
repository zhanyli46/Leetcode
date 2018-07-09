#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        /* Time: O(n^2), space: O(n) */
        /* Runtime: 48ms */
        vector<vector<int>> combs;
        vector<int> cur_comb;
        combine(combs, cur_comb, n, k, 1);
        return combs;
    }

private:
    void combine(vector<vector<int>> &combs, vector<int> &cur_comb, int n, int k, int start) {
        if (k == 0) {
            combs.push_back(cur_comb);
            return;
        }
        if (start > n) return;
        for (int i = start; i <= n; ++i) {
            cur_comb.push_back(i);
            combine(combs, cur_comb, n, k - 1, i + 1);
            cur_comb.pop_back();
        }
    }
};
