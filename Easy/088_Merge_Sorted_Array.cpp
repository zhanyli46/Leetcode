#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* Two pointers */
        /* Time: O(m + n), space: O(1) in-place */
        /* Runtime: 6ms */
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while (i < 0 && j >= 0) {
            nums1[k--] = nums2[j--];
        }
        while (j < 0 && i >= 0) {
            nums1[k--] = nums1[i--];
        }
    }

    //https://leetcode.com/problems/merge-sorted-array/discuss/29515/4ms-C++-solution-with-single-loop
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* Two pointers */
        /*  Observation: after exhausting nums2, the elements of nums1 are in order. */
        /* Time: O(m + n), space: O(1) in-place */
        /* Runtime: 6ms */
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            nums1[k--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* Copy and sort */
        /* Time: O((m+n)log(m+n)), space: O(1) in-place */
        /* Runtime: 6ms */
        copy(nums2.begin(), nums2.end(), nums1.begin() + m);
        sort(nums1.begin(), nums1.end());
    }
};
