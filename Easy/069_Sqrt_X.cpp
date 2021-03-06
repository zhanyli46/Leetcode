using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        /* Brute force */
        /* Time: O(sqrt(n)), space: O(1) */
        /* Runtime: 49ms */
        long i = 0;
        long square;
        while ((square = i * i) <= x) i++;
        return i - 1;
    }

    int mySqrt(int x) {
        /* Binary search */
        /* Time: O(log n), space: O(1) */
        /* Runtime: 37ms */
        long i = 0, j = x / 2 + 1, mid, square;
        while (i <= j) {
            mid = (i + j) / 2;
            square = mid * mid;
            if (square == x) return mid;
            else if (square < x) i = mid + 1;
            else j = mid - 1;
        }
        return j;
    }

    int mySqrt(int x) {
        /* Newton's method */
        /* Time: ?, space: O(1) */
        /* Runtime: 37ms */
        long g = x;
        while (g * g > x) {
            g = (g + x / g) / 2;
        }
        return g;
    }
};
