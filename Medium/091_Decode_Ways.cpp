class Solution {
public:
    int numDecodings(string s) {
        // Time: O(n), space: O(n)
        // Runtime: 0ms
        int n = s.length();
        if (n == 0) return 0;
        int M[n + 1] = {0};
        M[0] = 1;
        if (s[0] >= '1' && s[0] <= '9') M[1] = 1;
        for (int i = 2; i <= n; ++i) {
            M[i] += (s[i - 1] >= '1' && s[i - 1] <= '9') ? M[i - 1] : 0;
            M[i] += (validEncoding(s[i - 2], s[i - 1])) ? M[i - 2] : 0;
        }
        return M[n];
    }
private:
    bool validEncoding(char c1, char c2) {
        return (c1 == '1' && (c2 >= '0' && c2 <= '9')) ||
               (c1 == '2' && (c2 >= '0' && c2 <= '6'));
    }
};
