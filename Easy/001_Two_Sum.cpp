#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum_1(vector<int>& nums, int target) {
        /* Brute force: Time O(n^2), space O(1) */
        /* Runtime: 162ms */
        int i, j, n = nums.size();
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
    }

    vector<int> twoSum_2(vector<int>& nums, int target) {
        /* Hash map: Time O(n), Space O(n) */
        /* Runtime: 9ms */
        int i, n = nums.size(), num_to_find;
        unordered_map<int, int> m;
        for (i = 0; i < n; i++) {
            num_to_find = target - nums[i];
            if (m.find(num_to_find) != m.end())
                return {m[num_to_find], i};
            else
                m[nums[i]] = i;
        }
        return vector<int>();
    }
}
