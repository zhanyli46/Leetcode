#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Time: O(n), space: O(1) in-place
        // Runtime: 8ms
        if (nums.size() <= 2) return nums.size();
        int count = 1;
        int head = 1;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == prev) {
                if (count < 2) {
                    nums[head++] = nums[i];
                    ++count;
                }
            } else {
                count = 1;
                nums[head++] = nums[i];
                prev = nums[i];
            }
        }
        return head;
    }
};
