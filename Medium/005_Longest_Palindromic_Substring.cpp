#include <string>

class Solution {
public:
    string longestPalindrome(string s) {
        /* Dynamic Programming */
        /* Time O(n^2), space O(n^2) */
        /* Runtime: 120ms */
        int i, j, n = s.length();
        bool M[n][n] = {{false}};
        string palin;
        for (i = n - 1; i >= 0; i--) {
            for (j = i; j < n; j++) {
                if (i == j) M[i][j] = true;
                else if (i + 1 == j && s[i] == s[j]) M[i][j] = true;
                else M[i][j] = s[i] == s[j] && M[i + 1][j - 1];
                if (M[i][j] && (palin.length() < j - i + 1))
                    palin = s.substr(i, j - i + 1);
            }
        }
        return palin;
    }

    string longestPalindrome(string s) {
        /* String expansion */
        /* Time O(n^2) (empirically less than DP approach), space O(1) */
        /* Runtime: 22ms */
        int i, n = s.length();
        if (n < 2) return s;
        for (i = 0; i < n - 1; i++) {
            expandPalindrome(s, i, i);
            expandPalindrome(s, i, i + 1);
        }
        return s.substr(low, max_len);
    }

    // https://leetcode.com/problems/longest-palindromic-substring/discuss/2929/Accepted-4ms-c++-solution.
    string longestPalindrome(string s) {
        /* String expansion without repetition */
        /* Time O(n), space O(1) */
        /* Runtime: 7ms */
        int i = 0, left, right, n = s.length();
        int max_left = 0, max_len = 1;
        if (n < 2) return s;
        while (i < n && n - i > max_len / 2) {
            left = right = i;
            while (right < len - 1 && s[right] == s[right + 1])
                ++right;
            i = right + 1;
            while (right < len - 1 && left > 0 && s[left - 1] == s[right + 1]) {
                --left;
                ++right;
            }
            if (right - left + 1 > max_len) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }

private:
    int start, max_len;
    void expandPalindrome(string s, int i, int j) {
        int n = s.length();
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--, j++;
        }
        if (j - i - 1 > max_len) {
            start = i + 1;
            max_len = j - i - 1;
        }
    }
};
