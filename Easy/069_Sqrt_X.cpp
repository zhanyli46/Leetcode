using namespace std;

class Solution {
public:
    int mySqrt_1(int x) {
        /* Brute force */
        /* Time: O(n), space: O(1) */
        /* Runtime: 49ms */
        long i = 0;
        long square;
        while ((square = i * i) <= x) i++;
        return i - 1;
    }

    int mySqrt_2(int x) {
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
};
