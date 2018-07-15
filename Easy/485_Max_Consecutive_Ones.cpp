#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Time: O(n), space: O(1)
        // Runtime: 24ms
        int max_count = 0, cur_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                ++cur_count;
            } else {
                cur_count = 0;
            }
            max_count = max(max_count, cur_count);
        }
        return max_count;
    }
};
