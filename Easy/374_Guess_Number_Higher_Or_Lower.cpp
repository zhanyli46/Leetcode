// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        /* Time: O(log n), space: O(1) */
        /* Runtime: 2ms */
        int lo = 1, hi = n;
        while (true) {
            int mid = lo + (hi - lo) / 2;
            int result = guess(mid);
            if (result == -1) {
                hi = mid - 1;
            } else if (result == 1) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
    }
};
