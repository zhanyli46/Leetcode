class Solution {
public:
    /* Recursive */
    bool isPowerOfThree(int n) {
        /* Time: O(log_3(n)), space: O(1) */
        /* Runtime: 62ms */
        if (n <= 0) return false;
        if (n == 1) return true;
        return (n % 3 == 0 && isPowerOfThree(n / 3));
    }

    /* Maximum power-of-3 (prime only) */
    bool isPowerOfThree(int n) {
        /* Time: O(1), space: O(1) */
        /* Runtime: 62ms */
        return n > 0 && (1162261467 % n == 0);
    }
};
