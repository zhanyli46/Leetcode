class Solution {
public:
    /* Iterative */
    bool isPowerOfFour(int num) {
        /* Time: O(log_4(n)), space: O(1) */
        /* Runtime: 6ms */
        if (num < 0) return false;
        while (num != 1) {
            if (num == 0 || ((num & 0x3) != 0)) return false;
            num >>= 2;
        }
        return true;
    }

    /* Bit manipulation */
    /* All n that are power of four has the following format: */
    /*      0x(0 * x)1(0 * y), y % 2 == 0 */
    bool isPowerOfFour(int num) {
        /* Time: O(1), space: O(1) */
        /* Runtime: 3ms */
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
    }
};
