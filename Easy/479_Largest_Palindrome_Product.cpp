#include <cmath>        // pow
#include <string>       // to_string
#include <algorithm>    // reverse

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        // Time: O(10^n * sqrt(n))?, space: O(1)
        // Runtime: 268ms
        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);
        for (int i = upper; i >= lower; --i) {
            long palin = buildPalindrome(i);
            for (long j = upper; j * j >= palin; --j) {
                if (palin % j == 0 && palin / j <= upper)
                    return palin % 1337;
            }
        }
        return -1;
    }
private:
    long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stol(to_string(n) + s);
    }
};
