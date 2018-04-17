#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /* Time: O(n), space: O(n) */
        /* Runtime: 20ms */
        vector<int> v = nums;
        int i, j, n = nums.size();
        k %= n;
        for (i = 0, j = (n - k) % n; i < n; i++, j = (j + 1) % n)
            nums[i] = v[j];
    }

    void rotate(vector<int>& nums, int k) {
        /* Double reversion */
        /* Time: O(n), space: O(1) */
        /* Runtime: 22ms */
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
