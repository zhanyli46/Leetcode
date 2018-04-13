#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 6ms */
        int i = 0, j = 0, n = nums.size();
        while (j < n) {
            if (nums[j] != val)
                nums[i++] = nums[j];
            j++;
        }
        return i;
    }
};
