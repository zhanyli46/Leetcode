#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Time: O(n^3), space: O(n)
        // Runtime: 4ms
        int n = nums.size();
        vector<vector<int>> subsets;
        vector<int> cur_comb;
        subsets.push_back(cur_comb);
        for (int i = 1; i <= n; ++i)
            combination(subsets, cur_comb, nums, n, i, 0);
        return subsets;
    }

private:
    void combination(vector<vector<int>> &combs, vector<int> &cur_comb, vector<int>& nums, int n, int k, int start) {
        if (k == 0) {
            combs.push_back(cur_comb);
            return;
        }
        for (int i = start; i < n; ++i) {
            cur_comb.push_back(nums[i]);
            combination(combs, cur_comb, nums, n, k - 1, i + 1);
            cur_comb.pop_back();
        }
    }
};
