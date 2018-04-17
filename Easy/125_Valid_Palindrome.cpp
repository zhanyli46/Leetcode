using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        /* Time: O(n), space: O(1) */
        /* Runtime: 10ms */
        int i, j, k = 0, n = s.length();
        for (i = 0; i < n; i++) {
            if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9'))
                s[k++] = s[i];
            else if ('A' <= s[i] && s[i] <= 'Z')
                s[k++] = s[i] - 'A' + 'a';
        }
        for (i = 0, j = k - 1; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};
