#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /* Time: O(log_2(n)), space: O(1) */
        /* Runtime: 12ms */
        if (nums.empty()) return {-1, -1};
        return search(nums, target, 0, nums.size() - 1);
    }

private:
    vector<int> search(vector<int>& nums, int target, int lo, int hi) {
        if (nums[lo] == target && target == nums[hi])
            return {lo, hi};
        if (nums[lo] <= target && target <= nums[hi]) {
            int mid = lo + (hi - lo) / 2;
            vector<int> l, r;
            l = search(nums, target, lo, mid);
            r = search(nums, target, mid + 1, hi);
            if (l[0] == -1 || r[0] == -1)
                return max(l, r);
            else
                return {l[0], r[1]};
        }
        return {-1, -1};
    }
};
