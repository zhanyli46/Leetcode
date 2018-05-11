#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 29ms */
        int n = nums.size();
        int front = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0)
                nums[front++] = nums[i];
        }
        while (front < n) {
            nums[front++] = 0;
        }
    }
};
