#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /* Time: O(log_2(n)), space: O(1) */
        /* Runtime: 10ms */
        int offset = 0, n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                offset = i + 1;
                break;
            }
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[(mid + offset) % n] == target)
                return (mid + offset) % n;
            else if (nums[(mid + offset) % n] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
