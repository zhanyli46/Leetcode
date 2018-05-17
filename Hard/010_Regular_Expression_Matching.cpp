class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() || p.empty()) {
            return s == p;
        }
        // M is an 2-D bool array (len(s) * len(p)) that stores matching between
        //  substring of s and substring of p.
        // For example:
        //      M[i][j] -> if s[0..i - 1] matches p[0..j - 1]
        bool M[s.length() + 1][p.length() + 1];
        M[0][0] = true;
        // Set M[i][0] = 0, indicating that empty p cannot match anything
        for (int i = 1; i <= s.length(); ++i)
            M[i][0] = false;
        // Set M[0][j] to true if and only if:
        //      - j > 1 (p of length 1 cannot match empty s),
        //      - current j points to "*", and
        //      - j - 2 matches empty s
        // For example: s = "", p = ".*"
        //                  .   *
        //              0   1   2
        //      ""  0   t   f   t
        for (int j = 1; j <= p.length(); ++j)
            M[0][j] = j > 1 && p[j - 1] == '*' && M[0][j - 2];

        // Start matching
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 1; j <= p.length(); ++j) {
                // if next char in p is any char or '.'
                // then p[j] can match s[i] if p[j - 1] matches s[i - 1] and:
                //      - current char in p matches current char in s, or
                //      - current char in p is '.'
                if (p[j - 1] != '*')
                    M[i][j] = M[i - 1][j - 1] && (s[i - 1] == p[i - 1] || p[j - 1] == '.');
                // if next char is '*'
                // then p[j] can match s[i] if:
                //      - current [a-z.]* expression matches nothing, or
                //      - previous s is matched
                //          - previous char in p matches current char in s, or
                //          - previous char in p is '.'
                else
                    M[i][j] = M[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && M[i - 1][j];
            }
        }
        return M[s.length()][p.length()];
    }
};
