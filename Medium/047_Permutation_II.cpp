#include <vector>

using namespace std;

class Solution {
public:
    /* Simple Recursion and Remove Duplicate */
    /* Time: ~O(n!), space: O(n^2) */
    /* Runtime: 238ms */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty())
            return {{}};
        if (nums.size() == 1)
            return {{nums[0]}};
        vector<vector<int>> all_perms;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> next_nums = nums;
            vector<vector<int>> next_perms;
            next_nums.erase(next_nums.begin() + i);
            next_perms = permuteUnique(next_nums);
            for (int j = 0; j < next_perms.size(); ++j) {
                next_perms[j].push_back(nums[i]);
                all_perms.push_back(next_perms[j]);
            }
        }
        sort(all_perms.begin(), all_perms.end());
        int i = 1, j = 1;
        while (j < all_perms.size()) {
            if (all_perms[j - 1] != all_perms[j])
                all_perms[i++] = all_perms[j++];
            else
                ++j;
        }
        all_perms.erase(all_perms.begin() + i, all_perms.end());
        return all_perms;
    }

    /* Generate every permutation using next_permutation (Leetcode 031) */
    /* Time: O(n^2), space: O(1) */
    /* Runtime: 26ms */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> all_perms;
        sort(nums.begin(), nums.end());
        all_perms.push_back(nums);
        while (next_permutation(nums))
            all_perms.push_back(nums);
        return all_perms;
    }

private:
    bool next_permutation(vector<int>& nums) {
        vector<int>::iterator first = nums.begin(), last = nums.end();
        vector<int>::iterator i = last;
        if (first == last || first == --i) return false;
        while (true) {
            vector<int>::iterator ip1 = i;
            if (*--i < *ip1) {
                vector<int>::iterator j = last;
                while (*i >= *--j)
                    ;
                swap(*i, *j);
                reverse(ip1, last);
                return true;
            }
            if (i == first) {
                reverse(first, last);
                return false;
            }
        }
    }
};
