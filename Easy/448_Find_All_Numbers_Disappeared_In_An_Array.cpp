#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Time: O(n), space: O(1)
        // Runtime: 84ms
        vector<int> disappeared;
        for (int i = 0; i < nums.size(); ++i) {
            int val = abs(nums[i]) - 1;
            nums[val] = nums[val] > 0 ? -nums[val] : nums[val];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                disappeared.push_back(i + 1);
        }
        // Restore nums
        // for (int i = 0; i < nums.size(); ++i)
        //     nums[i] = abs(nums[i]);
        return disappeared;
    }
};
