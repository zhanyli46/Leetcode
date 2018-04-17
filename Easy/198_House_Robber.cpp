#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /* DP */
        /* Time: O(n), space: O(1) */
        /* Runtime: 1ms */
        int rob_this = 0, not_rob_this = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int temp = rob_this;
            rob_this = not_rob_this + nums[i];
            not_rob_this = max(not_rob_this, temp);
        }
        return max(rob_this, not_rob_this);
    }
};
