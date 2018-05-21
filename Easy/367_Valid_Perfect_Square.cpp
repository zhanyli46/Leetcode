class Solution {
public:
    bool isPerfectSquare(int num) {
        /* Time: O(?), space: O(1) */
        /* Runtime: 0ms */
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
