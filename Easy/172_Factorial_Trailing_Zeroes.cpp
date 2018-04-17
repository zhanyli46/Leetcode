using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        /* Time: O(log_5(n)), space: O(1) */
        /* Runtime: 3ms */
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
