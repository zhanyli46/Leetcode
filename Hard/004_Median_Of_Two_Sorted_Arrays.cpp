#include <vector>
#include <algorithm>    // min
#include <climits>      // INT_MAX

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* Reduce to find K-th element */
        /* Time O(log(k)), space O(1) */
        /* Runtime: 66ms */
        int n = nums1.size() + nums2.size();
        if (n % 2 == 1) {
            return findKth(nums1, nums2, 0, 0, n / 2 + 1);
        } else {
            return (findKth(nums1, nums2, 0, 0, n / 2) + findKth(nums1, nums2, 0, 0, n / 2 + 1)) / 2.0;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* Merge */
        /* m: size of nums1, n: size of nums2 */
        /* Time O(m + n), space O(m + n) */
        /* Runtime: 66ms */
        int n = nums1.size() + nums2.size();
        vector<int> v;
        vector<int>::const_iterator p1 = nums1.begin(), p2 = nums2.begin();
        while (p1 != nums1.end() || p2 != nums2.end()) {
            if (p1 == nums1.end()) {
                v.insert(v.end(), p2, nums2.end());
                break;
            }
            if (p2 == nums2.end()) {
                v.insert(v.end(), p1, nums1.end());
                break;
            }
            if (*p1 < *p2) {
                v.push_back(*p1++);
            } else {
                v.push_back(*p2++);
            }
        }
        if (n % 2 == 1) {
            return v[n / 2];
        } else {
            return (v[n / 2] + v[n / 2 - 1]) / 2.0;
        }
    }

private:
    int findKth(vector<int>& A, vector<int>& B, int startA, int startB, int k) {
        if (startA >= A.size()) {
            return B[startB + k - 1];
        }
        if (startB >= B.size()) {
            return A[startA + k - 1];
        }
        if (k == 1) {
            return min(A[startA], B[startB]);
        }

        int midA = (startA + k / 2 - 1) < A.size() ? A[startA + k / 2 - 1] : INT_MAX;
        int midB = (startB + k / 2 - 1) < B.size() ? B[startB + k / 2 - 1] : INT_MAX;
        if (midA < midB) {
            return findKth(A, B, startA + k / 2, startB, k - k / 2);
        } else {
            return findKth(A, B, startA, startB + k / 2, k - k / 2);
        }
    }
};
