class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // Time: O(n^2) (c++ substr complexity unspecified but generally O(n)), space: O(n)
        // Runtime: 20ms
        string next;
        int len = s.length();
        if (len <= 1) return false;
        for (int i = 1; i <= len / 2; ++i) {
            if (len % i == 0) {
                next = s.substr(i);
                next += s.substr(0, i);
                if (next == s) return true;
            }
        }
        return false;
    }
};
