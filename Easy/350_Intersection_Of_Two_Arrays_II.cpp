#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /* Sort + Two pointers */
        /* Time: O(nlogn), space: O(1) */
        /* Runtime: 8ms */
        int m = nums1.size(), n = nums2.size();
        vector<int> intersect;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0, j = 0; i < m && j < n; ) {
            if (nums1[i] == nums2[j]) {
                intersect.push_back(nums1[i]);
                ++i, ++j;
            } else if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return intersect;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /* Hashmap */
        /* Time: O(m + n), space: O(m) */
        /* Runtime: 10ms */
        unordered_map<int, int> dict;
        vector<int> intersect;
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < m; ++i)
            ++dict[nums1[i]];
        for (int j = 0; j < n; ++j) {
            if (dict.find(nums2[j]) != dict.end() && --dict[nums2[j]] >= 0)
                intersect.push_back(nums2[j]);
        }
        return intersect;
    }
};
