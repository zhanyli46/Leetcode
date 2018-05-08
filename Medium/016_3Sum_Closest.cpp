#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /* Time: O(n^2), space: O(1) */
        /* Runtime: 10ms */
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1, k = n - 1; j < k; ) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(closest_sum - target)) {
                    closest_sum = sum;
                }
                if (sum < target) ++j;
                else if (sum > target) --k;
                else return sum;
            }
        }
        return closest_sum;
    }
};
