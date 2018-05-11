class Solution {
public:
    bool canWinNim(int n) {
        /* Time: O(1), space: O(1) */
        /* Runtime: 2ms */
        if (n <= 0) return false;
        return n % 4 != 0;
    }
};
