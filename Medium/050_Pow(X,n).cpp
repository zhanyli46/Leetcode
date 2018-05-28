class Solution {
public:
    /* Brute force */
    /* Time: O(n), space: O(1) */
    /* Runtime: TIMEOUT */
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        int sign = n < 0 ? -1 : 1;
        n = n < 0 ? -n : n;
        double power = 1.0;
        for (int i = 0; i < n; ++i)
            power *= x;
        if (sign == -1)
            power = 1.0 / power;
        return power;
    }

    /* Bit approach */
    /* Time: O(1), space: O(1) */
    /* Runtime: 12ms */
    double myPow(double x, int n) {
        double power = 1.0;
        long abs_n = labs(n);
        while (abs_n > 0) {
            if (abs_n & 0x1)
                power *= x;
            abs_n >>= 1;
            x *= x;
        }
        return n < 0 ? 1.0 / power : power;
    }
};
