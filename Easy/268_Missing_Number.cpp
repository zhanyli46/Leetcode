#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 27ms */
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        return total - sum;
    }
};
