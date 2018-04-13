#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* Greedy Algorithm */
        /* Time: O(n), space: O(1) */
        /* Runtime: 13ms */
        int i, n = nums.size(), cur_sum = nums[0], max_sum = cur_sum;
        for (i = 1; i < n; i++) {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }

    //https://leetcode.com/problems/maximum-subarray/discuss/20360/C++-An-clear-O(n)-divide-and-conquer-solution-with-comments
    int maxSubArray(vector<int>& nums) {
        /* Divide and conquer */
        /* Recurrence: T(n) = 2T(n / 2) + O(1) */
        /* Time: O(n), space: O(1) */
        /* Runtime: 13ms */
        int mx, lmx, rmx, sum;
        maxSubArray(nums, 0, nums.size() - 1, mx, lmx, rmx, sum);
        return mx;
    }

    void maxSubArray(vector<int>& nums, int l, int r, int& mx, int& lmx, int& rmx, int& sum) {
        if (l == r) {
            mx = lmx = rmx = sum = nums[l];
        } else {
            int m = (l + r) / 2;
            int mx1, lmx1, rmx1, sum1;
            int mx2, lmx2, rmx2, sum2;
            maxSubArray(nums, l, m, mx1, lmx1, rmx1, sum1);
            maxSubArray(nums, m + 1, r, mx2, lmx2, rmx2, sum2);
            mx = max(max(mx1, mx2), rmx1 + lmx2);
            lmx = max(lmx1, sum1 + lmx2);
            rmx = max(rmx2, sum2 + rmx1);
            sum = sum1 + sum2;
        }
    }


};
