#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* Time: O(n), space: O(n) */
        /* Runtime: 24ms */
        unordered_map<int, int> m;
        int major_elem = 0, majority = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end())
                m[nums[i]] += 1;
            else
                m.insert({nums[i], 1});
        }
        for (auto p : m) {
            if (p.second > majority) {
                major_elem = p.first;
                majority = p.second;
            }
        }
        return major_elem;
    }

    int majorityElement(vector<int>& nums) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 19ms */
        int candidate = nums[0], count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
        	if (count == 0) {
        		candidate = nums[i];
        		count++;
        	} else if (nums[i] == candidate) {
        		count++;
        	} else {
        		count--;
        	}
        }
        return candidate;
    }
};
