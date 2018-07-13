#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Time: O(2^n log 2^n), space: O(1)
        // Runtime: 4ms
        vector<vector<int>> subsets;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        for (int k = 0; k <= nums.size(); ++k)
            combination(subsets, cur, nums, 0, k);
        int p = 0, i = 0, n = subsets.size();
        sort(subsets.begin(), subsets.end());
        while (i < n) {
            subsets[p++] = subsets[i++];
            while (i < n && subsets[i - 1] == subsets[i]) ++i;
        }
        subsets.resize(p);
        return subsets;

    }
private:
    void combination(vector<vector<int>> &combs, vector<int> &cur, vector<int> &nums, int start, int k) {
        if (k == 0) {
            combs.push_back(cur);
            return;
        }
        if (start >= nums.size()) return;
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            combination(combs, cur, nums, i + 1, k - 1);
            cur.pop_back();
        }
    }
};
