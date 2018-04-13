#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 31ms */
        int i = 1, j = 1, n = nums.size(), cur_num;
        if (n <= 1) return n;
        cur_num = nums[0];
        while (j < n) {
            while (j < n && nums[j] == cur_num)
                j++;
            if (j == n) break;
            nums[i++] = nums[j];
            cur_num = nums[j++];
        }
        return i;
    }
};
