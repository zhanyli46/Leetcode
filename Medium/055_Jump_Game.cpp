#include <vector>

using namespace std;

class Solution {
public:
    /* Brute Force */
    /* Time: O(n^2), space: O(n) */
    /* Runtime: TIMEOUT */
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        vector<bool> can_reach(n, false);
        can_reach[n - 1] = true;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; i + j < n && j <= nums[i]; ++j) {
                can_reach[i] = can_reach[i] || can_reach[i + j];
            }
        }
        return can_reach[0];
    }

    /* Linear search */
    /* Time: O(n), space: O(1) */
    /* Runtime: 14ms */
    bool canJump(vector<int>& nums) {
        int reach = 0;  // how far we can reach
        int i = 0;      // current position
        for ( ; i < nums.size() && i <= reach; ++i)
            reach = max(i + nums[i], reach);
        return i == nums.size();
    }
};
