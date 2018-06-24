#include <math.h>
#include <string>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // Time: O(log n), space: O(log n)
        // Runtime: 3ms
        int len = 1, start = 1;
        long count = 9;
        while (n > len * count) {
            n -= len * count;
            len += 1;
            start *= 10;
            count *= 10;
        }
        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n - 1) % len] - '0';
    }

    // https://leetcode.com/problems/nth-digit/discuss/88369/0ms-C++-Solution-with-Detail-Explanation
    int findNthDigit(int n) {
        // Time: O(log n), space: O(1)
        // Runtime: 4ms
        long base = 9, digits = 1;
        // 1. find out how many digits the number has
        //  e.g. n = 250
        //  after while: n = 250 - 9 - 180 = 61
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            ++digits;
        }
        // 2. calculate the number
        int index = n % digits;
        if (index == 0) index = digits;
        long num = pow(10, digits - 1);
        num += (index == digits) ? n / digits - 1 : n / digits;
        // 3. find the digit
        for (int i = index; i < digits; ++i) {
            num /= 10;
        }
        return num %= 10;
    }
};
