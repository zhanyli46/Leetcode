#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Time: O(log n) avg case, O(n) worst case, space: O(1)
        // Runtime: 4ms
        if (nums.empty()) return false;
        int l = 0, r = nums.size() - 1, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if ((nums[l] == nums[m]) && (nums[m] == nums[r])) {
                ++left; --right;
            } else if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return false;
    }
};
