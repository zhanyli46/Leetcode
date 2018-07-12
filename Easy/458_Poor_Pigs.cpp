#include <cmath>

class Solution {
public:
    // https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // Time: O(logn), space: O(1)
        // Runtime: 0ms
        int n_pigs = 0;
        while (pow(minutesToTest / minutesToDie + 1, n_pigs) < buckets)
            ++n_pigs;
        return n_pigs;
    }
};
