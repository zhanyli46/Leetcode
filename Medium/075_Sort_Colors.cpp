#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 0ms */
        if (nums.empty()) return;
        int head = 0, tail = nums.size() - 1;
        for (int i = 0; i <= tail; ) {
            if (nums[i] == 0)
                swap(nums[head++], nums[i++]);
            else if (nums[i] == 2)
                swap(nums[tail--], nums[i]);
            else
                ++i;
        }
    }
};
