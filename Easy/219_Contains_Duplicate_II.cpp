#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /* Brute force */
        /* Time:O(n^2), space: O(1) */
        /* Runtime: TIMEOUT */
        int i, j, n = nums.size();
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && j - i <= k)
                    return true;
            }
        }
        return false;
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /* Hashmap */
        /* Time:O(n), space: O(n) */
        /* Runtime: 26ms */
        unordered_map<int, int> m;
        int i, n = nums.size();
        for (i = 0; i < n; i++) {
            if (m.find(nums[i]) == m.end()) {
                m.insert({nums[i], i});
            } else {
                if (i - m[nums[i]] <= k)
                    return true;
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
