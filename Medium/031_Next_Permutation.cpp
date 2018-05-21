#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // C++ <algorithm> library implementation "next_permutation"
    // https://llvm.org/svn/llvm-project/libcxx/trunk/include/algorithm
    void nextPermutation(vector<int>& nums) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 18ms */
        vector<int>::iterator first = nums.begin(), last = nums.end();
        vector<int>::iterator i = last;
        if (first == last || first == --i) return;
        // 1) Find the first (i, ip1) pair where i < ip1, starting from the back
        // 2) Find the first j where i >= j, j starting from the back
        // 3) Swap i and j
        // 4) Reverse the subarray (ip1, end)
        while (true) {
            vector<int>::iterator ip1 = i;
            // i points to last element where *i < *(i + 1)
            // ip1 points to i + 1.
            if (*--i < *ip1) {
                vector<int>::iterator j = last;
                // j points to the last element that is greater than i.
                while (*i >= *--j)
                    ;
                swap(*i, *j);
                reverse(ip1, last);
                break;
            }
            if (i == first) {
                reverse(first, last);
                break;
            }
        }
    }
};
