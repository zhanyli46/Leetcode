#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        // Time: O(n), space: O(1)
        // Runtime: 4ms
        sort(s.begin(), s.end());
        int p = 0;
        int len = 0;
        int pivot = 0;
        while (p < s.length()) {
            if (p + 1 < s.length() && s[p] == s[p + 1]) {
                len += 2;
                p += 2;
            } else {
                pivot = 1;
                ++p;
            }
        }
        return len + pivot;
    }
};
