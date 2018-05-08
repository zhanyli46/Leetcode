class Solution {
public:
    bool isPowerOfTwo(int n) {
        /* Time: O(log_2 n), but way slower than method below */
        /* Runtime: TIMEOUT */
        int num = 1;
        while (num <= n) {
            if (num == n) return true;
            num *= 2;
        }
        return false;
    }

    bool isPowerOfTwo(int n) {
        /* Time: O(log_2 n) */
        /* Runtime: 6ms */
        if (n == 0) return false;
        if (n == 1) return true;
        return n % 2 == 0 && isPowerOfTwo(n / 2);
    }
};
