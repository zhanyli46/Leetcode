#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        /* Time: O(nlogn), space: O(1) */
        /* Runtime: 6ms */
        int m = nums1.size(), n = nums2.size();
        vector<int> intersect;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0, j = 0, k = 0; i < m && j < n; ) {
            if (nums1[i] == nums2[j]) {
                if (k == 0 || intersect[k - 1] != nums1[i]) {
                    intersect.push_back(nums1[i]);
                    ++k;
                }
                ++i, ++j;
            } else if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return intersect;
    }
};
