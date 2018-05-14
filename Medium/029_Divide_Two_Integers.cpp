class Solution {
public:
    int divide(int dividend, int divisor) {
        /* Time: O(?), space: O(1) */
        /* Runtime: 25ms */
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long long_dividend = labs(dividend);
        long long long_divisor = labs(divisor);
        int quotient = 0;
        while (long_dividend >= long_divisor) {
            long long temp = long_divisor;
            int multiple = 1;
            while (long_dividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            long_dividend -= temp;
            quotient += multiple;
        }
        return sign == 1 ? quotient : -quotient;
    }
};
