#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /* Time:O(n) avg, space: O(n) */
        /* Runtime: 40ms */
        unordered_set<int> s;
        int i, n = nums.size();
        for (i = 0; i < n; i++) {
            if (s.count(nums[i])) return true;
            else s.insert(nums[i]);
        }
        return false;
    }
};
