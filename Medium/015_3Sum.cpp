#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /* Time: O(n^2), space: O(1) */
        /* Runtime: 114ms */
        int i = 0, j, k, n = nums.size();
        vector<vector<int>> sum_set;
        sort(nums.begin(), nums.end());
        while (i < n - 2 && nums[i] <= 0) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    sum_set.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while (j < k && nums[j - 1] == nums[j]) ++j;
                    --k;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                } else {
                    ++j;
                    while (j < k && nums[j - 1] == nums[j]) ++j;
                }
            }
            ++i;
            while (i < n - 2 && nums[i - 1] == nums[i]) ++i;
        }
        return sum_set;
    }
};
