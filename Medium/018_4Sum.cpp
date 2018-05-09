#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /* Time: O(n^3), space: O(1) */
        /* Runtime: 50ms */
        int n = nums.size();
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int i = 0, j = i + 1, k = j + 1, l = n - 1;
        while (i < n) {
            while (j < n) {
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        v.push_back({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        while (k < l && nums[k - 1] == nums[k]) ++k;
                    } else if (sum < target) {
                        ++k;
                        while (k < l && nums[k - 1] == nums[k]) ++k;
                    } else {
                        --l;
                        while (k < l && nums[l] == nums[l + 1]) --l;
                    }
                }
                ++j;
                while (j < n && nums[j - 1] == nums[j]) ++j;
                k = j + 1;
                l = n - 1;
            }
            ++i;
            while (i < n && nums[i - 1] == nums[i]) ++i;
            j = i + 1;
            k = j + 1;
            l = n - 1;
        }
        return v;
    }
};
