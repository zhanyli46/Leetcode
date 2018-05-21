#include <vector>

using namespace std;

class Solution {
public:
    /* Heap's Algorithm */
    /* Time: O((e - 1)n!), space: O(1) */
    /* Runtime: 71ms */
    /* Analysis: https://stackoverflow.com/questions/42877789/heaps-algorithm-time-complexity */
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        int n = nums.size();
        perms = generate(nums, n, perms);
        return perms;
    }

    /* Simple Recursion */
    /* Time: O(cn!), c > 1, space: O(n^2) */
    /* Runtime: 14ms */
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return {{}};
        if (nums.size() == 1)
            return {{nums[0]}};
        vector<vector<int>> all_perms;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> next_nums = nums;
            vector<vector<int>> next_perms;
            next_nums.erase(next_nums.begin() + i);
            next_perms = permute(next_nums);
            for (int j = 0; j < next_perms.size(); ++j) {
                next_perms[j].push_back(nums[i]);
                all_perms.push_back(next_perms[j]);
            }
        }
        return all_perms;
    }

private:
    /* Heap's Algorithm */
    vector<vector<int>> generate(vector<int>& nums, int n, vector<vector<int>>& perms) {
        if (n == 1) {
            perms.push_back(nums);
            return perms;
        }
        for (int i = 0; i < n; ++i) {
            generate(nums, size - 1, perms);
            if (n % 2 == 0) {
                swap(nums[i], nums[size - 1]);
            } else {
                swap(nums[0], nums[size - 1]);
            }
        }
        return perms;
    }
};
