#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 16ms */
        int single = 0;
        for (int n : nums)
            single ^= n;
        return single;
    }
};
