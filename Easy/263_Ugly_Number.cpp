class Solution {
public:
    bool isUgly(int num) {
        /* Time: O(n)?, space: O(1) */
        /* Runtime: 6ms */
        if (num <= 0) return false;
        while (num != 1) {
            if (num % 5 == 0)
                num /= 5;
            else if (num % 3 == 0)
                num /= 3;
            else if (num % 2 == 0)
                num /= 2;
            else
                return false;
        }
        return true;
    }
};
