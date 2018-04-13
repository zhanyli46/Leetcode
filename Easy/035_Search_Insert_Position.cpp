#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 7ms */
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] < target)
                i++;
            else
                return i;
        }
        return i;
    }
};
